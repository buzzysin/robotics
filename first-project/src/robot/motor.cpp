#include "motor.h"

Motor::Motor(byte pin, byte direction_pin) : pin(pin), direction_pin(direction_pin)
{
}

void Motor::setup()
{
  pinMode(pin, OUTPUT);
  pinMode(direction_pin, OUTPUT);
}

void Motor::setSpeed(float speed)
{
  this->speed = speed;
}

void Motor::setDirection(byte direction)
{
  digitalWrite(direction_pin, direction);
}

void Motor::write()
{
  analogWrite(pin, speed * 255);
}

void Motor::stop()
{
  analogWrite(pin, 0);
}
