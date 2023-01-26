#include "src/include/lab-01.h"

ArduinoProgram *program = new Ex_05::Part_01(); // DONE

// Setup the robot
void setup()
{
#if defined(SERIAL_DEBUG)
  // Initialise the serial port
  Serial.begin(9600);
  Serial.println("Starting up...");
#endif

  // Initialise the robot
  program->setup();
}

// Main loop
void loop()
{
  // put your main code here, to run repeatedly:
  program->loop();
}
