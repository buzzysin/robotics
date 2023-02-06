#ifndef _NV_MEMORY_H_
#define _NV_MEMORY_H_

#include <EEPROM.h>

class NVMemory
{
  // Properties
private:
  int address;

  // Methods
public:
  NVMemory(int address)
  {
    this->address = address;
  }

};

#endif