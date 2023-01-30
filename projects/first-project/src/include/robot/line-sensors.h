#ifndef _LINE_SENSORS_H_
#define _LINE_SENSORS_H_

#include "../util/setupable.h"

#include "line-sensor.h"
#include "ir-led.h"

class LineSensors : public Setupable
{
public:
  // PINS

  // Left Left
  static const byte LL_PIN = 12;
  static const byte LL_MASK = 0b00001;

  // Left Center
  static const byte LC_PIN = A0; // 18
  static const byte LC_MASK = 0b00010;

  // Center Center
  static const byte CC_PIN = A2; // 20;
  static const byte CC_MASK = 0b00100;

  // Right Center
  static const byte RC_PIN = A3; // 21
  static const byte RC_MASK = 0b01000;

  // Right Right
  static const byte RR_PIN = 22;
  static const byte RR_MASK = 0b10000;

  LineSensor ll;
  LineSensor lc;
  LineSensor cc;
  LineSensor rc;
  LineSensor rr;

  IrLed irLed;

public:
  LineSensors() : ll(LineSensor(LL_PIN)), lc(LineSensor(LC_PIN)), cc(LineSensor(CC_PIN)), rc(LineSensor(RC_PIN)), rr(LineSensor(RR_PIN)),
                  irLed(IrLed())
  {
  }

  void setup() override
  {
    irLed.setup();

    ll.setup();
    lc.setup();
    cc.setup();
    rc.setup();
    rr.setup();

    irLed.on();
  }

  // Check if any of the sensors are active
  bool anyActive() const
  {
    return ll.isActive() || lc.isActive() || cc.isActive() || rc.isActive() || rr.isActive();
  }

  // Check if all of the sensors are active
  bool allActive() const
  {
    return ll.isActive() && lc.isActive() && cc.isActive() && rc.isActive() && rr.isActive();
  }

  // Check if the sensors are active based on the mask
  void setActive(byte mask)
  {
    for (byte i = 0; i < 5; i++)
    {
      byte bit = 1 << i;
      if (mask & bit)
      {
        switch (i)
        {
        case 0:
          ll.setActive();
          break;
        case 1:
          lc.setActive();
          break;
        case 2:
          cc.setActive();
          break;
        case 3:
          rc.setActive();
          break;
        case 4:
          rr.setActive();
          break;
        }
      }
    }
  }

  void setActive()
  {
    ll.setActive();
    lc.setActive();
    cc.setActive();
    rc.setActive();
    rr.setActive();
  }

  byte getActive() const
  {
    byte mask = 0;

    if (ll.isActive())
      mask |= LL_MASK;

    if (lc.isActive())
      mask |= LC_MASK;

    if (cc.isActive())
      mask |= CC_MASK;

    if (rc.isActive())
      mask |= RC_MASK;

    if (rr.isActive())
      mask |= RR_MASK;

    return mask;
  }

  void getActiveByCopy(byte &mask) const
  {
    mask = 0;

    if (ll.isActive())
      mask |= LL_MASK;

    if (lc.isActive())
      mask |= LC_MASK;

    if (cc.isActive())
      mask |= CC_MASK;

    if (rc.isActive())
      mask |= RC_MASK;

    if (rr.isActive())
      mask |= RR_MASK;
  }

  // In order for the line sensors to work, the IR LED must be enabled.
  // This is because the line sensors are reflectance sensors. The IR LED
  // emits IR light, and the line sensors detect the reflected light.
  void enable()
  {
    irLed.on();
  }

  // Turning off the IR LED will disable the line sensors.
  void disable()
  {
    irLed.off();
  }

  // The line sensors are set to output mode
  void enableWrite()
  {
    ll.enableWrite();
    lc.enableWrite();
    cc.enableWrite();
    rc.enableWrite();
    rr.enableWrite();
  }

  // The line sensors are set to input mode
  void enableRead()
  {
    ll.enableRead();
    lc.enableRead();
    cc.enableRead();
    rc.enableRead();
    rr.enableRead();
  }
};

#endif