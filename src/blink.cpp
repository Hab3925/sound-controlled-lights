#include "blink.h"

bool state = false;

void blink() {
  // Blink the LED
  digitalWrite(9, !state);
  state = !state;
}