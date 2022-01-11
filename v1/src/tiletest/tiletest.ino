// Adafruit_NeoMatrix example for tiled NeoPixel matrices.  Scrolls
// 'Howdy' across three 10x8 NeoPixel grids that were created using
// NeoPixel 60 LEDs per meter flex strip.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

#define PIN 5

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(7, 7, PIN, NEO_TILE_BOTTOM + NEO_TILE_LEFT + NEO_TILE_ROWS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setBrightness(255);
}

int i = 0;
void loop() {
//  matrix.drawLine(0, i, 6, i, BLUE);
//
//matrix.drawPixel(2, 2, RED);
//  
//  matrix.show();
//  delay(100);
//
//  matrix.drawLine(0, i, 6, i, BLACK);
//
//  if(i == 6) {
//    i = 0;
//  } else {
//    i++;
//  }
    matrix.setCursor(0, 0);
    matrix.print("D");
    matrix.show();
}
