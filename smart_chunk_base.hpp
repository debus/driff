/*
 * dsmart_chunks.hpp
 *
 *  Created on: Dec 11, 2013
 *      Author: phil
 */

#ifndef DSMART_CHUNKS_HPP_
#define DSMART_CHUNKS_HPP_

#include "chunk_header.hpp"
#include <map>
#include <vector>
#include <string>
#include "serializable.hpp"
namespace debus{namespace riff{

#define D_CHUNK_LOOP(it,vec) for(chunk_iterator it = vec.begin(); it != vec.end(); ++it)
#define D_CCHUNK_LOOP(it,vec) for(const_chunk_iterator it = vec.begin(); it != vec.end(); ++it)
class smart_chunk_t;

typedef smart_chunk_t* (*chunk_producer_function)(chunk_header_t::id_type, unsigned int size);

typedef std::map<chunk_header_t::id_type,chunk_producer_function> chunk_type_map;

template<typename K, typename V>
std::map<K,V> __mergeChunkTypeMap(const std::map<K,V>& base, const std::map<K,V>& diff){
	std::map<K,V> merged = base;
	for(typename std::map<K,V>::const_iterator it = diff.begin(); it != diff.end(); ++it){
		merged[it->first] = it->second;
	}
	return merged;
}

smart_chunk_t* __getChunkTypeInstance(chunk_header_t::id_type id, unsigned int size, const chunk_type_map& map);

class smart_chunk_t : public chunk_header_t{
public:
	smart_chunk_t(){
		this->ckID = -1;
	};

	smart_chunk_t(id_type id, unsigned int size){
		this->ckID = id;
	};

	virtual ~smart_chunk_t(){
		removeSubChunks();
	};

	static smart_chunk_t* readChunk(std::istream& is, const chunk_type_map& map){
		using namespace serialization;
		id_type id;
		unsigned int size = 0;
		is >= id;
		is >= size;
		return __getChunkTypeInstance(id,size,map);
	};

protected:
	typedef std::vector<smart_chunk_t*>::iterator chunk_iterator;
	typedef std::vector<smart_chunk_t*>::const_iterator const_chunk_iterator;
public:
	std::vector<smart_chunk_t*> sub_chunks;

	void removeSubChunks(){
		D_CHUNK_LOOP(it,sub_chunks){
			delete *it;
		}
	};
	std::string idToString(){
		char cstr[5];
		*((unsigned int*)cstr) = this->ckID;
		cstr[4] = '\0';
		return std::string(cstr);
	};
	smart_chunk_t* getFirstChunkByID(id_type id) const {
		D_CCHUNK_LOOP(it,sub_chunks){
			if((*it)->ckID == id){
				return *it;
			}
		}
		return NULL;
	};

	std::vector<smart_chunk_t*> getChunksByID(id_type id) const {
		std::vector<smart_chunk_t*> ret;
		D_CCHUNK_LOOP(it,sub_chunks){
			if((*it)->ckID == id){
				ret.push_back(*it);
			}
		}
		return ret;
	};

	virtual unsigned int getChunkSize() const {
		unsigned int size = 0;
		D_CCHUNK_LOOP(it,sub_chunks){
			size += (*it)->getChunkSize()+chunk_header_t::written_size;
		}
		return size;
	};

};

class unknown_chunk_t : public smart_chunk_t{
public:
  unsigned int ckSize;
	char* data;
	unknown_chunk_t(id_type id, unsigned int size) : smart_chunk_t(id,size){
    ckSize = size;
		if(size != 0){
			data = new char[size];
		} else {
			data = NULL;
		}
	}

	virtual ~unknown_chunk_t(){
    this->removeSubChunks();
		if(data != NULL){
			delete[] data;
			data = NULL;
		}
	}

  virtual unsigned int getChunkSize(){
    return this->ckSize;
  }

	static smart_chunk_t* create(id_type id, unsigned int size){
		return new unknown_chunk_t(id,size);
	}
};










smart_chunk_t* __getChunkTypeInstance(chunk_header_t::id_type id, unsigned int size, const chunk_type_map& map){
	chunk_type_map::const_iterator it = map.find(id);
	if(it != map.end()){
		return it->second(id,size);
	} else {
		return unknown_chunk_t::create(id,size);
	}
}



}};

#endif /* DSMART_CHUNKS_HPP_ */
