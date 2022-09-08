
#include "DisplayRuan.cpp"
#include "Enums.cpp"

class Key {
    public:
        void press();
        void setKeyboard(Keyboard keyboard);
};

class Keyboard {
    public:
        Key findKey(char c);        
        void receiveDigit(Digit digit);
        void setCpu(Cpu cpu);
};


class Cpu {
    public:
        void receiveDigit(Digit digit);
        void setDisplay(Display display);
};

class Calculator {
    public:
        void setDisplay(Display display);
        void setKeyboard(Keyboard keyboard);
        void setCpu(Cpu cpu);
};

int main() {

    Calculator calc;

    /*calc.getKeyboard().findKey('2').press();
    calc.getKeyboard().findKey('+').press();
    calc.getKeyboard().findKey('2').press();
    calc.getKeyboard().findKey('=').press();*/

    return 0;
}