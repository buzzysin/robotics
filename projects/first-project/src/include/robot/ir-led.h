#ifndef _IR_LED_H_
#define _IR_LED_H_

#define IR_LED_PIN 11

#include "../util/setupable.h"

class IrLed : public Setupable
{
public:
  static int STATE;

public:
  IrLed()
  {
  }

  void setup()
  {
    pinMode(IR_LED_PIN, OUTPUT);
  }

  void on()
  {
    digitalWrite(IR_LED_PIN, HIGH);
    STATE = HIGH;
  }

  void off()
  {
    digitalWrite(IR_LED_PIN, LOW);
    STATE = LOW;
  }

  int getState() const
  {
    return STATE;
  }
};

int IrLed::STATE = HIGH;

#endif