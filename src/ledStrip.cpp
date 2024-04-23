#include "ledStrip.h"

CRGB leds[NUM_LEDS];

uint8_t num_active_leds = 0;

void initLedStrip() {
    FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(50);
    FastLED.clear();
    FastLED.show();
}

void updateLeds() {
    // Update the color of the LED strip based on the recorded peak frequency
    // int hue = map(peakFrequency, 0, 15000, 0, 360); // Map the peak frequency to a hue value
    // CRGB color = CHSV(hue, 255, 255); // Create a color based on the hue value
    CRGB color = CRGB::Red;

    calculateAmplitude();
    // float scaledAmplitude = log10(amplitude + 1) * (256 / log10(1024 + 1)); // +1 to avoid log(0)
    num_active_leds = map(amplitude, 0, 2048, 0, NUM_LEDS);

    // Set the color of the LED strip
    for (int i = 0; i < num_active_leds; i++) {
        leds[i] = color;
    }

    // // Turn off the remaining LEDs
    // for (int i = num_active_leds; i < NUM_LEDS; i++) {
    //     leds[i] = CRGB::Black;
    // }

    FastLED.show();
}
