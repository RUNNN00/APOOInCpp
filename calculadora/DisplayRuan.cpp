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
    console.set_color(Color::FG_Green);

    if (signal == Signal::NEGATIVE)
        printf(" ▃▃ ");
    else
        printf("    ");

    for (int i = 0; i < digitCount; i++) {
        switch (digits[i]) {
        case ZERO:
            showDigitShape("████",
                            "█  █",
                            "█  █",
                            "████", i);
            break;
        case ONE:
            showDigitShape("  █ ",
                           " ██ ",
                           "  █ ",
                           "████", i);
            break;
        case TWO:
            showDigitShape("████",
                           "  ▄█",
                           "█▀  ",
                           "████", i);
            break;
        case THREE:
            showDigitShape("▀▀▀█",
                           " ▄█ ",
                           "   █",
                           "████", i);
            break;
        case FOUR:
            showDigitShape(" █ █",
                           " █ █",
                           "████",
                           "   █", i);
            break;
        case FIVE:
            showDigitShape("████",
                           "█   ",
                           " ▀▀█",
                           "████", i);
            break;
        case SIX:
            showDigitShape(" ███",
                           "█   ",
                           "█▀▀█",
                           "████", i);
            break;
        case SEVEN:
            showDigitShape("████",
                           "   █",
                           " ██ ",
                           "█   ", i);
            break;
        case EIGTH:
            showDigitShape("████",
                           "█▄▄█",
                           "█  █",
                           "████", i);
            break;
        case NINE:
            showDigitShape("████",
                           "█▄▄█",
                           "   █",
                           "███ ", i);
            break;
        default:
            showDigitShape("█  █",
                           " ██ ",
                           " █  ",
                           "█  █", i);
            break;
        }
    }
    console.reset_color();
    printf("\n");
}

void DisplayRuan::showDigitShape(const char * line1, const char * line2, const char * line3, const char * line4, unsigned char column){
    console.set_cursor(1, (MAX_DIGITS - digitCount + 1 + column) * 6);printf(line1);
    console.set_cursor(2, (MAX_DIGITS - digitCount + 1 + column) * 6);printf(line2);
    console.set_cursor(3, (MAX_DIGITS - digitCount + 1 + column) * 6);printf(line3);
    console.set_cursor(4, (MAX_DIGITS - digitCount + 1 + column) * 6);printf(line4);

    if (decimalPosition == column) {
        console.set_cursor(4, (MAX_DIGITS - digitCount + 1 + column) * 6 + 4);
        printf("▗");
    }
}

void DisplayRuan::addDigit(Digit digit, bool withDot)
{
    if (digitCount < MAX_DIGITS) {
        digits[digitCount] = digit;

        if (withDot)
            decimalPosition = digitCount;

        digitCount++;
    }
    
    refresh();
}

void DisplayRuan::setSignal(Signal signal)
{
    this->signal = signal;
}

void DisplayRuan::clear()
{
    decimalPosition = MAX_DIGITS;
    digitCount = 0;
    signal = Signal::POSITIVE;
    refresh();
}