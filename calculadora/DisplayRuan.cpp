#include <stdio.h>

#include "DisplayRuan.hpp"

DisplayRuan::DisplayRuan() {

    console.init(0, 0);
    clear();
}

DisplayRuan::~DisplayRuan() {}

void DisplayRuan::refresh()
{
    if (signal == NEGATIVE)
        printf("-");
    else
        printf(" ");

    for (int i = 1; i <= digitCount; i++)
    {
        switch (digits[i - 1])
        {
        case ZERO:
            console.set_cursor(1, 1 + i);
            printf("0");
            break;
        case ONE:
            console.set_cursor(1, 1 + i);
            printf("1");
            break;
        case TWO:
            console.set_cursor(1, 1 + i);
            printf("2");
            break;
        case THREE:
            console.set_cursor(1, 1 + i);
            printf("3");
            break;
        case FOUR:
            console.set_cursor(1, 1 + i);
            printf("4");
            break;
        case FIVE:
            console.set_cursor(1, 1 + i);
            printf("5");
            break;
        case SIX:
            console.set_cursor(1, 1 + i);
            printf("6");
            break;
        case SEVEN:
            console.set_cursor(1, 1 + i);
            printf("7");
            break;
        case EIGTH:
            console.set_cursor(1, 1 + i);
            printf("8");
            break;
        case NINE:
            console.set_cursor(1, 1 + i);
            printf("9");
            break;
        default:
            printf("?");
            break;
        }
    }
    printf("\n");
}

void DisplayRuan::showDigits(Digit digits[], int count) {
    
    clear();
    for (int i = 0; i < count; i++) {
        addDigit(digits[i]);
    }
}

void DisplayRuan::addDigit(Digit digit)
{
    if (digitCount <= MAX_DIGITS)
    {
        digits[digitCount++] = digit;
        refresh();
    }
}

void DisplayRuan::setSignal(Signal signal)
{
    if (digitCount < 1)
        this->signal = signal;
    refresh();
}

void DisplayRuan::clear()
{
    digitCount = 0;
    signal = POSITIVE;
    console.clear_screen();
    refresh();
}