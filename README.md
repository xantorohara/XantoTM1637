# XantoTM1637
Arduino library for "Digital tube" (4-Digit LED Display based on TM1637 chip)

## Digital tube
These are typical "Digital tube" modules:

<a href="http://s.click.aliexpress.com/e/FiqN3JQfe" target="_blank">
![Digital tubes](https://github.com/xantorohara/XantoTM1637/raw/master/extras/digital-tube-blue.png?raw=true)
</a>

## Quick start
1. Download XantoI2C library: [XantoI2C-master.zip](https://github.com/xantorohara/XantoI2C/archive/master.zip)
2. Download XantoTM1637 library: [XantoTM1637-master.zip](https://github.com/xantorohara/XantoTM1637/archive/master.zip)
3. Install these libraries (for example, via Arduino IDE: Sketch -> Include Library -> Add .ZIP Library...)
4. Use it 

This sample demonstrates basic usage of the library:

```cpp
#include <XantoI2C.h>
#include <XantoTM1637.h>

const uint8_t PIN_DISPLAY_CLK = 5;
const uint8_t PIN_DISPLAY_DIO = 6;

XantoTM1637 display(PIN_DISPLAY_CLK, PIN_DISPLAY_DIO);

void setup() {
}

int i = 0;
void loop() {
  display.displayNumber(i++);
  delay(500);
}

```


## About XantoTM1637

Another one library for TM1637 chip with these points: 

* Display numbers in different formats: decimal, hexadecimal, binary
* Display time (seconds or minutes) using mm:ss or hh:mm formats
* Display raw segments
* Brightness control
* Display ON/OFF
* Software I2C layer, so it is possible to use multiple devices at one time

## Drawing
 
![Drawing](https://github.com/xantorohara/XantoTM1637/raw/master/extras/XantoTM1637-drawing.png?raw=true)

###Symbol-to-code mapping table
In the table below columns A,B,C,D,E,F,G,H corresponds to the drawing above.

Symbol |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H 
------ | --- | --- | --- | --- | --- | --- | --- | ---
   0   |  1  |  1  |  1  |  1  |  1  |  1  |  0  |  0 
   1   |  0  |  1  |  1  |  0  |  0  |  0  |  0  |  0 
   2   |  1  |  1  |  0  |  1  |  1  |  0  |  1  |  0 
   3   |  1  |  1  |  1  |  1  |  0  |  0  |  1  |  0 
   4   |  0  |  1  |  1  |  0  |  0  |  1  |  1  |  0 
   5   |  1  |  0  |  1  |  1  |  0  |  1  |  1  |  0 
   6   |  1  |  0  |  1  |  1  |  1  |  1  |  1  |  0 
   7   |  1  |  1  |  1  |  0  |  0  |  0  |  0  |  0 
   8   |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  0 
   9   |  1  |  1  |  1  |  1  |  0  |  1  |  1  |  0 
   A   |  1  |  1  |  1  |  0  |  1  |  1  |  1  |  0 
   b   |  0  |  0  |  1  |  1  |  1  |  1  |  1  |  0 
   C   |  1  |  0  |  0  |  1  |  1  |  1  |  0  |  0 
   d   |  0  |  1  |  1  |  1  |  1  |  0  |  1  |  0 
   E   |  1  |  0  |  0  |  1  |  1  |  1  |  1  |  0 
   F   |  1  |  0  |  0  |  0  |  1  |  1  |  1  |  0 
       |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0 
   -   |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  0
   °   |  1  |  1  |  0  |  0  |  0  |  1  |  1  |  0
   
* "Digital tube" (like in the picture below) has only one place decimal point - between digits 2 and 3.
So, in order to show this decimal point just set H bit to 1 for digit 2.
 
## Class API

```cpp
/**
 * Create a new instance of the XantoTM1637
 * clock_pin - any digital pin for SCL (CLK) line
 * data_pin - any digital pin for SDA (DIO) line
 */
XantoTM1637(uint8_t clock_pin, uint8_t data_pin, uint8_t brightness = 3);

/**
 * Switch the display on
 */
void on();

/**
 * Switch the display off
 */
void off();

/**
 * Set display brightness.
 * Min brightness: 0
 * Max brightness: 7
 */
void setBrightness(uint8_t brightness);

/**
 * Display decimal number.
 * Max value: 9999
 */
void displayNumber(uint16_t number, uint8_t leading_zeroes = true);

/**
 * Display hexadecimal number.
 * Max value: 65535 (0xFFFF)
 */
void displayNumberHex(uint16_t number);

/**
 * Display binary number.
 * Max value: 15 (0b1111)
 */
void displayNumberBin(uint16_t number);

/**
* Display time:
* - in seconds using seconds and "mm:ss" format
* - in minutes using minutes and "hh:mm" format
* Min value: 0 ("00:00")
* Max value: 5999 ("99:59")
*/
void displayTime(uint16_t value, uint8_t show_colon = true);

/**
 * Display colon (":") symbol between 2nd and 3rd digits
 */
void displayColon(uint8_t show_colon);

/**
 * Display raw segments (codes from TM1637_CODE enum or your own)
 */
void displayRaw(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4);

/**
 * Display "Err " word.
 */
void displayError();

/**
 * Clear the display
 */
void clear();    
```

## Examples
* [XantoTM1637_Demo](https://github.com/xantorohara/XantoTM1637/tree/master/examples/XantoTM1637_Demo) -
demonstrates abilities of the library

* [XantoTM1637_Seconds_Counter](https://github.com/xantorohara/XantoTM1637/tree/master/examples/XantoTM1637_Seconds_Counter) -
just displays time in seconds

## Related projects
* [XantoI2C](https://github.com/xantorohara/XantoI2C) - 
XantoTM1637 uses XantoI2C library for I2C communications with a TM1637 chip.

* [LED matrix 8x8 online editor] (https://github.com/xantorohara/led-matrix-editor) -
online tool for editing and creating animations for LED matrices.
  
## References
* :blue_book: [TM1637 datasheet (English version)](http://xantorohara.github.io/datasheets/TM1637_V2.4_EN.pdf)

## Author
Xantorohara <xantorohara@gmail.com>
