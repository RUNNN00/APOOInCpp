#pragma once
#include "Calculator.hpp"

class CpuRuan : public Cpu {
    private:
        Display* display;
        Digit numA[MAX_DIGITS];
        Digit numB[MAX_DIGITS];
        char digitCountNumA;
        char digitCountNumB;
        char decimalPositionA;
        char decimalPositionB;
        Operation operation;
        int digitToInt(Digit);
        Digit intToDigit(int);
        int getOperand(Digit[], int);
        void setExpressionInDigit(float);
        void addDigitNumA(Digit);
        void addDigitNumB(Digit);
        void operate();

    public:
        CpuRuan();
        CpuRuan(Display&);
        void setDisplay(Display&);
        void receiveDigit(Digit);
        void receiveOperation(Operation);
        void receiveControl(Control);
};