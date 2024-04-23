#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>

#include <Thread.h>
#include <ThreadController.h>

#include "blink.h"
#include "sampling.h"
#include "ledStrip.h"
#include "fft.h"

#define BLINK_FREQUENCY 1000000 / 1                 // 1 Hz
#define SAMPLING_FREQUENCY 1000000 / SAMPLE_RATE
#define LED_FREQUENCY 1000000 / 25                  // 25 Hz
#define FFT_FREQUENCY 1000000 / 25                  // 25 Hz

#endif // MAIN_H