#ifndef _EX_02_H
#define _EX_02_H

#include "util/arduino-program.h"

namespace Ex_02
{
  // Flash the led at 5Hz
  class Part_04 : public ArduinoProgram
  {
  public:
    void setup() override;
    void loop() override;
  };

  void Part_04::setup()
  {
    pinMode(LED_BUILTIN, OUTPUT);
  }

  void Part_04::loop()
  {
    // Total flash time = 400ms (= 5Hz)

    // Time on = 100ms
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);

    // Time off = 100ms
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}; // namespace Ex_02

#endif