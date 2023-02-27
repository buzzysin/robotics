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

void LineSensors::disableCharging()
{
  emitter.off();
  // Serial.println("Turned off emitter");
}

void LineSensors::enableCharging()
{
  emitter.on();
  // Serial.println("Turned on emitter");
}

unsigned long *LineSensors::read(unsigned long t_cancel)
{
  // Enable the line sensors
  enableCharging();

  // The start time
  unsigned long t_start = micros();

  // Wait for the line sensors to charge
  for (uint8_t i = 0; i < COUNT; i++)
  {
    sensors[i].charge();
    // Serial.println("Charged line sensor " + String(i));
  }

  // Disable the line sensors
  disableCharging();

  // The line sensor state
  uint8_t ls_state = 0b00000;

  // Wait for the line sensors to discharge
  while (ls_state != 0b11111)
  {
    // For each line sensor
    for (uint8_t i = 0; i < COUNT; i++)
    {
      auto sensor = sensors[i];

      if (ls_state & 1 << i)
      {
        // Serial.println("Skipping line sensor " + String(i));
        // Skip the line sensor if it has already been read
        continue;
      }

      // Read the line sensor
      auto ls_reading = sensor.read();

      if (ls_reading != 0)
      {
        // Store the result
        readings[i] = ls_reading;

        // Mark the line sensor as complete
        ls_state |= 1 << i;
      }
    }

    // If the read has timed out
    if (micros() - t_start > t_cancel)
    {
      // Exit the loop
      // Serial.println("Read timed out, giving up");
      
      for (uint8_t i = 0; i < COUNT; i++)
      {
        if (ls_state & 1 << i)
        {
          continue;
        }

        // Set the reading to the maximum value
        readings[i] = t_cancel;
      }
    }
  }

  return readings;
}