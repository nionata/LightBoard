#include <FastLED.h>
#define NUM_LEDS 50
#define BRIGHTNESS 50

#define LED_PIN 5
#define TRIG_PIN
#define ECHO_PIN 

CRGBArray<NUM_LEDS> leds;

int matrix[7][7] = {
    {44, 45, 46, 47, 48, 49, 50},
    {43, 42, 41, 40, 39, 38, 37},
    {30, 31, 32, 33, 34, 35, 36},
    {29, 28, 27, 26, 25, 24, 23},
    {16, 17, 18, 19, 20, 21, 22},
    {15, 14, 13, 12, 11, 10, 9},
    {2, 3, 4, 5, 6, 7, 8}
};

void setup() { 
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); 
}

void loop() { 
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 7; j++) {
      leds[matrix[i][j] - 1] = CRGB::Blue;
    }

    FastLED.show();
    FastLED.delay(100);
    
    leds[matrix[i][i] - 1] = CRGB::White;
    leds[matrix[i][6-i] - 1] = CRGB::White;

    FastLED.show();
    FastLED.delay(100);

    leds.fadeToBlackBy(150);
  }
}

