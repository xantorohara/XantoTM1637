#include <XantoI2C.h>

#include "XantoTM1637.h"

const uint8_t PIN_DISPLAY_CLK = 8;
const uint8_t PIN_DISPLAY_DIO = 9;

XantoTM1637 display(PIN_DISPLAY_CLK, PIN_DISPLAY_DIO);

void setup() {
  testFrame();
  testNumberHex();
  testFrame();
  testLetters();

}

void testFrame() {
  display.displayRaw(TM1637_CODE::Btbl, TM1637_CODE::Btb, TM1637_CODE::Btb, TM1637_CODE::Btrb);
  delay(1000);
}

void testLetters() {
  display.displayRaw(TM1637_CODE::A, TM1637_CODE::b, TM1637_CODE::C, TM1637_CODE::c);
  delay(500);
  display.displayRaw(TM1637_CODE::d, TM1637_CODE::F, TM1637_CODE::J, TM1637_CODE::H);
  delay(500);

}
void testNumberHex() {
  for (int i = 0; i < 16; i++) {
    display.displayNumberHex(i);
    delay(500);
  }

  display.displayNumberHex(0x1111);
  delay(500);

  display.displayNumberHex(0xFFFF);
  delay(500);

}

int i = 0;
void loop() {
  display.displayTime(i);
  delay(500);
  i++;
}
