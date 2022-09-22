#pragma once

#define MAX_DIGITS 8

enum Digit { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGTH, NINE };
enum Signal { POSITIVE, NEGATIVE };
enum Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE, EQUAL, NOOP };
enum Control { OFF, CLEAR, MEMORY_READ_CLEAR, MEMORY_SUBTRACTION, MEMORY_ADDITION };

class Display {
    public:
        virtual void showDigits(Digit[], int) = 0;
        virtual void addDigit(Digit) = 0;
        virtual void setSignal(Signal) = 0;
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
};*/

class Cpu {
    private:
        Display* display;
    public:
        virtual void receiveDigit(Digit) = 0;
        virtual void receiveOperation(Operation) = 0;
        virtual void setDisplay(Display&) = 0;
};

/*class Calculator {
    public:
        void setDisplay(Display display);
        void setKeyboard(Keyboard keyboard);
        void setCpu(Cpu cpu);
};*/