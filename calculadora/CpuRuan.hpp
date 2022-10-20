#pragma once
#include "Calculator.hpp"

class CpuRuan : public Cpu {
    private:
        Display* display;
        Digit numA[MAX_DIGITS];
        Digit numB[MAX_DIGITS];
        Signal signalNumA;
        char digitCountNumA;
        char digitCountNumB;
        char decimalPositionA;
        char decimalPositionB;
        Operation operation;
        int digitToInt(Digit);
        Digit intToDigit(int);
        float getOperand(Digit[], int, int);
        void setExpressionInDigits(float);
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