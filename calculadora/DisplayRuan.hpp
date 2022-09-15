#pragma once

#include "Calculator.hpp"
#include "Console.hpp"

class DisplayRuan : public Display
{
private:
    Console console;
    int digitCount;
    Digit digits[MAX_DIGITS];
    Signal signal;

    void refresh();
public:
    DisplayRuan();
    ~DisplayRuan();
    void addDigit(Digit digit);
    void setSignal(Signal signal);
    void clear();
};