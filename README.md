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

(4) **neopixel_bright**: this will adjust the brightness levels of the NeoPixels, showing how we use math functions to control timing. Also, we introduce the concept of the preprocessor macro and the serial monitor output. 

*Try*: going to Tools->Serial Monitor to see the output of the brightness levels

Also the button down will still turn off the entire strip

*Changes*: try changing the delay value or the brightDirection variable

(5) **neopixel_3color**: this will produce 3 bands of color on the NeoPixel

*Changes*: try changing the 3 color values. why is this code "crude" in its form. is there a better way to accomplish this?

(6) **neopixel_moving1**: this will cycle through the 3 colors

*Try*: pressing the button, notice how there is a slow response — this is because we are getting locked into the delay loop

*Changes*: try changing the delay time for a faster effect

(7) **neopixel_moving2**: this will cycle through the 3 colors as above, but uses the millis() button instead of delay() to control timing, so that your button response is immediate.

(8) **neopixel_moving3**: uses the random funciton, while cycling through the colors to change the RGB color values in response to the button presses.

(9) **neopixel_gradient1**: uses math to make a gradient from white to pink

*Changes*: try changing RGB color values

(10) **neopixel_gradient2**: shows an animated gradient using math to adjust the gradient levels for each pixel.

*Changes*: try changing RGB color values

(11) **neopixel_gradient3**: shows an animated gradient using math to adjust the gradient levels for each pixel and uses a poteniometer to adjust the speed of the animation.

*Changes*: try changing the delay time for a faster or slower animation effect

(12) **neopixel_sequencer** This sketch will shows 5 different sequences and effects. A potentiometer at pin A5 will adjust the
  speed of each animation.
  
*Changes*: play with it, have fun!