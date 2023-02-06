#ifndef _ARDUINO_PROGRAM_H_
#define _ARDUINO_PROGRAM_H_

#include <Arduino.h>

#include "loopable.h"
#include "setupable.h"

class ArduinoProgram : public HasSetup, public HasLoop
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