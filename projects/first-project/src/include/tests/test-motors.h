#ifndef _TEST_MOTORS_H_
#define _TEST_MOTORS_H_

#include "../util/arduino-program.h"

#include "../robot/motors.h"

namespace Programs
{
  // Wheel diameter: 0.065 m +- 0.001 m
  // Wheel circumference: 0.065 * pi = 0.203 m +- 0.003 m
  // 5 cycles in 8072 ms at 12.5% power (right wheel)
  //
  // Estimate cycles per second at 100% power:
  // ( 5 cycles / 8072 ms ) = 0.125 * Max Hz
  // 0.125 * Max Hz = 0.618 Hz
  // Max Hz = 4.944 Hz
  //
  // Meters per second at 100% power:
  // 4.944 Hz * 0.203 m = 1.001 m/s +- 0.012 m/s
  class TestMotors : public ArduinoProgram
  {
  protected:
    Motors motors;

  public:
    void setup() override
    {
      motors.setup();
      motors.setSpeed(Motor::VERY_FAST);
    }

    void loop() override
    {
      motors.drive();
    }
  };

};

#endif