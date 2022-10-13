#pragma once

#include "Calculator.hpp"
#include "Console.hpp"

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
    void showDigits(Digit[], int, int);
    void addDigit(Digit);
    void setDecimal();
    void setSignal(Signal);
    void clear();
};