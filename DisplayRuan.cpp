#include <stdlib.h>
#include "Enums.cpp"
#include "Display.cpp"
#include "Console.hpp"

class DisplayRuan : public Display
{
private:
    Console console;

public:
    DisplayRuan(Console console) {
        this->console = console;
    }
    ~DisplayRuan() {}

    void addDigit(Digit digit)
    {
        // TODO my display
    }

    void clear() {
        console.clear_screen();
    }
};