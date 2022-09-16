#include "CpuRuan.hpp"
#include "Calculator.hpp"

void CpuRuan::addDigitNumA(Digit digit) {

    if (digitCountNumA < MAX_DIGITS)
        numA[digitCountNumA++] = digit;
}

void CpuRuan::addDigitNumB(Digit digit) {

    if (digitCountNumB < MAX_DIGITS)
        numB[digitCountNumB++] = digit;
}

void CpuRuan::operate() {

    int a;// = getNumA(); remove digits
    int b;// = getNumB(); remove digits
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
    // Guardar o resultado no numA
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