#ifndef _LED_H_
#define _LED_H_

#include <Arduino.h>

#include "../util/setupable.h"

class Led : public HasSetup
{
  // Properties
protected:
  byte pin;
  byte STATE = LOW;

  // Public methods
public:
  // Constructor
  Led(byte pin);

  // Set up the led
  void setup() override;

  // Turn the led on
  virtual void on();

  // Turn the led off
  virtual void off();

  // Toggle the led
  virtual void toggle();
}; // class Led

#endif