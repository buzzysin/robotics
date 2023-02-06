#include "leds.h"

Leds::Leds() : l(Led(Pins::LED_L_PIN)),
               c(Led(Pins::LED_C_PIN)),
               r(Led(Pins::LED_R_PIN))
{
}

void Leds::setup()
{
  l.setup();
  c.setup();
  r.setup();
}
