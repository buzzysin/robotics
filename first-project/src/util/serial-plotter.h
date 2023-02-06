#ifndef _SERIAL_PLOTTER_H
#define _SERIAL_PLOTTER_H

#include <Arduino.h>

#include "debugging.h"

uint32_t PLOT_INDEX = 0;
const uint32_t PLOT_MAX_ENTRIES = 50;
const uint32_t PLOT_MAX_ENTRY_LENGTH = 20;
char PLOT[PLOT_MAX_ENTRIES][PLOT_MAX_ENTRY_LENGTH];

class SerialPlotter
{

public:
  void write(double value)
  {
    strcat(PLOT[PLOT_INDEX], String(value).c_str());
    strcat(PLOT[PLOT_INDEX], ",");
  }

  void write(unsigned long value)
  {
    strcat(PLOT[PLOT_INDEX], String(value).c_str());
    strcat(PLOT[PLOT_INDEX], ",");
  }

  void write(String value)
  {
    strcat(PLOT[PLOT_INDEX], value.c_str());
    strcat(PLOT[PLOT_INDEX], ",");
  }

  void plot()
  {
    onActiveSerialConnection
    {
      PLOT[PLOT_INDEX][strlen(PLOT[PLOT_INDEX]) - 1] = '\0';

      for (uint32_t i = 0; i <= PLOT_INDEX; i++)
      {
        Serial.println(PLOT[i]);

        // Clear the plot entry
        memset(PLOT[i], 0, PLOT_MAX_ENTRY_LENGTH);
      }
      
      PLOT_INDEX = 0;
    }
    else
    {
      PLOT_INDEX += 1;
      PLOT_INDEX %= PLOT_MAX_ENTRIES;
    }
  }
};

#endif // SERIAL_PLOTTER_H