#pragma once
#include "Calculator.hpp"

class CpuRuan : public Cpu {
    private:
        Display* display;
        Operation operation;
        Digit digitsOperandA[MAX_DIGITS];
        Digit digitsOperandB[MAX_DIGITS];
        unsigned char countOperandA;
        unsigned char countOperandB;
        void operate();
        int digitToInt(Digit);
        Digit intToDigit(int);
        float getOperand(Digit[], int, int);
        void addDigitNumA(Digit);
        void addDigitNumB(Digit);
    public:
        CpuRuan();
        CpuRuan(Display&);
        void setDisplay(Display&);
        void receiveDigit(Digit);
        void receiveOperation(Operation);
        void receiveControl(Control);
};