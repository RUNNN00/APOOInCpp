#include "CpuRuan.hpp"
#include "Calculator.hpp"

#include <stdio.h>

CpuRuan::CpuRuan() {
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

void CpuRuan::operate() {

    int a = getOperand(numA, digitCountNumA);
    int b = getOperand(numB, digitCountNumB);
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

    // converter o resultado para digits na numA
    // limpar tela
    // Mostra numA na tela
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("result: %d\n", result);
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

void CpuRuan::setDisplay(Display& display) {
    this->display = &display;
}