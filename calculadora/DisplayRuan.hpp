#pragma once

#include "Calculator.hpp"
#include "Console.hpp"

#define MAX_DIGIT 8

class DisplayRuan : public Display
{
private:
    Console console;
    int digitCount;
    Digit digits[MAX_DIGIT];
    Signal signal;

    void refresh();
public:
    DisplayRuan();
    ~DisplayRuan();
    void addDigit(Digit digit);
    void setSignal(Signal signal);
    void clear();
};