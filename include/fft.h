#ifndef FFT_H
#define FFT_H

#include <Arduino.h>
#include <arduinoFFT.h>
#include "sampling.h"

extern float peakFrequency;

void calculateFft();

// extern float f_peaks[5];

// void calculateFft();
// float FFT(int in[],int N,float Frequency);
// float sine(int i);
// float cosine(int i);


#endif // FFT_H