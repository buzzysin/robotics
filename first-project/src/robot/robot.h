#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <Arduino.h>

#include "../util/setupable.h"
#include "../util/loopable.h"

#include "line-sensors.h"
#include "motors.h"
#include "leds.h"

class Robot : public HasSetup, public HasLoop
{
protected:
  LineSensors lineSensors;
  Motors motors;
  Leds leds;
  

public:
  // Constructor
  Robot();

  // Set up the robot
  void setup() override;

  // Update the robot
  void loop() override;
};

#endif