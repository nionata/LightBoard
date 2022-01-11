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

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(50, 4, PIN, NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
}


int x    = matrix.width();
int pass = 0;

int i = 0;
void loop() {
    int j = 0;
    for (int i = 0; i < 50; i++) {
      matrix.drawLine(i, 0, i, 3, colors[j]);
      matrix.show();
      delay(5);
    
      if (j == 2) {
        j = 0;
      } else {
        j++;
      }
      
      if (i % 5 == 0) {
        matrix.fillScreen(0);
      }
    }
}

//void setup() {
//  matrix.begin();
//  matrix.setTextWrap(true);
//  matrix.setBrightness(40);
//  matrix.setTextColor(colors[0]);
//}
//
//int x    = matrix.width();
//int pass = 0;
//
//void loop() {
//  matrix.fillScreen(0);
//  matrix.setCursor(x, 0);
//  matrix.print(F("Howdy"));
//  if(--x < -36) {
//    x = matrix.width();
//    if(++pass >= 3) pass = 0;
//    matrix.setTextColor(colors[pass]);
//  }
//  matrix.show();
//  delay(100);
//}
