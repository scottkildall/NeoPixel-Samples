/********************************************************************************************************
  neopixel_gradient3:
  Written by Scott Kildall
  
  This sketch will show an animated gradient using math to adjust the gradient levels for each pixel.
  A potentiometer at analog pin 5 will control the speed of the pixels.
  
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

// variable delay time
int delayTime = 15;

// stores the start time, use unsignged long to prevent overflow
unsigned long startTime;  

int startPixel = 0;
boolean bSwitchDown = false;

int sensorPin = 5;    // select the input pin for the potentiometer

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  startTime = millis();
  activate();
  
  Serial.begin(9600);
}

// use the button asynchonously
// sensorValue will be between 0-123 (10-bit number) and we will transform this into a delayTime
void loop() {
  int sensorValue = analogRead(sensorPin);  
  delayTime = sensorValue/250;

  Serial.println(sensorValue);
  
  if( digitalRead(switchPin) == true ) {
     allOff();
     startTime = 0;
  } 
  else {
    if( startTime + delayTime < millis() ) {
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









