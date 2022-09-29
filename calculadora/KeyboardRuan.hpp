#pragma once

#include "Calculator.hpp"

#define MAX_KEYS_COUNT 25

class KeyboardRuan : public Keyboard {
    private:
        Cpu* cpu;
        Key* keys[MAX_KEYS_COUNT];
        unsigned char keyCount;
    public:
        KeyboardRuan();
        KeyboardRuan(Cpu&);
        void receiveDigit(Digit);
        void receiveOperation(Operation);
        void receiveControl(Control);
        void addKey(Key&);
        Key& findKey(char);
        void setCpu(Cpu&);
};