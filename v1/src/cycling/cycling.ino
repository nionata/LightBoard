#include <FastLED.h>
#define NUM_LEDS 50
#define BRIGHTNESS 50

#define LED_PIN 5
#define TRIG_PIN
#define ECHO_PIN 

CRGBArray<NUM_LEDS> leds;

int matrix[7][7] = {
    {2, 3, 4, 5, 6, 7, 8},
    {15, 14, 13, 12, 11, 10, 9},
    {16, 17, 18, 19, 20, 21, 22},
    {29, 28, 27, 26, 25, 24, 23},
    {30, 31, 32, 33, 34, 35, 36},
    {43, 42, 41, 40, 39, 38, 37},
    {44, 45, 46, 47, 48, 49, 50}
};

void setup() { 
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); 
}

void loop() { 
    static uint8_t hue;
    
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(hue++, 255, 255);
      FastLED.show();
      delay(25);

      leds.fadeToBlackBy(40);
    }
}

