#ifndef _EX_05_H
#define _EX_05_H

#include "util/arduino-program.h"
#include "util/serial-plotter.h"

#include <math.h>

namespace Ex_05
{
  /**
   * Plot two sinusoids
   */
  class Part_01 : public ArduinoProgram
  {
  public:
    float x;
    float f;
    float y1;
    float y2;

    SerialPlotter_c plotter;

    void setup() override;
    void loop() override;
  };

  void Part_01::setup()
  {
    // Wait for the serial port to be ready
    while (!Serial)
      ;
  }

  void Part_01::loop()
  {
    x = millis() / 1000.0;
    f = PI * cos(TWO_PI * x / 5);
    y1 = cos(TWO_PI * x + (+f));
    y2 = cos(TWO_PI * x + (-f));

    plotter.write(y1);
    plotter.write(y2);

    plotter.plot();

    delay(10);
  }
}; // namespace Ex_05

#endif