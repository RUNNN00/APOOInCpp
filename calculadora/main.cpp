#include <iostream>

#include "Calculator.hpp"
#include "DisplayRuan.hpp"
#include "CpuRuan.hpp"
#include "KeyboardRuan.hpp"
#include "KeyRuan.hpp"

void testDisplay(Display& display) {
   
   display.setSignal(NEGATIVE);
   display.addDigit(ZERO);
   display.clear();
   display.addDigit(ZERO);
   display.addDigit(ZERO);
   display.addDigit(ONE);
   display.setDecimal();
   display.addDigit(TWO);
   display.addDigit(THREE);
   display.addDigit(ZERO);
   display.setDecimal();
   display.addDigit(FOUR);
   display.addDigit(FIVE);
   display.addDigit(ONE);
   display.addDigit(ONE);
   display.addDigit(ONE);
   display.addDigit(TWO);
}

void testCpu(Cpu& cpu) {

  cpu.receiveDigit(ONE);
  cpu.receiveDigit(TWO);
  cpu.receiveDigit(THREE);

  cpu.receiveOperation(ADD);

  cpu.receiveDigit(FOUR);
  cpu.receiveDigit(FIVE);
  cpu.receiveDigit(SIX);

  cpu.receiveOperation(EQUAL);  
}

void testKeyboard(Keyboard& keyboard) {

    try {
      keyboard.findKey('1').press();
      keyboard.findKey('+').press();
      keyboard.findKey('1').press();
      keyboard.findKey('=').press();
    }
    catch (const char* exception) {
      std::cerr << exception;
    }
}


int main(){
  /* Fase de criação */
  DisplayRuan display;
  /*CpuRuan cpu{display};
  KeyboardRuan keyboard{cpu};

  KeyDigitRuan zero{Digit::ZERO};
  KeyDigitRuan one{Digit::ONE};
  KeyDigitRuan two{Digit::TWO};
  KeyDigitRuan three{Digit::THREE};
  KeyDigitRuan four{Digit::FOUR};
  KeyDigitRuan five{Digit::FIVE};
  KeyDigitRuan six{Digit::SIX};
  KeyDigitRuan seven{Digit::SEVEN};
  KeyDigitRuan eigth{Digit::EIGTH};
  KeyDigitRuan nine{Digit::NINE};

  KeyOperationRuan addition{Operation::ADD};
  KeyOperationRuan subtraction{Operation::SUBTRACT};
  KeyOperationRuan multiplication{Operation::MULTIPLY};
  KeyOperationRuan divide{Operation::DIVIDE};
  KeyOperationRuan equal{Operation::EQUAL};

  /* Fase de construção/ligação */
  /*keyboard.addKey(zero);
  keyboard.addKey(one);
  keyboard.addKey(addition);
  keyboard.addKey(equal);

  /* Fase de testes */
  //testKeyboard(keyboard);
  testDisplay(display);
}