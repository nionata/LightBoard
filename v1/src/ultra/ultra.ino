#include <FastLED.h>
#define NUM_LEDS 50
#define BRIGHTNESS 50

#define LED_PIN 5
#define TRIG_PIN 11
#define ECHO_PIN 12
long duration, cm, inches;


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

  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.print("shetup");
}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert the time into a distance
  cm = (duration / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inches = (duration / 2) / 74; // Divide by 74 or multiply by 0.0135

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();


  for (int i = 0; i < NUM_LEDS; i++) {
//    Serial.println(i);
    leds[i] = CRGB::White;
  }
  
//  FastLED.setBrightness(inches%255);
  FastLED.show();
  delay(100);

  leds.fadeToBlackBy(75);
}

