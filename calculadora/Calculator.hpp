#pragma once

enum Digit { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGTH, NINE };
enum Signal { POSITIVE, NEGATIVE };
enum Operator { ADD, SUBTRACT, MULTIPLY, DIVIDE };
enum Controller { EQUAL, CLEAR };

class Display {
    public:
        virtual void addDigit(Digit digit) = 0;
        virtual void setSignal(Signal signal) = 0;
        virtual void clear() = 0;
};

/*class Key {
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
};*/