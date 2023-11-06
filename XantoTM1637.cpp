#include "XantoTM1637.h"

XantoTM1637::XantoTM1637(uint8_t clock_pin, uint8_t data_pin, uint8_t brightness):
  i2c(clock_pin, data_pin) {
  onToControl(1);
  brightnessToControl(brightness);
}

void XantoTM1637::setBrightness(uint8_t brightness) {
  brightnessToControl(brightness);
  write_i2c();
}

void XantoTM1637::brightnessToControl(uint8_t brightness) {
  if (brightness > 7) {
    brightness = 7;
  }
  bitWrite(control, 7, bitRead(brightness, 0));
  bitWrite(control, 6, bitRead(brightness, 1));
  bitWrite(control, 5, bitRead(brightness, 2));
}

void XantoTM1637::onToControl(uint8_t on) {
  bitWrite(control, 4, on != 0);
}

void XantoTM1637::on() {
  onToControl(1);
  write_i2c();
}

void XantoTM1637::off() {
  onToControl(0);
  write_i2c();
}

void XantoTM1637::digitsToSegments() {
  for (uint8_t i = 1; i < 5; i++) {
    data[i] = TM1637_DIGITS[data[i]];
  }
}

void XantoTM1637::colonToSegments(uint8_t show_colon) {
  if (show_colon) {
    bitSet(data[2], 0);
  } else {
    bitClear(data[2], 0);
  }
}

void XantoTM1637::write_i2c() {
  i2c.doStartWriteAckStop(TM1637_COMMAND1);
  i2c.doStartWriteAckStop(data, 5);
  i2c.doStartWriteAckStop(control);
}

void XantoTM1637::displayError() {
  data[1] = TM1637_CODES::CE;
  data[2] = TM1637_CODES::Cr;
  data[3] = TM1637_CODES::Cr;
  data[4] = TM1637_CODES::SPACE;
  write_i2c();
}

void XantoTM1637::displayNumber(uint16_t number, uint8_t leading_zeroes) {
  if (number > 9999) {
    displayError();
  } else {
    data[1] = number / 1000 % 10;
    data[2] = number / 100 % 10;
    data[3] = number / 10 % 10;
    data[4] = number % 10;
    digitsToSegments();

    if (!leading_zeroes) {
      if (data[1] == TM1637_CODES::C0) {
        data[1] = TM1637_CODES::SPACE;
        if (data[2] == TM1637_CODES::C0) {
          data[2] = TM1637_CODES::SPACE;
          if (data[3] == TM1637_CODES::C0) {
            data[3] = TM1637_CODES::SPACE;
          }
        }
      }
    }
    write_i2c();
  }
}

void XantoTM1637::displayNumberHex(uint16_t number) {
  data[1] = number / 4096 % 16;
  data[2] = number / 256 % 16;
  data[3] = number / 16 % 16;
  data[4] = number % 16;
  digitsToSegments();
  write_i2c();
}

void XantoTM1637::displayNumberBin(uint16_t number) {
  if (number > 0b1111) {
    displayError();
  } else {
    data[1] = bitRead(number, 3);
    data[2] = bitRead(number, 2);
    data[3] = bitRead(number, 1);
    data[4] = bitRead(number, 0);
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


void XantoTM1637::clear() {
  data[1] = TM1637_CODES::SPACE;
  data[2] = TM1637_CODES::SPACE;
  data[3] = TM1637_CODES::SPACE;
  data[4] = TM1637_CODES::SPACE;
  write_i2c();
}

