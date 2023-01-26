#ifndef _KINEMATICS_H
#define _KINEMATICS_H

// Class to track robot position.
class Kinematics_c
{
public:
  // Public variables and functions.

  // The x position of the robot.
  double x;

  // The y position of the robot.
  double y;

  // The rotation of the robot, in radians.
  double theta;

protected:
  // No protected variables or functions.

public:
  // Constructor, must exist.
  Kinematics_c()
  {
    x = 0.0f;
    y = 0.0f;
    theta = 0.0f;
  }

  // Use this function to update
  // your kinematics
  void update()
  {
  }
};

#endif