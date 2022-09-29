#include "Calculator.hpp"
#include "KeyRuan.hpp"

// DIGIT ========================================
KeyDigitRuan::KeyDigitRuan(Digit content) {

    this->content = content;
}

void KeyDigitRuan::press() {

    keyboard->receiveDigit(content);
}

void KeyDigitRuan::setKeyboard(Keyboard& keyboard) {

    this->keyboard = &keyboard;
}

char KeyDigitRuan::getSymbol() {

    switch(content) {
        case Digit::ZERO: return '0';
        case Digit::ONE: return '1';
        case Digit::TWO: return '2';
        case Digit::THREE: return '3';
        case Digit::FOUR: return '4';
        case Digit::FIVE: return '5';
        case Digit::SIX: return '6';
        case Digit::SEVEN: return '7';
        case Digit::EIGTH: return '8';
        case Digit::NINE: return '9';
        default: return '0';
    }
}

// OPERATION ========================================
KeyOperationRuan::KeyOperationRuan(Operation content) {

    this->content = content;
}

void KeyOperationRuan::press() {

    keyboard->receiveOperation(content);
}

void KeyOperationRuan::setKeyboard(Keyboard& keyboard) {

    this->keyboard = &keyboard;
}

char KeyOperationRuan::getSymbol() {

    switch(content) {
        case Operation::ADD: return '+';
        case Operation::SUBTRACT: return '-';
        case Operation::MULTIPLY: return '*';
        case Operation::DIVIDE: return '/';
        case Operation::EQUAL: return '=';
        case Operation::NOOP: return ' ';
        default: return ' ';
    }
}

// CONTROL ========================================
KeyControlRuan::KeyControlRuan(Control content) {

    this->content = content;
}

void KeyControlRuan::press() {

    keyboard->receiveControl(content);
}

void KeyControlRuan::setKeyboard(Keyboard& keyboard) {

    this->keyboard = &keyboard;
}

char KeyControlRuan::getSymbol() {

    // TODO switch content to return ref char
}