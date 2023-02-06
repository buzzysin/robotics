#include "motors.h"

Motors::Motors() : motor_l(Pins::MOTOR_L_PIN, Pins::MOTOR_L_DIR_PIN),
                   motor_r(Pins::MOTOR_R_PIN, Pins::MOTOR_R_DIR_PIN)
{
}

void Motors::setup()
{
  motor_l.setup();
  motor_r.setup();
}

void Motors::setSpeed(float speed)
{
  switch (mode)
  {
  case FINE:
    motor_l.setSpeed(speed * drive_ratios[0]);
    motor_r.setSpeed(speed * drive_ratios[1]);
    break;
  default:
    motor_l.setSpeed(speed);
    motor_r.setSpeed(speed);
  }

  this->speed = speed;
}

void Motors::setDirection(byte direction)
{
  this->direction = direction;
  switch (mode)
  {
    // Only in spin mode does one motor go in reverse with respect to the other
  case SPIN:
    switch (direction)
    {
    case Motor::FWD:
      motor_l.setDirection(Motor::FWD);
      motor_r.setDirection(Motor::REV);
      break;

    case Motor::REV:
      motor_l.setDirection(Motor::REV);
      motor_r.setDirection(Motor::FWD);
      break;
    }
    break;

  // Otherwise, both motors go in the same direction
  default:
    switch (direction)
    {
    case Motor::FWD:
      motor_l.setDirection(Motor::FWD);
      motor_r.setDirection(Motor::FWD);
      break;

    case Motor::REV:
      motor_l.setDirection(Motor::REV);
      motor_r.setDirection(Motor::REV);
      break;
    }
  }
}

void Motors::setMode(Mode mode)
{
  this->mode = mode;
}

// Set the steering of the robot. This is only used in fine mode.
void Motors::setSteerLeft(float steer)
{
  if (mode == FINE)
  {
    drive_ratios[0] = 1.0f - steer;
    drive_ratios[1] = 1.0f;
  }
}

// Set the steering of the robot. This is only used in fine mode.
void Motors::setSteerRight(float steer)
{
  if (mode == FINE)
  {
    drive_ratios[0] = 1.0f;
    drive_ratios[1] = 1.0f - steer;
  }
}

void Motors::write()
{
  motor_l.write();
  motor_r.write();
}

void Motors::stop()
{
  motor_l.stop();
  motor_r.stop();
}