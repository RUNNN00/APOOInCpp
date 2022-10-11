#include <stdio.h>
#include <stdbool.h>

#include "DisplayRuan.hpp"

DisplayRuan::DisplayRuan()
{
    console.init(0, 0);
    clear();
}

DisplayRuan::~DisplayRuan() {}

void DisplayRuan::refresh()
{
    console.clear_screen();
    console.set_cursor(0, 0);
    printf("████████████\n");
    printf("█");
    console.set_color(Color::FG_Green);

    if (signal == Signal::NEGATIVE)
        printf("-");
    else
        printf(" ");

    for (int i = 0; i < digitCount; i++)
    {
        switch (digits[i])
        {
        case ZERO:
            printf("0");
            break;
        case ONE:
            printf("1");
            break;
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGTH:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        default:
            printf("?");
            break;
        }

        if (i == decimalPosition)
            printf(".");
    }
    console.reset_color();
    printf("█\n");
    printf("████████████\n");
}

void DisplayRuan::showDigits(Digit digits[], int count, int decimalPos)
{
    clear();
    for (int i = 0; i < count; i++)
    {
        if (i == decimalPos)
            setDecimal();
        addDigit(digits[i]);
    }
}

void DisplayRuan::addDigit(Digit digit)
{
    if (digitCount < MAX_DIGITS)
    {
        if (digitCount < 1 && digit == Digit::ZERO)
            return;

        digits[digitCount++] = digit;
        refresh();
    }
}

void DisplayRuan::setDecimal()
{
    if (decimalPosition == MAX_DIGITS)
    {
        if (digitCount < 1)
            digits[digitCount++] = Digit::ZERO;

        decimalPosition = digitCount - 1;
    }
}

void DisplayRuan::setSignal(Signal signal)
{
    if (digitCount < 1)
        this->signal = signal;
}

void DisplayRuan::clear()
{
    decimalPosition = MAX_DIGITS;
    digitCount = 0;
    signal = Signal::POSITIVE;
    refresh();
}