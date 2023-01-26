#ifndef _EX_03_H
#define _EX_03_H

#include "util/arduino-program.h"

namespace Ex_03
{
  // Flash the led at 5Hz 10 times
  class Part_01 : public ArduinoProgram
  {
    uint8_t times = 0;
    const uint8_t MAX_TIMES = 10;

  public:
    void setup() override;
    void loop() override;
  };

  void Part_01::setup()
  {
    pinMode(LED_BUILTIN, OUTPUT);
  };

  void Part_01::loop()
  {
    if (times < MAX_TIMES)
    {
      // Total flash time = 400ms (= 5Hz)

      // Time on = 100ms
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);

      // Time off = 100ms
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);

      times++;
    }
  }
}; // namespace Ex_03

#endif
