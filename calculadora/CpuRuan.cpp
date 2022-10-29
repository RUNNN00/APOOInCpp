#include "CpuRuan.hpp"
#include "Calculator.hpp"

CpuRuan::CpuRuan()
{
    operation = Operation::NOOP;
    countOperandA = 0;
    countOperandB = 0;
}

CpuRuan::CpuRuan(Display &display)
{
    setDisplay(display);
    operation = Operation::NOOP;
    countOperandA = 0;
    countOperandB = 0;
}

void CpuRuan::setDisplay(Display &display)
{
    this->display = &display;
}

void CpuRuan::receiveDigit(Digit digit)
{
    if (operation == Operation::NOOP)
    {
        addDigitNumA(digit);
    }
    else
    {
        if (countOperandB == 0)
            display->clear();
        addDigitNumB(digit);
    }

    display->addDigit(digit);
}

void CpuRuan::receiveOperation(Operation operation)
{
    if (operation == Operation::SUBTRACT && countOperandA < 1)
        addDigitNumA(ZERO);

    if (operation != Operation::NOOP && countOperandB > 0)
        operate();

    this->operation = operation;
}

void CpuRuan::receiveControl(Control control)
{
    switch (control)
    {
    case Control::EQUAL:
        if (countOperandB > 0)
            operate();
        break;
    default:
        break;
    }
}

void CpuRuan::addDigitNumA(Digit digit)
{
    if (countOperandA < MAX_DIGITS)
        digitsOperandA[countOperandA++] = digit;
}

void CpuRuan::addDigitNumB(Digit digit)
{
    if (countOperandB < MAX_DIGITS)
        digitsOperandB[countOperandB++] = digit;
}

void CpuRuan::operate()
{
    float a;// = getOperand(digitsOperandA, countOperandA, decimalPositionA);
    float b;// = getOperand(digitsOperandB, countOperandB, decimalPositionB);
    countOperandA = 0;
    countOperandB = 0;

    //if (signalNumA == Signal::NEGATIVE && a > 0)
    //    a *= -1;

    float result = 0;
    switch (operation)
    {
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

    //setExpressionInDigits(result);
    // atualiza o display
}


int CpuRuan::digitToInt(Digit digit)
{
    switch (digit)
    {
    case Digit::ZERO:
        return 0;
        break;
    case Digit::ONE:
        return 1;
        break;
    case Digit::TWO:
        return 2;
        break;
    case Digit::THREE:
        return 3;
        break;
    case Digit::FOUR:
        return 4;
        break;
    case Digit::FIVE:
        return 5;
        break;
    case Digit::SIX:
        return 6;
        break;
    case Digit::SEVEN:
        return 7;
        break;
    case Digit::EIGTH:
        return 8;
        break;
    case Digit::NINE:
        return 9;
        break;
    default:
        return 0; // TODO exception...
    }
}

Digit CpuRuan::intToDigit(int n)
{
    switch (n)
    {
    case 0:
        return Digit::ZERO;
        break;
    case 1:
        return Digit::ONE;
        break;
    case 2:
        return Digit::TWO;
        break;
    case 3:
        return Digit::THREE;
        break;
    case 4:
        return Digit::FOUR;
        break;
    case 5:
        return Digit::FIVE;
        break;
    case 6:
        return Digit::SIX;
        break;
    case 7:
        return Digit::SEVEN;
        break;
    case 8:
        return Digit::EIGTH;
        break;
    case 9:
        return Digit::NINE;
        break;
    default:
        return Digit::ZERO;
    }
}