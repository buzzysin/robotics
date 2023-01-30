#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "../util/setupable.h"

class Motors;

class Motor : public Setupable
{

  friend class Motors; // Allow Motors to access private members

public:
  // Forward is LOW
  static const byte FWD = LOW;

  // Reverse is HIGH
  static const byte REV = HIGH;

  // Speed limits
  // No power
  static constexpr double MIN = 0.00f;
  // Max power
  static constexpr double MAX = 1.00f;

  // Speeds
  // 1/8th power
  static constexpr double VERY_SLOW = MAX / 8;
  // 1/4th power
  static constexpr double SLOW = VERY_SLOW * 2;
  // 3/8th power
  static constexpr double MED_SLOW = VERY_SLOW * 3;
  // 1/2 power
  static constexpr double MED = VERY_SLOW * 4;
  // 5/8th power
  static constexpr double MED_FAST = VERY_SLOW * 5;
  // 3/4th power
  static constexpr double FAST = VERY_SLOW * 6;
  // 7/8th power
  static constexpr double VERY_FAST = VERY_SLOW * 7;

  // Constants
  static constexpr double WHEEL_DIAMETER_M = 0.065f;

private:
  const byte pin;
  const byte direction_pin;

  float speed = 0.0f;

public:
  Motor(int pin, int direction_pin) : pin(pin), direction_pin(direction_pin)
  {
  }

  void setup() override
  {
    pinMode(pin, OUTPUT);
    pinMode(direction_pin, OUTPUT);
  }

  // Set the speed of the motors. Also sets the direction.
  void setSpeed(double speed)
  {
    this->speed = speed;
  }

  // Get the direction of the motor
  double getSpeed() const
  {
    return speed;
  }

  // Get the power of the motor (passed to analogWrite)
  int getPower() const
  {
    return 255 * abs(clamp(getSpeed(), -MAX, MAX));
  }

  // Get the direction of the motor
  byte getDirection() const
  {
    return getSpeed() >= 0 ? FWD : REV;
  }

  // Write the direction and power to the motor
  void drive()
  {
    analogWrite(pin, getPower());
    digitalWrite(direction_pin, getDirection());
  }
};

#endif