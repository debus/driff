#ifndef DEBUS_H_RIFF_CHUNK_BASE_FFIR_H_SUBED
#define DEBUS_H_RIFF_CHUNK_BASE_FFIR_H_SUBED
#include <string>
namespace debus{namespace riff{

typedef unsigned int id_t;

static std::string chunkIDToString(id_t id){
  char tmp[5];
  *(unsigned int* tmp) = id;
  tmp[4] = '\0';
  return std::string(tmp);
}

static id_t stringToChunkID(const std::string& str){
  return *(const id_t*)str.c_str();
}

static id_t stringToChunkID(const char* str){
  return *(const id_t*)str;
}

class chunk_base_t{
public:
  id_t ckID; /// The id of the chunk.

  /**
   * Returns the size in bytes of the chunk minus any header info and padding.
   */
  virtual std::size_t getSize() const = 0;

  /**
   * Returns a bool indicating whether this chunk supports children or not.
   * This lets you know if you can safely cast this to a chunk_parent_t or not.
   */
  virtual bool supportsChildren() const = 0;

 };

#endif
