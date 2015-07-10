/********************************************************************************************************
  neopixel_gradient2:
  Written by Scott Kildall
  
  This sketch will show an animated gradient using math to adjust the gradient levels for each pixel.
  
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
int red = 100;
int green = 255;

// a pre-processor macro
#define DELAY_TIME (15)

// stores the start time, use unsignged long to prevent overflow
unsigned long startTime;  

int startPixel = 0;
boolean bSwitchDown = false;

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
    bSwitchDown = true;
     allOff();
     startTime = 0;
  } 
  else {
    if( bSwitchDown )
      bSwitchDown = false;  
    
    if( startTime + DELAY_TIME < millis() ) {
       activate();
       startTime = millis();  
    }
  } 
}

void allOff() {
  strip.clear();
   strip.show();
}

// sp is a local variable that will be the actual first pixel that we write to
void activate() {
   int sp = startPixel;
   
   for( int i = 0; i < numPixels; i++ ) {
      strip.setPixelColor(sp, red, i*2, green );
      
      if( sp == numPixels )
         sp = 0;
       else
         sp++;
   }
      
  strip.show();
  
  
  startPixel++;
  if( startPixel == 60 )
    startPixel = 0;
}









