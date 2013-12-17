#ifndef H_DEBUS_ENCRYPTION_SUBED_H
#define H_DEBUS_ENCRYPTION_SUBED_H

namespace debus{namespace encryption{

class AES{
  
  void KeyExpansion(){};
  void AddRoundKey(){};
  void SubBytes(){};
  void ShiftRows(){};
  void MixColumns(){};

};

}};

#endif
