#include "DisplayRiume.hpp"

#include <stdio.h>

void DisplayRiume::addDigit(Digit digit, bool withDot) {
  switch (digit) {
  case ZERO:
    printf("0");
    break;
  case ONE:
    printf("1");
    break;
  case TWO:
    printf("2");
    break;
  case THREE:
    printf("3");
    break;
  case FOUR:
    printf("4");
    break;
  case FIVE:
    printf("5");
    break;
  case SIX:
    printf("6");
    break;
  case SEVEN:
    printf("7");
    break;
  case EIGHT:
    printf("8");
    break;
  case NINE:
    printf("9");
    break;
  case NO_DIGIT:
    printf("");
    break;

  default:
    printf("?");
    break;
  }
  printf(withDot ? "." : "");
}
void DisplayRiume::setSignal(Signal signal) {
  if (signal == NEGATIVE)
    printf("-");
}

void DisplayRiume::clear() { printf("\n"); }