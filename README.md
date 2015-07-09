## NeoPixel Tutorial

written by Scott Kildall

A series of Arduino Sketches to progressively show programming techniques using the NeoPixels.

### Overview
NeoPixels are RGB pixels that chainable from one to the next so you can power and program a long line of NeoPixels together to form an long string of individually addressable LEDs. One advantage is that they have one data line, so the wiring is very easy.

AdaFruit has some excellent tutorials on how to hook up the NeoPixels to the Arduino
https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library

For the sake of these tutorials, the data pin of the NeoPixel is always on pin 6.

Because of the ease-of-use, the NeoPixels are perfect for showing basic Arduino programming techniques.


### Installation
Place the "NeoPixel Samples" folder in your Arduino folder, which should be located in your documents folder.

You can load each one under the File->Sketchbook->Neopixel Samples

Also, you will want to make sure that you have the NeoPixel library from AdaFruit installed, here:

https://github.com/adafruit/Adafruit_NeoPixel

**Sketches**

Each sketch progressively builds on the previous one, so I'd suggest moving through them in order.

(1) **neopixel_basic**: this will light up your strand of NeoPixels as one color (default is blue).

*Changes*: try changing the red, green and blue variables to change to color of your NeoPixel strips

(2) **neopixel_basic_button**: this adds a button to turn the NeoPixel strip on and off. The switch is connected to pin 4. 

*Changes*: try altering the code so that pressing the button down turns the NeoPixel strip on and the default state is off.

(3) **neopixel_basic_func**: this encapsulates the code into two separate fucntions.

*Changes*: try changing the function names.

(3) **neopixel_brightness**: this will adjust the brightness levels of the NeoPixels. Also, we introduce the concept of the preprocessor macro and the serial monitor output. 

*Try*: going to Tools->Serial Monitor to see the output of the brightness levels

Also the button down will still turn off the entire strip

*Changes*: try changing the delay value or the brightDirection variable