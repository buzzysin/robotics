#include "src/include/lab-01.h"

// ArduinoProgram *program = new Ex_04::Part_04(); // DONE
ArduinoProgram *program = new Ex_05::Part_01(); // DONE

// Setup the robot
void setup()
{
  // Initialise the robot
  program->setup();
}

// Main loop
void loop()
{
  // put your main code here, to run repeatedly:
  program->loop();
}
