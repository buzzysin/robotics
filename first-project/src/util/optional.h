#ifndef _FAKE_ASYNC_H_
#define _FAKE_ASYNC_H_

#include <Arduino.h>

template <typename T>
class Optional
{
  T item;
  bool _empty;

public:
  Optional(T result, bool _empty)
  {
    this->item = result;
    this->_empty = _empty;
  }

  T get()
  {
    return item;
  }

  bool notEmpty()
  {
    return _empty;
  }

  bool empty()
  {
    return !_empty;
  }

  operator bool()
  {
    return notEmpty();
  }
};

template <typename T>
static Optional<T> of(T result)
{
  return Optional<T>{result, true};
}

template <typename T>
static Optional<T> of()
{
  return Optional<T>{T(), false};
}

#endif
