#include "main.h"

Thread blinkThread = Thread(blink, BLINK_FREQUENCY); // Blink to see if the program is running
Thread samplingThread = Thread(samplingFunction, SAMPLING_FREQUENCY);
Thread fftThread = Thread(calculateFft, FFT_FREQUENCY);
Thread ledColorThread = Thread(updateLeds, LED_FREQUENCY);

ThreadController threadController = ThreadController();

void setup()
{
  Serial.begin(115200);

  // Init the ADC
  initAdc();

  // Init the LED strip
  initLedStrip();

  // Init threads
  threadController.add(&blinkThread);
  threadController.add(&samplingThread);
  threadController.add(&fftThread);
  threadController.add(&ledColorThread);
}


void loop()
{
  threadController.run();
}