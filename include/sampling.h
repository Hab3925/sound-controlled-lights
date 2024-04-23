#ifndef SAMPLING_H
#define SAMPLING_H

#include <Arduino.h>
#include <MCP_ADC.h>

#define ADC_CS 10
#define NUM_SAMPLES 64
#define SAMPLE_RATE 2000

extern float data[NUM_SAMPLES];  //  buffer for the data
extern float amplitude;             //  peak amplitude

void initAdc();
void samplingFunction();
void calculateAmplitude();

#endif // SAMPLING_H