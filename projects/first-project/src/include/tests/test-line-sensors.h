#ifndef _TEST_LINE_SENSORS_H_
#define _TEST_LINE_SENSORS_H_

#include "../util/arduino-program.h"
#include "../robot/line-sensors.h"
#include "../robot/motors.h"
#include "../util/debugging.h"
#include "../util/serial-plotter.h"

namespace Programs
{
  class TestLineSensors : public ArduinoProgram
  {

  private:
    LineSensors lineSensors;
    Motors motors;
    SerialPlotter plotter;
    unsigned long startTime;
    unsigned long endTime;
    unsigned long minTime = 0UL - 1;
    unsigned long maxTime = 0;

  public:
    void setup() override
    {
      lineSensors.setup();
      motors.setup();

      motors.setSpeed(Motor::VERY_SLOW);
    }

    void loop() override
    {
      // Temporarily set sensors to output HIGH
      lineSensors.enableWrite();
      lineSensors.setActive();

      // Wait for capacitors to charge
      delayMicroseconds(10);

      // Reset sensors to input
      lineSensors.enableRead();

      // Set startTime
      startTime = micros();

      byte active = 0;

      // Wait for capacitors to discharge
      while (lineSensors.anyActive())
        lineSensors.getActiveByCopy(active);

      // Set endTime
      endTime = micros();

      // Print results
      unsigned long elapsed = endTime - startTime;

      if (elapsed < minTime)
        minTime = elapsed;

      if (elapsed > maxTime)
        maxTime = elapsed;

      int numActive = 0;

      for (int i = 0; i < 5; i++)
        if (active & (1 << i))
          numActive++;

      plotter.plot();

      delay(100);

      motors.drive();
    }
  };

} // namespace Programs

#endif