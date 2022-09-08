#include "Calculator.hpp"
#include "DisplayRuan.hpp"

int main() {

    Display* d = new DisplayRuan();

    d->addDigit(Digit::ONE);
    d->addDigit(Digit::ZERO);
    d->addDigit(Digit::TWO);
    d->addDigit(Digit::TWO);

    /*calc.getKeyboard().findKey('2').press();
    calc.getKeyboard().findKey('+').press();
    calc.getKeyboard().findKey('2').press();
    calc.getKeyboard().findKey('=').press();*/

    return 0;
}