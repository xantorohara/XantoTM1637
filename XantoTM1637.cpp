#include "XantoTM1637.h"

XantoTM1637::XantoTM1637(uint8_t clock_pin, uint8_t data_pin, uint8_t brightness):
  brightness(brightness), i2c(clock_pin, data_pin) {
}

void XantoTM1637::digitsToSegments() {
  for (uint8_t i = 1; i < 5; i++) {
    data[i] = TM1637_DIGITS[data[i]];
  }
}

void XantoTM1637::colonToSegments(uint8_t show_colon) {
  if (show_colon) {
    data[2] |= 0x80;
  } else {
    data[2] &= 0x7F;
  }
}

void XantoTM1637::write_i2c() {
  i2c.doStartWriteAckStop(TM1637_COMMAND1);
  i2c.doStartWriteAckStop(data, 5);
  i2c.doStartWriteAckStop(TM1637_COMMAND3 + brightness);
}

void XantoTM1637::displayError() {
  data[1] = TM1637_CODE::E;
  data[2] = TM1637_CODE::r;
  data[3] = TM1637_CODE::r;
  data[4] = TM1637_CODE::SPACE;
  write_i2c();
}

void XantoTM1637::displayNumber(uint16_t number) {
  if (number > 9999) {
    displayError();
  } else {
    data[1] = number / 1000 % 10;
    data[2] = number / 100 % 10;
    data[3] = number / 10 % 10;
    data[4] = number % 10;
    digitsToSegments();
    write_i2c();
  }
}

void XantoTM1637::displayNumberHex(uint16_t number) {
  if (number > 0xFFFF) {
    displayError();
  } else {
    data[1] = number / 0xFFF % 0xF;
    data[2] = number / 0xFF % 0xF;
    data[3] = number / 0xF % 0xF;
    data[4] = number % 0xF;
    digitsToSegments();
    write_i2c();
  }
}

void XantoTM1637::displayNumberBin(uint16_t number) {
  if (number > 0b1111) {
    displayError();
  } else {
    data[1] = number / 8 % 2;
    data[2] = number / 4 % 2;
    data[3] = number / 2 % 2;
    data[4] = number % 2;
    digitsToSegments();
    write_i2c();
  }
}

void XantoTM1637::displayTime(uint16_t value, uint8_t show_colon) {
  if (value > 5999) {
    displayError();
  } else {
    data[1] = value / 600 % 10;
    data[2] = value / 60 % 10;
    data[3] = value % 60 / 10;
    data[4] = value % 10;
    digitsToSegments();
    colonToSegments(show_colon);
    write_i2c();
  }
}

void XantoTM1637::displayColon(uint8_t show_colon) {
  colonToSegments(show_colon);
  write_i2c();
}

void XantoTM1637::displayRaw(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4) {
  data[1] = d1;
  data[2] = d2;
  data[3] = d3;
  data[4] = d4;
  write_i2c();
}

