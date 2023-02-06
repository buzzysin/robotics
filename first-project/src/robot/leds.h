#ifndef _LEDS_H_
#define _LEDS_H_

#include <Arduino.h>

#include "../util/setupable.h"
#include "../util/loopable.h"

#include "led.h"

namespace Pins
{
  static const byte LED_L_PIN = LED_BUILTIN_RX; // 17;
  static const byte LED_C_PIN = LED_BUILTIN;    // 13;
  static const byte LED_R_PIN = LED_BUILTIN_TX; // 30;
} // namespace Pins

class Leds : public HasSetup
{
protected:
  // Static properties
  static const uint8_t COUNT = 3;

  //  Properties
protected:
  Led l;
  Led c;
  Led r;
  Led leds[COUNT] = {l, c, r};

  // Public methods
public:
  // Constructor
  Leds();

  // Set up the leds
  void setup() override;

}; // class Leds

#endif
