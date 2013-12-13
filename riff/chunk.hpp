#include "chunk_base.hpp"
#include <vector>
#ifndef DEBUS_H_CHUNK_H_SUBED
#define DEBUS_H_CHUNK_H_SUBED

namespace debus{namespace riff{

class chunk_parent_t : public chunk_base_t{
protected:
  chunk_list children;
public:
  typedef std::vector<chunk_base_t*> chunk_list;
  
  virtual chunk_base_t* getFirstChildByID(id_t id) const {
    for(chunk_list::const_iterator it = children.begin(); it != children.end(); ++it){
      if((*it)->ckID == id){
        return *it;
      }
    }
    return NULL;
  };

  virtual chunk_base_t* addChild(chunk_base_t* chunk){
    if(chunk == NULL){ return NULL; }
    children.push_back(chunk);
    return chunk;
  };

  virtual chunk_base_t* insertChild(chunk_base_t* chunk, unsigned int pos){
    if(chunk == NULL || pos > children.size()){ return NULL; }
    
  }
};

}};

#endif
