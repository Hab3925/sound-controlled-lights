#include "fft.h"

float vImag[NUM_SAMPLES] = {0};

float peakFrequency;

ArduinoFFT<float> FFT;
float dataCopy[NUM_SAMPLES];

void initFft(){    
    FFT = ArduinoFFT<float>(data, vImag, NUM_SAMPLES, SAMPLE_RATE);
}

void calculateFft(){
    
    for (int i = 0; i < NUM_SAMPLES; i++)
    {
        dataCopy[i] = data[i];
        vImag[i] = 0;
    }
    
    
    FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
    FFT.compute(FFTDirection::Forward);
    
    // for (int i = 0; i < NUM_SAMPLES; i++)
    // {
    //     Serial.print(vImag[i]);
    //     Serial.print(",");
    // }
    // Serial.println("next");
    
    FFT.complexToMagnitude();

    // // Find the peak frequency and amplitude
    peakFrequency = FFT.majorPeak();
    // Serial.println(peakFrequency);
}