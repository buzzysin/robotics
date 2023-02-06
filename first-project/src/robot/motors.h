#ifndef _MOTORS_H_
#define _MOTORS_H_

#include <Arduino.h>

#include "../util/setupable.h"
#include "../util/maths.h"

#include "motor.h"

namespace Pins
{
  // left motor
  static const byte MOTOR_L_PIN = 10;

  // right motor
  static const byte MOTOR_R_PIN = 9;

  // Left motor direction
  static const byte MOTOR_L_DIR_PIN = 16;

  // Right motor direction
  static const byte MOTOR_R_DIR_PIN = 15;
} // namespace Pins

class Motors : public HasSetup
{
public:
  enum Mode
  {
    // LINEAR mode means the motors will drive forward or backward, moving the entire robot
    LINEAR,
    // FINE mode means only one motor will drive forward or backward, causing the robot to
    // turn using the stationary (or slower) wheel as a pivot point
    FINE,
    // SPIN mode means both one motor will drive forward and the other will drive backward,
    // causing the robot to spin in place
    SPIN
  };

protected:
  Motor motor_l;
  Motor motor_r;

  float speed = Motor::MIN;
  byte direction = Motor::FWD;
  float drive_ratios[2] = {1.0f, 1.0f};
  Mode mode = LINEAR;

public:
  // Constructor
  Motors();

  // Set up the motors
  void setup() override;

  // Set the speed of the motors.
  // In SPIN mode, depending on the direction, this will cause the robot to spin in place.
  void setSpeed(float speed);

  // Set the direction of the robot.
  // In LINEAR mode, this will cause the robot to move forward or backward.
  // In FINE mode, this will cause the robot to turn left or right.
  // In SPIN mode, this will cause the robot to spin left or right.
  void setDirection(byte direction);

  // Set the operating mode of the motors
  //
  // LINEAR mode means the motors will drive forward or backward, moving the entire robot
  //
  // FINE mode means only one motor will drive forward or backward, causing the robot to
  // turn using the stationary (or slower) wheel as a pivot point
  //
  // SPIN mode means both one motor will drive forward and the other will drive backward,
  // causing the robot to spin in place.
  void setMode(Mode mode);

  // Set the drive ratios for the motors. This is only used in FINE mode.
  void setSteerLeft(float ratio);

  // Set the drive ratios for the motors. This is only used in FINE mode.
  void setSteerRight(float ratio);

  // Apply the speed, direction, and turn ratios to the motor drivers. This should be called inside the loop.
  void write();

  // Stop the motors. The motor parameters, such as speed and direction, are not changed.
  void stop();
};

#endif