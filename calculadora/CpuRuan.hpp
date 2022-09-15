#pragma once
#include "Calculator.hpp"

class CpuRuan : public Cpu {
    private:
        Display* display;
        Digit numA[MAX_DIGITS];
        Digit numB[MAX_DIGITS];
        char digitCountNumA;
        char digitCountNumB;
        Operation operation;

        void addDigitNumA(Digit);
        void addDigitNumB(Digit);
        void operate(Operation);

    public:
        void receiveDigit(Digit);
        void receiveOperation(Operation);
        void setDisplay(Display&);
};