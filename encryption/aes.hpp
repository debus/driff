#ifndef H_DEBUS_AES_SUBED_H
#define H_DEBUS_AES_SUBED_H
#include "rijndael.hpp"

namespace debus{namespace encryption{

class AES{
  
  void KeyExpansion(){};
  void AddRoundKey(){};
  void SubBytes(){};
  void ShiftRows(){};
  void MixColumns(){};

};



}}

#endif
