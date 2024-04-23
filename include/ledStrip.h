#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <Arduino.h>
#include <FastLED.h>
#include "fft.h"

#define NUM_LEDS 60
#define LED_PIN 7

void initLedStrip();
void updateLeds();

#endif // LEDSTRIP_H