#ifndef _TEST_DELAY_TIMER_H_
#define _TEST_DELAY_TIMER_H_

#include "../util/arduino-program.h"
#include "../util/waiter.h"

namespace Programs
{
  class TestDelayTimer : public ArduinoProgram
  {
  protected:
    Waiter waiter;

  public:
  };
}

#endif