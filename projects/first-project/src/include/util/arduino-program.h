#ifndef _ARDUINO_PROGRAM_H
#define _ARDUINO_PROGRAM_H

#include "loopable.h"
#include "setupable.h"

class ArduinoProgram : public Setupable, public Loopable
{
private:
  bool onFirstLoop = false;

public:
  void loop() override
  {
    if (!onFirstLoop)
    {
      Serial.println("ArduinoProgram::loop() called");
      onFirstLoop = true;
    }
  }

  void setup() override
  {
    Serial.println("ArduinoProgram::setup() called");
  }
};

#endif