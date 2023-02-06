#ifndef _HACKS_H_
#define _HACKS_H_

// Arduino
#include <Arduino.h>

template <typename Ret, typename... Args>
class Function
{
public:
  virtual Ret operator()(Args... args) = 0;
};

template <typename Ret, typename Binding, typename... Args>
class BoundFunction : public Function<Ret, Args...>
{
public:
  typedef Ret (Binding::*Method)(Args...);

  BoundFunction(Binding *binding, Method method)
  {
    this->binding = binding;
    this->method = method;
  }

  Ret operator()(Args... args) override
  {
    return (this->binding->*this->method)(args...);
  }

private:
  Binding *binding;
  Method method;
};

#endif