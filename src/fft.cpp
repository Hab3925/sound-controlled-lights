#include "fft.h"

float vImag[NUM_SAMPLES] = {0};

float peakFrequency;

ArduinoFFT<float> FFT = ArduinoFFT<float>(data, vImag, NUM_SAMPLES, SAMPLE_RATE);

void calculateFft(){
    Serial.println("Calculating FFT");
    FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
    FFT.compute(FFTDirection::Forward);
    FFT.complexToMagnitude();

    // Find the peak frequency and amplitude
    peakFrequency = FFT.majorPeak();
    Serial.println(peakFrequency);
}