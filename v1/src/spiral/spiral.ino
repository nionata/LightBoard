#include <FastLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define LENGTH 7
#define PIN 5
#define BRIGHTNESS 255

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(LENGTH, LENGTH, PIN, 
  NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
  matrix.begin();
  matrix.setBrightness(BRIGHTNESS);
  matrix.fillScreen(CRGB::White);
}

void loop() {
//  matrix.fillScreen(0);
}
