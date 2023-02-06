#include "line-sensors.h"

LineSensors::LineSensors() : ll(LineSensor(Pins::LS_LL_PIN)),
                             lc(LineSensor(Pins::LS_LC_PIN)),
                             cc(LineSensor(Pins::LS_CC_PIN)),
                             rc(LineSensor(Pins::LS_RC_PIN)),
                             rr(LineSensor(Pins::LS_RR_PIN)),
                             emitter(IrLed(Pins::IR_LED_PIN))
{
}

void LineSensors::setup()
{
  ll.setup();
  lc.setup();
  cc.setup();
  rc.setup();
  rr.setup();
  emitter.setup();
}

void LineSensors::disable()
{
  emitter.on();
}

void LineSensors::enable()
{
  emitter.off();
}

unsigned long *LineSensors::read(unsigned long t_cancel)
{
  // Enable the line sensors
  enable();

  // The line sensor state
  uint8_t ls_state = 0b00000;

  // The line sensor readings
  unsigned long ls_readings[COUNT] = {0, 0, 0, 0, 0};

  // The start time
  unsigned long t_start = micros();

  // Wait for the line sensors to charge
  for (uint8_t i = 0; i < COUNT; i++)
  {

    sensors[i].charge();
  }

  // Wait for the line sensors to discharge
  while (ls_state != 0b11111)
  {
    // For each line sensor
    for (uint8_t i = 0; i < COUNT; i++)
    {
      // Read the line sensors
      auto ls_reading = sensors[i].read();

      if (ls_reading.notEmpty())
      {
        // Store the result
        ls_readings[i] = ls_reading.get();
        
        // Mark the line sensor as complete
        ls_state |= 1 << i;
      }
    }

    // If the read has timed out
    if (micros() - t_start > t_cancel)
    {
      // Exit the loop
      break;
    }
  }

  // Disable the line sensors
  disable();

  return ls_readings;
}