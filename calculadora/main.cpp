#include "Calculator.hpp"
#include "DisplayRuan.hpp"
#include "CpuRuan.hpp"

void testDisplay(Display& display){
   display.setSignal(NEGATIVE);
   display.addDigit(ZERO);
   display.clear();
   display.addDigit(ZERO);
   display.addDigit(ZERO);
   display.addDigit(ONE);
   display.addDigit(TWO);
   display.addDigit(THREE);
   display.addDigit(FOUR);
   display.addDigit(FIVE);
   display.addDigit(ZERO);
   display.addDigit(ONE);
}

void testCpu(Cpu& cpu){
  //cpu.receiveDigit(ONE);
  cpu.receiveDigit(TWO);
  //cpu.receiveDigit(THREE);
  cpu.receiveOperation(ADD);
  cpu.receiveDigit(FOUR);
  //cpu.receiveDigit(FIVE);
  //cpu.receiveDigit(SIX);
  cpu.receiveOperation(EQUAL);  
}


int main(){
  /* Fase de criação */
  /* Instancie suas implementações aqui */
  DisplayRuan d1;
  CpuRuan c1;

  /* Fase de construção/ligação */
  c1.setDisplay(d1);

  /* Fase de testes */
  //testDisplay(d1);
  testCpu(c1);

}