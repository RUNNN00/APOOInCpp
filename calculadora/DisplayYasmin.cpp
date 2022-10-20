#include "DisplayYasmin.hpp"
#include <iostream>
#include <stdio.h>

void DisplayYasmin::refresh() {
  console.set_color(Color::FG_White);
  console.clear_screen();

  switch (signal) {
  case NEGATIVE:
    this->showDigitShape("    ", "    ", "▬▬▬▬", "    ", "    ", 0);

    break;
  case POSITIVE:
    this->showDigitShape("    ", "   ", "    ", "    ", "    ", 0);
    break;

  default:
    break;
  }

  for (int i = 1; i <= this->counter; i++) {
    switch (this->digits[i - 1]) {
    case ZERO:
      this->showDigitShape("████", "█  █", "█  █", "█  █", "████", i);
      break;
    case ONE:
      this->showDigitShape("  █ ", " ██ ", "  █ ", "  █ ", "████", i);
      break;
    case TWO:
      this->showDigitShape("████", "  ██", "████", "██ ", "████", i);
      break;
    case THREE:
      this->showDigitShape("████", "   █", " ███", "   █", "████", i);
      break;
    case FOUR:
      this->showDigitShape("█  █", "█  █", "████", "   █", "   █", i);
      break;
    case FIVE:
      this->showDigitShape("████", "█   ", "████", "   █", "████", i);
      break;
    case SIX:
      this->showDigitShape("████", "█   ", "████", "█  █", "████", i);
      break;
    case SEVEN:
      this->showDigitShape("████", "   █", "  █ ", " █  ", "█   ", i);
      break;
    case EIGTH:
      this->showDigitShape("████", "█  █", "████", "█  █", "████", i);
      break;
    case NINE:
      this->showDigitShape("████", "█  █", "████", "   █", "   █", i);
      break;

    default:
      break;
    }
  }
}

DisplayYasmin::DisplayYasmin() {
  this->console.init(0, 0);
  this->clear();
}

void DisplayYasmin::showDigitShape(const char *line1, const char *line2,
                                   const char *line3, const char *line4,
                                   const char *line5, unsigned char column) {
  this->console.set_cursor(1, 1 + column * 5);
  printf(line1);
  this->console.set_cursor(2, 1 + column * 5);
  printf(line2);
  this->console.set_cursor(3, 1 + column * 5);
  printf(line3);
  this->console.set_cursor(4, 1 + column * 5);
  printf(line4);
  this->console.set_cursor(5, 1 + column * 5);
  printf(line5);
}

void DisplayYasmin::addDigit(Digit digit, bool withDot) {
  // char c;
  if (this->counter < MAX_DIGITS) {
    std::cout<< "counter" << this->counter ;
    digits[this->counter++] = digit;
    this->refresh();
  }
}

void DisplayYasmin::setDecimalSeparator() {
  this->decimalCounter++;
  if (this->decimalCounter == 1) {
    std::cout << "∎";
  }
}

void DisplayYasmin::setSignal(Signal signal) {
  this->signal = signal;
  this->refresh();
}

void DisplayYasmin::clear() {
  this->counter = 0;
  this->decimalCounter = 0;
  this->signal = POSITIVE;
  this->refresh();
}