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
        int digitToInt(Digit);
        Digit intToDigit(int);
        int getOperand(Digit[], int);
        void addDigitNumA(Digit);
        void addDigitNumB(Digit);
        float operate();

    public:
        CpuRuan();
        CpuRuan(Display&);
        void receiveDigit(Digit);
        void receiveOperation(Operation);
        void receiveControl(Control);
        void setDisplay(Display&);
};