#include "robot.h"

// Constructor
Robot::Robot()
{
}

// Set up the robot
void Robot::setup()
{
  lineSensors.setup();
  motors.setup();
  leds.setup();
}

// Update the robot
void Robot::loop()
{
  // Reads
  lineSensors.read();

  // Writes
  motors.write();
}