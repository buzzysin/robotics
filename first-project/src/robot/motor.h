#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>

#include "../util/setupable.h"

class Motors;

class Motor : public HasSetup
{

  friend class Motors; // Allow Motors to access private members

public:
  // Forward is LOW
  static const byte FWD = LOW;

  // Reverse is HIGH
  static const byte REV = HIGH;

  // Speed limits
  // No power
  static constexpr float STOP = 0.00f;
  // Max power
  static constexpr float MAX = 1.00f;
  // Min power
  static constexpr float MIN = MAX / 8.0f;

  // Speeds

  // 1/8th power
  static constexpr float VERY_SLOW = MIN;
  // 1/4th power
  static constexpr float SLOW = MIN * 2;
  // 3/8th power
  static constexpr float MED_SLOW = MIN * 3;
  // 1/2 power
  static constexpr float MED = MIN * 4;
  // 5/8th power
  static constexpr float MED_FAST = MIN * 5;
  // 3/4th power
  static constexpr float FAST = MIN * 6;
  // 7/8th power
  static constexpr float VERY_FAST = MIN * 7;

  // Constants

  // Wheel diameter in meters
  static constexpr float WHEEL_DIAMETER_M = 0.065f;

private:
  const byte pin;
  const byte direction_pin;

  float speed = 0.0f;

public:
  Motor(byte pin, byte direction_pin);

  // Set up the motor
  void setup() override;

  // Set the speed of the motor
  void setSpeed(float speed);

  // Set the direction of the motor
  void setDirection(byte direction);

  // Apply the speed and direction to the motor. This should be called after
  // setSpeed and setDirection to apply the changes.
  void write();

  void stop();
};

#endif