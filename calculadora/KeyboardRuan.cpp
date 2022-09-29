#include "KeyboardRuan.hpp"
#include "Calculator.hpp"

KeyboardRuan::KeyboardRuan() {}

KeyboardRuan::KeyboardRuan(Cpu& cpu) {

    setCpu(cpu);
    keyCount = 0;
}

void KeyboardRuan::receiveDigit(Digit digit) {

    cpu->receiveDigit(digit);
}

void KeyboardRuan::receiveOperation(Operation operation) {

    cpu->receiveOperation(operation);
}

void KeyboardRuan::receiveControl(Control control) {

    cpu->receiveControl(control);
}

void KeyboardRuan::addKey(Key& key) {
 
    key.setKeyboard(*this);
    keys[keyCount++] = &key;
}

Key& KeyboardRuan::findKey(char c) {

    for (int i = 0; i < keyCount; i++) {
        if (keys[i]->getSymbol() == c)
            return *(keys[i]);
    }

    throw "KEY_NOT_FOUND";
}

void KeyboardRuan::setCpu(Cpu& cpu) {

    this->cpu = &cpu;
}