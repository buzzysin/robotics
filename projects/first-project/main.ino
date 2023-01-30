#include "src/include/tests/test-motors.h"
#include "src/include/tests/test-line-sensors.h"
#include "src/include/tests/test-delay-timer.h"

// auto *program = new Programs::TestMotors();
auto *program = new Programs::TestLineSensors();
// auto *program = new Programs::TestDelayTimer();

void setup()
{
  Serial.begin(9600);

  program->setup();
}

void loop()
{
  program->loop();
}