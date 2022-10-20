#pragma once

#include "Calculator.hpp"
#include "Console.hpp"

#define MAX_DIGITS 8

class DisplayRuan : public Display
{
private:
    Console console;
    int digitCount;
    int decimalPosition;
    Digit digits[MAX_DIGITS];
    Signal signal;
    void refresh();
    void showDigitShape(const char*, const char*, const char*, const char*, unsigned char);
public:
    DisplayRuan();
    ~DisplayRuan();
    void addDigit(Digit, bool withDot = false);
    void setSignal(Signal);
    void clear();
};