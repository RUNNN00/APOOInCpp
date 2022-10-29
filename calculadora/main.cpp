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
   display.addDigit(ZERO, true);
   display.addDigit(ONE, true);
   display.addDigit(TWO);
   display.addDigit(THREE);
   display.addDigit(ZERO);
   display.addDigit(FOUR);
   display.addDigit(FIVE);
   display.addDigit(ONE);
   display.addDigit(ONE);
   display.addDigit(ONE);
   display.addDigit(TWO);
}

void testCpu(Cpu& cpu) {

  //cpu.receiveDigit(ZERO);
  //cpu.receiveDigit(ZERO);
  //cpu.receiveOperation(SUBTRACT);
  //cpu.receiveDigit(TWO);
  //cpu.setDecimal();
  cpu.receiveDigit(ONE);

  cpu.receiveOperation(ADD);
  //cpu.receiveOperation(SUBTRACT);

  //cpu.setDecimal();
  cpu.receiveDigit(FIVE);
  //cpu.receiveDigit(SIX);
  //cpu.receiveOperation(SUBTRACT);
  cpu.receiveDigit(FOUR);
  cpu.receiveDigit(ONE);

  cpu.receiveControl(EQUAL);
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
  CpuRuan cpu{display};
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

  /* Fase de construção/ligação */
  keyboard.addKey(zero);
  keyboard.addKey(one);
  keyboard.addKey(addition);

  /* Fase de testes */
  //testKeyboard(keyboard);
  testDisplay(display);
  //testCpu(cpu);
}