#include <Adafruit_NeoPixel.h>
#define LED_PIN    5
#define LED_COUNT 150

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ400);

void setup() {
  strip.begin();         
  strip.show();   
  strip.setBrightness(255);
}

uint32_t blue = strip.Color(0, 255, 255);

int THEATER_ROUNDS = 5; // # of theater chases / loop
int SNAKE_ROUNDS = 1; // # of snake chases / loop
void loop() {
   tChaseController(THEATER_ROUNDS);
   sChaseController(SNAKE_ROUNDS);
}


// Theater
void tChaseController(int THEATER_ROUNDS) {
  int wait = 50;
  int sub = (wait - 1)/THEATER_ROUNDS;
  for(int i = 0; i < THEATER_ROUNDS; i++) {
    uint8_t red = rand() % 256;
    uint8_t green = rand() % 256;
    uint8_t blue = rand() % 256;
    wait -= sub; 
    
    tChaseAction(strip.Color(red, green, blue), wait);
  }
}  


void tChaseAction(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}


// Snake
void sChaseController(int SNAKE_ROUNDS) {
    int k = 8;
  for(int i = 0; i < SNAKE_ROUNDS; i++) {
      k *= k;
//    int wait = 5;
//    for(int j = 0; j < 100; j++) {
//      hue++;
      sChaseAction(strip.Color(k, 255, 255), 10);
//      
////      if (wait == 5) {
////        wait = 25; 
////      } else {
////        wait -= 5;
////      }
//    }
  }

//    static uint16_t hue;
//    sChaseAction(strip.ColorHSV(hue, 255, 255), 5);

}

void sChaseAction(uint32_t color, int wait) {
  int r = strip.numPixels();
  for(int l = 0; l < strip.numPixels()/2; l++) {
     strip.setPixelColor(l, color);
     strip.setPixelColor(r, color);
     strip.show();
     delay(wait);
     strip.fill();
     r--;
  }
}
