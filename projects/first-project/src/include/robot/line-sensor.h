#ifndef _LINE_SENSOR_H_
#define _LINE_SENSOR_H_

#include "../util/setupable.h"

class LineSensor : public Setupable
{
private:
  byte pin;

public:
  LineSensor(byte pin)
  {
    this->pin = pin;
  }

  void setup() override
  {
    pinMode(pin, INPUT);
  }

  void enableWrite()
  {
    pinMode(pin, OUTPUT);
  }

  void enableRead()
  {
    pinMode(pin, INPUT);
  }

  bool isActive() const
  {
    return digitalRead(pin) == HIGH;
  }

  void setActive()
  {
    digitalWrite(pin, HIGH);
  }
};

#endif