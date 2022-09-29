#pragma once

#include "Calculator.hpp"

class KeyDigitRuan : public Key {
    private:
        Keyboard* keyboard;
        Digit content;
    public:
        KeyDigitRuan(Digit);
        void setContent(Digit);
        void press();
        void setKeyboard(Keyboard&);
        char getSymbol();
};

class KeyOperationRuan : public Key {
    private:
        Keyboard* keyboard;
        Operation content;
    public:
        KeyOperationRuan(Operation);
        void setContent(Operation);
        void press();
        void setKeyboard(Keyboard&);
        char getSymbol();
};

class KeyControlRuan : public Key {
    private:
        Keyboard* keyboard;
        Control content;
    public:
        KeyControlRuan(Control);
        void setContent(Control);
        void press();
        void setKeyboard(Keyboard&);
        char getSymbol();
};