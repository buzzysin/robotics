#ifndef _LINE_SENSOR_PROGRAM_H_
#define _LINE_SENSOR_PROGRAM_H_

#include <Arduino.h>

#include "../util/arduino-program.h"
#include "../robot/line-sensor.h"

class LineSensorProgram : public ArduinoProgram
{
  // Properties
protected:
  LineSensor *lineSensor;

  // Methods
public:
  LineSensorProgram(LineSensor *lineSensor)
  {
    lineSensor = lineSensor;
  }

  void setup() override
  {
    lineSensor->setup();
  }

  void loop() override
  {
  }
}; // class LineSensorProgram

#endif