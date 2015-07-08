/********************************************************************************************************
  neopixel_basic_button:
  Written by Scott Kildall
  
  This will light just a NeoPixel strip of NeoPixels
  When the button presses, we will turn off the NeoPixel
  
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

// Global RGB values, change to suit your needs
int r = 255;
int g = 0;
int b = 255;

// pin for input
int switchPin = 4;

void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
}

void loop() {
  // Check to see if the button is down
  if( digitalRead(switchPin) == true ) {
    // if value is 0,0,0, then the pixel will be "off"
    for( int i = 0; i < numPixels; i++ ) 
       strip.setPixelColor(i, 0, 0, 0 );
  } 
  else {
    Serial.println("off");
     
     for( int i = 0; i < numPixels; i++ ) 
       strip.setPixelColor(i, r, g, b);
  } 
  
  strip.show();
  
  // delay for the purposes of debouncing the switch
  delay(10);
}
