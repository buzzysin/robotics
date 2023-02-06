#include "led.h"

Led::Led(byte pin) : pin(pin)
{
}

void Led::setup()
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, STATE);
}

void Led::on()
{
  STATE = HIGH;
  digitalWrite(pin, STATE);
}

void Led::off()
{
  STATE = LOW;
  digitalWrite(pin, STATE);
}

void Led::toggle()
{
  STATE = !STATE;
  digitalWrite(pin, STATE);
}