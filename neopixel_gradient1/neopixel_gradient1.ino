/********************************************************************************************************
  neopixel_gradient1:
  Written by Scott Kildall
  
  This sketch will show show a gradient from while to purple, using math to adjust the gradient levels.
  
---------------------------------------------------------------------------------------------------------
NeoPixel Information for initializing the strip, below
  60ma/pixel for current load
  Parameter 1 = number of pixels in strip
  Parameter 2 = pin number (most are valid)
  Parameter 3 = pixel type flags, add together as needed:
    NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

**********************************************************************************************************/

#include <Adafruit_NeoPixel.h>
 
// the data pin for the NeoPixels
int neoPixelPin = 6;

// How many NeoPixels we will be using, charge accordingly
int numPixels = 60;

// Instatiate the NeoPixel from the ibrary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

// our button
int switchPin = 4;

// initial colors, you can change these
int red = 128;
int blue = 128;
int green = 0;

// a pre-processor macro
#define DELAY_TIME (2000)

// stores the start time, use unsignged long to prevent overflow
unsigned long startTime;  

void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
  
  startTime = millis();
  activate();
}

// use the button asynchonously
void loop() {
  if( digitalRead(switchPin) == true ) {
     allOff();
     startTime = 0;
  } 
  else {
    if( startTime + DELAY_TIME < millis() ) {
       activate();
       startTime = millis();  
    }
  } 
}

void allOff() {
  for( int i = 0; i < numPixels; i++ ) {
       strip.setPixelColor(i, 0, 0, 0 );
   }
   strip.show();
}

// i is the variable that controls the green channel. it will start at 0 and in the final loop will be 236 (almost max green)
void activate() {
    for( int i = 0; i < numPixels; i++ ) {
       strip.setPixelColor(i, red, i*4, blue );
    }
      
  strip.show();
}







