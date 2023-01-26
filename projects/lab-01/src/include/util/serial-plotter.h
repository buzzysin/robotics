#ifndef _SERIAL_PLOTTER_H
#define _SERIAL_PLOTTER_H

class SerialPlotter_c
{
  // Serial output
  String output;

public:
  void write(float value)
  {
    output += String(value) + ",";
  }

  void write(int value)
  {
    output += String(value) + ",";
  }

  void write(String value)
  {
    output += value + ",";
  }

  void plot()
  {
    output = output.substring(0, output.length() - 1);

    Serial.println(output);

    output = "";
  }
};

#endif // SERIAL_PLOTTER_H