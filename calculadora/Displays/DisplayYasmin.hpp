#pragma once
#include "Calculator.hpp"
#include "Console.hpp"
//#define MAX_DIGITS 8

class DisplayYasmin : public Display // implementa metodos sobrescrevendo-os (define comportamentos)
{
private:
    Console console;
    Digit digits[MAX_DIGITS];
    unsigned char counter;
    unsigned char decimalCounter;
    Signal signal;
    void refresh();
    void showDigitShape(const char * line1, const char * line2, const char * line3, const char * line4, const char * line5, unsigned char column);
    void setDecimalSeparator();
void setDigit(Digit& );

public:
    DisplayYasmin();
    void addDigit(Digit digit, bool withDot);
    void setSignal(Signal signal);
    void clear();
};
