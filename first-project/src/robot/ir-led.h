#ifndef _IR_LED_H_
#define _IR_LED_H_

#include <Arduino.h>

#include "led.h"

namespace Pins
{
  static const byte IR_LED_PIN = 11;
} // namespace Pins

class IrLed : public Led
{
  // Public methods
public:
  // Constructor
  IrLed(byte pin);
}; // class IrLed

#endif