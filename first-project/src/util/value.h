#ifndef _VALUE_H_
#define _VALUE_H_

#include <Arduino.h>

template <typename T>
class Value
{
  // Properties
protected:
  T value;

  // Methods
public:
  Value(T value) : value(value)
  {
  }

  T get()
  {
    return this->value;
  }

  void set(T value)
  {
    this->value = value;
  }
};

#endif