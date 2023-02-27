#ifndef _LINE_SENSORS_H_
#define _LINE_SENSORS_H_

#include <Arduino.h>

#include "../util/setupable.h"
#include "../util/io.h"

#include "line-sensor.h"
#include "ir-led.h"

static const byte LS_LL_MASK = 0b00001;
static const byte LS_LC_MASK = 0b00010;
static const byte LS_CC_MASK = 0b00100;
static const byte LS_RC_MASK = 0b01000;
static const byte LS_RR_MASK = 0b10000;

namespace Pins
{
  // Line sensor Left Left
  static const byte LS_LL_PIN = 12;

  // Line sensor Left Center
  static const byte LS_LC_PIN = A0; // 18

  // Line sensor Center Center
  static const byte LS_CC_PIN = A2; // 20;

  // Line sensor Right Center
  static const byte LS_RC_PIN = A3; // 21

  // Line sensor Right Right
  static const byte LS_RR_PIN = 22;
}

class LineSensors : public HasSetup
{

  // Properties
private:
  unsigned long timeout = 0;

  // Public properties
public:
  LineSensor ll;
  LineSensor lc;
  LineSensor cc;
  LineSensor rc;
  LineSensor rr;

  static const uint8_t COUNT = 5;
  LineSensor sensors[COUNT] = {ll, lc, cc, rc, rr};

  IrLed emitter;

  unsigned long readings[COUNT] = {0, 0, 0, 0, 0};

  // Public methods
public:
  // Constructor
  LineSensors();

  // Set up the line sensors
  void setup() override;

  // Allow the line sensors to discharge
  void disableCharging();

  // Allowing the line sensor capacitors to charge
  void enableCharging();

  // Read the line sensors. Intended to be used in a `loop()`.
  // Always returns a pointer to an array of 5 `unsigned long`s
  unsigned long *read(unsigned long t_cancel = 6000);

  unsigned long *readInterrupt();
};

#endif