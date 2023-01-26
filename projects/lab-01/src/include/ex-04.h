#ifndef _EX_04_H
#define _EX_04_H

#include "util/arduino-program.h"

#ifndef BUZZER_PIN
#define BUZZER_PIN A7
#endif

namespace Ex_04
{
  /**
   * Beep the buzzer and play around with values
   */
  class Part_01 : public ArduinoProgram
  {
  public:
    void setup() override;
    virtual void beep();
    void loop() override;
  };

  void Part_01::setup()
  {
    // Turn it off! Please!
    digitalWrite(BUZZER_PIN, LOW);

    // Reinitialise the buzzer
    pinMode(BUZZER_PIN, OUTPUT);

    // just wait a bit
    delay(1000);
  }

  void Part_01::beep()
  {
    // Beep for 2.5ms (400 Hz)
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(0.5 * 2.5 * 1000);
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(0.5 * 2.5 * 1000);
  }

  void Part_01::loop()
  {
    beep();
  }

  /**
   * Beep the buzzer using `delayMicroseconds`
   */
  class Part_02 : public Part_01
  {
  public:
    void beep() override;
    void beep(double freq_Hz = 400);
  };

  void Part_02::beep()
  {
    beep(400);
  }

  // Takes 10us to beep (kHz)
  void Part_02::beep(double freq_Hz)
  {
    double ms = (1 / freq_Hz) * 1000;
    double us = ms * 1000;

    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(0.5 * us);

    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(0.5 * us);
  };

  // Beep the buzzer with a fixed on/off time
  class Part_03 : public Part_02
  {
  public:
    // Beep for `ms` milliseconds
    void beep(int ms = 1000, double freq_Hz = 400);
    void loop() override;
  };

  void Part_03::beep(int how_long_ms, double freq_Hz)
  {
    int elapsed = 0;

    while (how_long_ms > elapsed)
    {
      ((Part_02 *)this)->beep(freq_Hz);
      elapsed += 10;
    }

    delay(how_long_ms);
  }

  void Part_03::loop()
  {
    beep(1000);
  }

  // Use a global variable to gradually increase the beep time

#define TWELTFH_ROOT_OF_2 1.0594630943592952645618252949463

  // Global beep time in ms
  static int beepTime = 2000;
  static int beepFreq = 200;

  class Part_04 : public Part_03
  {
  public:
    void loop() override;
  };

  void Part_04::loop()
  {
    beep(beepTime, beepFreq);

    beepTime /= TWELTFH_ROOT_OF_2;
    beepFreq *= TWELTFH_ROOT_OF_2;

    if (beepTime < 10)
    {
      beepTime = 1000;
      beepFreq = 200;
    }
  }

}; // namespace Ex_04

#endif