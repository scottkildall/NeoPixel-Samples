/********************************************************************************************************
  neopixel_sequencer:
  Written by Scott Kildall
  
  This sketch will shows 5 different sequences and effects. A potentiometer at pin A5 will adjust the
  speed of each animation.
  
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
int blue = 255;
int green = 255;

// stores the start time, use unsignged long to prevent overflow
unsigned long startTime;  

// variable delay time
int delayTime = 20;

// start pixel, use for gradients
int startPixel = 0;

// flag for switches
boolean bSwitchDown = false;

 // for brightness 
int brightness = 255; 
int brightDirection = -10;

// modulus variable
int xmasMod = 0;

// which sequence we are using and the max # of sequences
int sequenceNum = 0;
int numSequences = 5;

int sensorPin = 5;    // select the input pin for the potentiometer


void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
  
  startTime = millis();
  activate();
  
  // seed the random number generator with whatever noise is on pin A0 (we don't have anything connected here)
  randomSeed(analogRead(0));
}

// check for switch, if down then change the sequence
// and also call activate using the asynchronous timer
void loop() {
  int sensorValue = analogRead(sensorPin);  
  delayTime = sensorValue;
  
  if( digitalRead(switchPin) == true ) {
    bSwitchDown = true;
     startTime = 0;
     delay(10);  // debounce
  } 
  else {
    if( bSwitchDown ) {
      // first release of switch
      bSwitchDown = false;  
      switchSequence(); 
    }
    
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

// switch to an new random sequence
int switchSequence() {
  int currentNum = sequenceNum;
  
  // this while loop ensures that we don't repeat the current sequence
  while( currentNum == sequenceNum ) 
    sequenceNum = random(numSequences);
    
  strip.setBrightness(brightness);  
  
  return sequenceNum;
}

// call appropiate function based on sequence number
void activate() {
    if( sequenceNum == 0 ) 
      sequenceGradient();
    else if( sequenceNum == 1 ) 
      sequenceSoloMover();
    else if( sequenceNum == 2 ) 
      sequenceBrightShift();
    else if( sequenceNum == 3 ) 
      sequenceRandom();
    else if( sequenceNum == 4 )
      sequenceXmas();
}

//---------  SEQUENCE GRADIENT FUNCITONS -------------//
void sequenceGradient() {
   int sp = startPixel;
   
   for( int i = 0; i < numPixels; i++ ) {
      strip.setPixelColor(sp, i*4, 0, blue );
      
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

//---------  SEQUENCE SOLO MOVER: a single pixel moves around the strip -------------//
void sequenceSoloMover() {
   for( int i = 0; i < numPixels; i++ ) {
     if( i == startPixel )
         strip.setPixelColor(i, 255,0,0);
     else
          strip.setPixelColor(i, 0,255,255);
   }
      
  strip.show();
  
  startPixel++;
  if( startPixel == numPixels )
    startPixel = 0;
}


//---------  SEQUENCE BRIGHT SHIFT: brightness fades up/down -------------//
void sequenceBrightShift() {
   for( int i = 0; i < numPixels; i++ ) 
     strip.setPixelColor(i, 255,0,0);
     
  strip.setBrightness(brightness);  
  strip.show();
  
  brightness = brightness + brightDirection;
  if( brightness < 0 ) {
     brightness = 0;
     brightDirection = -brightDirection;
  }
  else if( brightness > 255 ) {
     brightness = 255;
     brightDirection = -brightDirection;
  }
}

//---------  SEQUENCE RANDOM: Each pixel is a random color -------------//
void sequenceRandom() {
   for( int i = 0; i < numPixels; i++ )
     strip.setPixelColor(i, random(255), random(255) , random(255));
   
  strip.show();
}

//---------  SEQUENCE XMAS: Alternate green and red pixels -------------//
void sequenceXmas() {
   for( int i = 0; i < numPixels; i++ ) {
     if( i % 2 == xmasMod )
        strip.setPixelColor(i, 255,0,0);
     else
        strip.setPixelColor(i, 0,255,0); 
   }
   
   if( xmasMod == 0 )
     xmasMod = 1;
   else
     xmasMod = 0;
     
  strip.show();
}


