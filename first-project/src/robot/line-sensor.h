#ifndef _LINE_SENSOR_H_
#define _LINE_SENSOR_H_

#include <Arduino.h>

#include "../util/setupable.h"
#include "../util/optional.h"


class LineSensor : public HasSetup
{
  // Properties
protected:
  byte pin;
  unsigned long t_cancel;
  unsigned long t_start;
  unsigned long t_read = 0;

  // Methods
public:
  // Constructor
  LineSensor(byte pin, unsigned long timeout = 0);

  // Set up the line sensor
  void setup() override;

  // Read the line sensor
  unsigned long read();

  // Charge the line sensor
  void charge();

  // Reset the line sensor
  void reset();
};

#endif