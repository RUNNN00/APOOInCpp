#pragma once

enum Digit { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };
enum Signal { POSITIVE, NEGATIVE };
enum Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE, NOOP };
enum Control { OFF, CLEAR, MEMORY_READ_CLEAR, MEMORY_SUBTRACTION, MEMORY_ADDITION, EQUAL, DECIMAL_SEPARATOR };

class Display {
    public:
        virtual void addDigit(Digit, bool withDot = false) = 0;
        virtual void setSignal(Signal) = 0;
        virtual void clear() = 0;
};

class Cpu {
    private:
        Display* display;
    public:
        virtual void receiveDigit(Digit) = 0;
        virtual void receiveOperation(Operation) = 0;
        virtual void receiveControl(Control) = 0;
        virtual void setDisplay(Display&) = 0;
};

class Keyboard;
class Key {
    public:
        virtual void press() = 0;
        virtual void setKeyboard(Keyboard&) = 0;
        virtual char getSymbol() = 0;
};

class Keyboard {
    public:
        virtual void receiveDigit(Digit) = 0;
        virtual void receiveOperation(Operation) = 0;
        virtual void receiveControl(Control) = 0;
        virtual void addKey(Key&) = 0;
        virtual Key& findKey(char) = 0; 
        virtual void setCpu(Cpu&) = 0;
};

class Calculator {
    public:
        virtual void setDisplay(Display&) = 0;
        virtual void setKeyboard(Keyboard&) = 0;
        virtual void setCpu(Cpu&) = 0;
};