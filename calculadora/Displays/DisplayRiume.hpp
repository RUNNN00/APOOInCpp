#pragma once
#include "Calculator.hpp"

class DisplayRiume: public Display{
  public:
    void addDigit(Digit digit, bool withDot);
    void setSignal(Signal signal);
    void clear();
};