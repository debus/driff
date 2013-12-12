#include <fstream>
#include "smart_chunk_base.hpp"
#include <iostream>

using namespace std;
using namespace debus::riff;
int main(){
  ifstream file("file.wav", ios_base::binary);
  chunk_type_map map;
  smart_chunk_t* chunk = smart_chunk_t::readChunk(file,map);

  cout<<"ckID: "<<chunk->ckID<<" '"<<chunk->idToString()<<"'"<<endl;
  cout<<"ckSize: "<<chunk->ckSize<<" ("<<chunk->getChunkSize()<<")"<<endl;
  return 0;
}
