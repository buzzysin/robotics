#include "src/robot/robot.h"

Robot robot;

void setup()
{
  Serial.begin(9600);
  robot.setup();
}

void loop()
{
  robot.loop();
}
