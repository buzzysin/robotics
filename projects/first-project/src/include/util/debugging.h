#ifndef _DEBUGGING_H_
#define _DEBUGGING_H_

/*
 * A known problem is that removing the USB cable during
 * the robot operation can cause very irratic behaviour.
 * Plugging in a USB cable can also reset your robot.
 * The root cause is not known (memory error?), but the
 * following example provides a solution.
 */
#include <USBCore.h> // To fix serial print behaviour bug.
u8 USB_SendSpace(u8 ep);
#define SERIAL_ACTIVE (USB_SendSpace(CDC_TX) >= 50)

#define SerialDebug \ 
  if (SERIAL_ACTIVE) Serial

#define SerialDebugln \
  if (SERIAL_ACTIVE)  \
  Serial.println

#define onActiveSerialConnection \
  if (SERIAL_ACTIVE)

#endif