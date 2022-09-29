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

void CpuRuan::setExpressionInNumA(int expression) {

    int num[MAX_DIGITS];
    int decimal = (int) pow(10, MAX_DIGITS - 1);
    for (int i = 0; i < MAX_DIGITS; i++) {
        num[i] = expression / decimal % 10;
        decimal /= 10;
    }

    int i = 0;
    while (num[i] == 0) { i++; }
    int count = MAX_DIGITS - i;
    for (int j = 0; j < count; j++) {
        addDigitNumA(intToDigit(num[i]));
        i++;
    }
}

void CpuRuan::operate() {

    int a = getOperand(numA, digitCountNumA);
    int b = getOperand(numB, digitCountNumB);
    digitCountNumA = 0;
    digitCountNumB = 0;
    int result = 0;
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
    setExpressionInNumA(result);
    display->showDigits(numA, digitCountNumA);
}

void CpuRuan::receiveDigit(Digit digit) {

    if (operation == Operation::NOOP) {
        addDigitNumA(digit);
    }
    else if (operation == Operation::EQUAL) {
        digitCountNumA = 0;
        display->clear();
        addDigitNumA(digit);
    }
    else {
        if (digitCountNumB == 0)
            display->clear();
        addDigitNumB(digit);
    }
    display->addDigit(digit);
}

void CpuRuan::receiveOperation(Operation operation) {

    if (this->operation != Operation::NOOP && digitCountNumB > 0)
        operate();

    this->operation = operation;
}

void CpuRuan::receiveControl(Control control) {
    // TODO switch controls behaviour
}

void CpuRuan::setDisplay(Display& display) {
    this->display = &display;
}