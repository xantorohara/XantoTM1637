/**
 * This example demonstrates abilities of the XantoTM1637 library
 */
#include <XantoI2C.h>

#include <XantoTM1637.h>

const uint8_t PIN_DISPLAY_CLK = 5;
const uint8_t PIN_DISPLAY_DIO = 6;

XantoTM1637 display(PIN_DISPLAY_CLK, PIN_DISPLAY_DIO);

/**
 * Each code is a combination (0bABCDEFGH)
 * of corresponding segments:
 *   ___
 *  | A |
 *  F   B  #
 *  |_G_|  H
 *  |   |  #
 *  E   C
 *  |_D_|
 *
 */
enum TM1637_EXTRA_CODES : uint8_t {
  // Letters
  CH = 0b01101110, //H
  CJ = 0b01111000, //J
  CL = 0b00011100, //L
  CP = 0b11001110, //P
  CU = 0b01111100, //U
  Cc = 0b00011010, //c
  Ch = 0b00101110, //h
  Cn = 0b00101010, //n
  Co = 0b00111010, //o
  Cu = 0b00111000, //u

  // Borders
  Btbl = 0b10011100, //top-bottom-left borders
  Btb = 0b10010000, //top-bottom borders
  Btrb = 0b11110000, //top-right-bottom borders

  // Misc
  DEGREE = 0b11000110, //º
  UNDERSCORE = 0b00010000, // _
};

void setup() {
}

void loop() {
  testFrame();
  testControl();
  
  testFrame();
  testNumbers();
  testFrame();
  testNumbersBin();
  testFrame();
  testNumbersHex();
  testFrame();
  testLetters();
  testFrame();
  testDegrees();
  testFrame();
  testTimer();
}

void testFrame() {
  //display rectangle
  display.displayRaw(Btbl, Btb, Btb, Btrb);
  delay(1000);
}

void testDashes() {
  display.displayRaw(TM1637_CODES::MINUS, TM1637_CODES::MINUS, TM1637_CODES::MINUS, TM1637_CODES::MINUS);
  delay(1000);
}

void testControl() {
  display.displayNumber(5555);

  //increase brightness
  for (uint8_t i = 0; i <= 7; i++) {
    display.setBrightness(i);
    delay(500);
  }

  //display off
  display.off();
  delay(1000);

  //display off
  display.on();
  delay(1000);

  //restore brightness
  display.setBrightness(3);
}

void testNumbers() {

  // display 0000, 0001, 0002, .., 0009, 0010
  for (uint8_t i = 0; i <= 10; i++) {
    display.displayNumber(i);
    delay(500);
  }

  testDashes();

  // display 0, 1, 2, .., 9, 10
  for (uint8_t i = 0; i <= 10; i++) {
    display.displayNumber(i, false);
    delay(500);
  }

  testDashes();

  // display 0000, 1111, 2222, .., 9999
  for (uint8_t i = 0; i < 10; i++) {
    display.displayNumber(i * 1111);
    delay(500);
  }

  testDashes();

  // display "Err " message in case of overflow
  display.displayNumber(12345);
  delay(1000);
}

void testNumbersBin() {

  // display 0000, .., 1111
  for (uint8_t i = 0; i < 16; i++) {
    display.displayNumberBin(i);
    delay(500);
  }

  testDashes();

  // display "Err " message in case of overflow
  display.displayNumberBin(25);
  delay(1000);
}

void testNumbersHex() {

  // display 0001, 0002, .., 000F, 0010
  for (uint8_t i = 0; i <= 16; i++) {
    display.displayNumberHex(i);
    delay(500);
  }

  testDashes();

  // display 1111, 2222, .., FFFF
  for (uint8_t i = 0; i < 16; i++) {
    display.displayNumberHex(i * 0x1111);
    delay(500);
  }
}

void testLetters() {

  // display John
  display.displayRaw(CJ, Co, Ch, Cn);
  delay(1000);

  // display HoPE
  display.displayRaw(CH, Co, CP, TM1637_CODES::CE);
  delay(1000);

  // display LunA
  display.displayRaw(CL, Cu, Cn, TM1637_CODES::CA);
  delay(1000);

  // dislpay PAUL
  display.displayRaw(CP, TM1637_CODES::CA, CU, CL);
  delay(1000);
}

void testDegrees() {
  display.displayRaw(TM1637_CODES::MINUS, TM1637_CODES::C3, TM1637_CODES::C6, DEGREE);
  delay(1000);
}

void testTimer() {
  display.clear();

  // blink colon
  for (uint8_t i = 0; i < 3; i++) {
    display.displayColon(true);
    delay(500);
    display.displayColon(false);
    delay(500);
  }

  // display fast timer
  for (uint8_t i = 0; i <= 100; i++) {
    display.displayTime(i, i % 2);
    delay(250);
  }
}

