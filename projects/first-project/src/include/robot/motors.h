#ifndef _MOTORS_H_
#define _MOTORS_H_

#include "../util/setupable.h"
#include "../util/maths.h"

#include "motor.h"

class Motors : public Setupable
{
public:
  // PINS

  // Drive the left motor
  static const byte L_PIN = 10;

  // Drive the right motor
  static const byte R_PIN = 9;

  // Direction of the left motor
  static const byte L_DIR_PIN = 16;

  // Direction of the right motor
  static const byte R_DIR_PIN = 15;

  Motor motor_l;
  Motor motor_r;

  // -1 to 1. 0 is stopped
  double speed = 0.0f;
  byte direction = Motor::FWD;

  // -1 to 1. 0 is straight ahead
  double turn_speed = 0.0f;

public:
  Motors() : motor_l(Motor(L_PIN, L_DIR_PIN)), motor_r(Motor(R_PIN, R_DIR_PIN))
  {
  }

  void setup() override
  {
    motor_l.setup();
    motor_r.setup();
  }

  void setTurnSpeed(double turn_speed)
  {
    this->turn_speed = clamp(turn_speed, -1.0f, 1.0f);
  }

  double getTurnSpeed() const
  {
    return turn_speed;
  }

  // Set the speed of the motors. Also sets the direction.
  void setSpeed(double speed)
  {
    this->speed = clamp(speed, -1.0f, 1.0f);
  }

  double getSpeed() const
  {
    return speed;
  }

  void drive()
  {
    double lspeed = this->speed * clamp(0.5 * (1 + getTurnSpeed()), -1.0f, 1.0f);
    double rspeed = this->speed * clamp(0.5 * (1 - getTurnSpeed()), -1.0f, 1.0f);

    motor_l.setSpeed(lspeed);
    motor_r.setSpeed(rspeed);

    motor_l.drive();
    motor_r.drive();
  }
};

#endif