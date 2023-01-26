#ifndef _ARDUINO_PROGRAM_H
#define _ARDUINO_PROGRAM_H

class ArduinoProgram
{
public:
  void virtual loop() {
    Serial.println("ArduinoProgram::loop() called");
  }
  void virtual setup() {
    Serial.println("ArduinoProgram::setup() called");
  }

  virtual ~ArduinoProgram() {}
};

#endif