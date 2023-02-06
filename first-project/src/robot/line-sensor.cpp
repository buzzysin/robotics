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
  // Set the pin to output
  pinMode(pin, OUTPUT);

  // Wait for the capacitor to charge
  delayMicroseconds(10);

  // Set the pin to input
  pinMode(pin, INPUT);

  // Reset the measurement
  reset();
}

void LineSensor::reset()
{
  // Reset the start time
  t_start = micros();

  // Reset the read time
  t_read = 0;
}

Optional<unsigned long> LineSensor::read()
{
  unsigned long t_new = micros() - t_start;

  // The capacitor has discharged
  if (digitalRead(pin) == LOW)
  {
    // If the read has been completed
    if (t_read)
    {
      // The read has been completed, return the result
      return of(t_read);
    }
    else
    {
      // Wait for the read to complete
      return of<unsigned long>();
    }
  }

  t_read = t_new;

  return of<unsigned long>();
}
