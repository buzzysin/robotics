#include "line-sensor.h"

LineSensor::LineSensor(byte pin, unsigned long timeout) : pin(pin),
                                                          t_cancel(timeout)
{
}

void LineSensor::setup()
{
  pinMode(pin, INPUT);
}

void LineSensor::charge()
{
  // Serial.println("Charging capacitor");

  // Set the pin to output
  pinMode(pin, OUTPUT);

  // Temporarily set the pin to high
  digitalWrite(pin, HIGH);

  // Wait for the capacitor to charge
  delayMicroseconds(10);

  // Set the pin to input
  pinMode(pin, INPUT);

  // Reset the measurement
  reset();
}

void LineSensor::reset()
{
  // Serial.println("Resetting line sensor");

  // Reset the start time
  t_start = micros();

  // Reset the read time
  t_read = 0;
}

unsigned long LineSensor::read()
{
  // Capture the current time
  unsigned long t_new = micros() - t_start;

  // If we have a previous reading, return it
  if (t_read > 0)
  {
    // Serial.println("Using previous reading");
    return t_read;
  }

  // The capacitor has discharged
  if (digitalRead(pin) == LOW)
  {
    // Serial.println("Capacitor has discharged");

    // Capture the time
    t_read = t_new;

    // Return the time
    return t_read;
  }
  // The capacitor has not yet discharged
  else
  {
    // Serial.println("Capacitor has not yet discharged");
    // We are still charging, return 0 until we discharge
    return 0;
  }
}
