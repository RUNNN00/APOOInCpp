#include "CpuRuan.hpp"
#include "Calculator.hpp"

void CpuRuan::convertNumToDigits(int num, Digit digits[]) {

    int aux = num;
    int j = 1;
    for (int i = MAX_DIGITS - 1; i >= 0; i--) {
        aux = num / j % 10;
        j *= 10;
    }
}

int CpuRuan::setDecimalSystem(int index, int digit, int size) {

    int aux = size - index;
    switch (aux) {
        case 2:
        return digit * 10;
        case 3:
        return digit * 100;
        case 4:
        return digit * 1000;
        case 5:
        return digit * 10000;
        case 6:
        return digit * 100000;
        case 7:
        return digit * 1000000;
        case 8:
        return digit * 10000000;
        default:
        return digit;
    }
}

int CpuRuan::getNum(Digit numVet[], int size) {

    int num = 0;
    for (int i = 0; i < size; i++) {
        int aux = 0;
        switch (numVet[i]) {
            case Digit::ZERO: aux = 0; break;
            case Digit::ONE: aux = 1; break;
            case Digit::TWO: aux = 2; break;
            case Digit::THREE: aux = 3; break;
            case Digit::FOUR: aux = 4; break;
            case Digit::FIVE: aux = 5; break;
            case Digit::SIX: aux = 6; break;
            case Digit::SEVEN: aux = 7; break;
            case Digit::EIGTH: aux = 8; break;
            default: aux = 0;
        }
        num += setDecimalSystem(i, aux, size);
    }
    return num;
}

void CpuRuan::addDigitNumA(Digit digit) {

    if (digitCountNumA < MAX_DIGITS)
        numA[digitCountNumA++] = digit;
}

void CpuRuan::addDigitNumB(Digit digit) {

    if (digitCountNumB < MAX_DIGITS)
        numB[digitCountNumB++] = digit;
}

void CpuRuan::operate() {

    int a = getNum(numA, digitCountNumA);
    digitCountNumA = 0;
    int b = getNum(numB, digitCountNumB);
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
    display->clear();
    convertNumToDigits(result, numA);
    // Mostra numA na tela
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