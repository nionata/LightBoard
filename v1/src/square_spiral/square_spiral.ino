#include <FastLED.h>

#define BRIGHTNESS 255
#define WIDTH 7
#define HEIGHT 7

#define LED_PIN 2
#define TRIG_PIN
#define ECHO_PIN 

CRGBArray<NUM_LEDS> leds;

void setup() { 
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); 
  FastLED.setBrightness(BRIGHTNESS);
 } 

//int delayCounter = 1;
void loop() { 
    


  
//  static uint8_t hue;
//  for(int i = 0; i < NUM_LEDS/2; i++) {   
//    // fade everything out
//    leds.fadeToBlackBy(50);
//
//    // let's set an led value
//    leds[i] = CHSV(hue++,255,255);
//
//    leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
//
//    FastLED.delay(delayCounter);
//  }
//
//  if (delayCounter == 0) {
//      delayCounter = 20;
//      
//  } else {
//      delayCounter -= 1;
//  }
}

 

