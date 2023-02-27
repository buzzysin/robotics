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
  // Measurements
  unsigned long t_start = micros();
  unsigned long t_cancel = 5000; // We will spend at most 5ms reading
  unsigned long *ls_readings;

  // Reads
  ls_readings = lineSensors.read(t_cancel);

  // Writes
  motors.write();

  Serial.print("LL:");
  Serial.print(ls_readings[0]);
  Serial.print(",LC:");
  Serial.print(ls_readings[1]);
  Serial.print(",CC:");
  Serial.print(ls_readings[2]);
  Serial.print(",RC:");
  Serial.print(ls_readings[3]);
  Serial.print(",RR:");
  Serial.println(ls_readings[4]);
}