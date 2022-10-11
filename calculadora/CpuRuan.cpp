#include <math.h>

#include "CpuRuan.hpp"
#include "Calculator.hpp"

CpuRuan::CpuRuan() {

    operation = Operation::NOOP;
    digitCountNumA = 0;
    digitCountNumB = 0;
}

CpuRuan::CpuRuan(Display& display) {

    setDisplay(display);
    operation = Operation::NOOP;
    digitCountNumA = 0;
    digitCountNumB = 0;
}

int CpuRuan::digitToInt(Digit digit) {

    switch (digit) {
        case Digit::ZERO: return 0; break;
        case Digit::ONE: return 1; break;
        case Digit::TWO: return 2; break;
        case Digit::THREE: return 3; break;
        case Digit::FOUR: return 4; break;
        case Digit::FIVE: return 5; break;
        case Digit::SIX: return 6; break;
        case Digit::SEVEN: return 7; break;
        case Digit::EIGTH: return 8; break;
        case Digit::NINE: return 9; break;
        default: return 0; // TODO exception...
    }
}

Digit CpuRuan::intToDigit(int n) {

    switch (n) {
        case 0: return Digit::ZERO; break;
        case 1: return Digit::ONE; break;
        case 2: return Digit::TWO; break;
        case 3: return Digit::THREE; break;
        case 4: return Digit::FOUR; break;
        case 5: return Digit::FIVE; break;
        case 6: return Digit::SIX; break;
        case 7: return Digit::SEVEN; break;
        case 8: return Digit::EIGTH; break;
        case 9: return Digit::NINE; break;
        default: return Digit::ZERO;
    }
}

void CpuRuan::addDigitNumA(Digit digit) {

    if (digitCountNumA < MAX_DIGITS)
        numA[digitCountNumA++] = digit;
}

void CpuRuan::addDigitNumB(Digit digit) {

    if (digitCountNumB < MAX_DIGITS)
        numB[digitCountNumB++] = digit;
}

int CpuRuan::getOperand(Digit digits[], int count) {

    int acc = 0;
    for (int i = 0; i < count; i++) {
        acc *= 10;
        acc += digitToInt(digits[i]);
    }
    return acc;
}

float CpuRuan::operate() {

    float a = getOperand(numA, digitCountNumA);
    float b = getOperand(numB, digitCountNumB);
    digitCountNumA = 0;
    digitCountNumB = 0;
    float result = 0;
    switch (operation) {
        case Operation::ADD:
            result = a + b;
            break;
        case Operation::SUBTRACT:
            result = a - b;
            break;
        case Operation::MULTIPLY:
            result = a * b;
            break;
        case Operation::DIVIDE:
            result = a / b;
            break;
    }
    return result;
}

void CpuRuan::receiveDigit(Digit digit) {

}

void CpuRuan::receiveOperation(Operation operation) {

}

void CpuRuan::receiveControl(Control control) {
    
}

void CpuRuan::setDisplay(Display& display) {
    this->display = &display;
}