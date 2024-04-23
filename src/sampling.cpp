#include "sampling.h"

MCP3201 mcp;           //  use HWSPI
float data[NUM_SAMPLES] = {0};    //  buffer for the data

int writeIndex = 0;    //  index to write the data
uint32_t lastSampleTime = 0;  //  time of the last sample

float amplitude;        //  peak amplitude

void initAdc() {
    SPI.begin();
    mcp.begin(ADC_CS);
}

void samplingFunction() {
    uint16_t val = mcp.read(0);
    int16_t adjustedVal = val - 2048; // adjust the value to be centered around 0

    // Serial.println(val);

    data[writeIndex] = (float) adjustedVal;

    // add the data to the data buffer
    if (writeIndex < NUM_SAMPLES - 1) {
        writeIndex++;
    } else {
        writeIndex = 0;
    }
}

void calculateAmplitude() {
    double sumOfSquares = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        sumOfSquares += data[i] * data[i];
    }
    amplitude = sqrt(sumOfSquares / NUM_SAMPLES);
}
