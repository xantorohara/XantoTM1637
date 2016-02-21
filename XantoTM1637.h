/**
 * XantoTM1637
 * Arduino library for "Digital tube" (4-Digit LED Display based on TM1637 chip)
 *
 * Version: 1.0.1
 * Author: Xantorohara <xantorohara@gmail.com>
 *
 * Requires: XantoI2C library
 *
 * References:
 * - TM1637 datasheet http://xantorohara.github.io/datasheets/TM1637_V2.4_EN.pdf
 *
 */

#ifndef XANTO_TM1637
#define XANTO_TM1637

#include <Arduino.h>
#include <XantoI2C.h>

const uint8_t TM1637_COMMAND1 = 0x02;
const uint8_t TM1637_COMMAND2 = 0x03;
const uint8_t TM1637_COMMAND3 = 0xF1;

/**
 * Codes for some chars
 */
struct TM1637_CODE {
  enum Enum : uint8_t {
    // Decimal digits
    D0 = 0xFC, //0
    D1 = 0x60, //1
    D2 = 0xDA, //2
    D3 = 0xF2, //3
    D4 = 0x66, //4
    D5 = 0xB6, //5
    D6 = 0xBE, //6
    D7 = 0xE0, //7
    D8 = 0xFE, //8
    D9 = 0xF6, //9

    //Letters
    A = 0xFF,
    b = 0xFF,
    C = 0xFF,
    c = 0xFF,
    d = 0xFF,
    E = 0xFF,
    F = 0xFF,
    J = 0xFF,
    H = 0xFF,
    h = 0xFF,
    L = 0xFF,
    n = 0xFF,
    o = 0xFF,
    P = 0xFF,
    q = 0xFF,
    r = 0xFF,
    U = 0xFF,
    u = 0xFF,

    //Borders
    Btbl = 0xFF, //top-bottom-left borders
    Btb = 0xFF, //top-bottom borders
    Btrb = 0xFF, //top-right-bottom borders

    //Other,
    MINUS = 0x00,
    SPACE = 0x00 // all segments off
  };
};

const uint8_t TM1637_DIGITS[16] = {
  TM1637_CODE::D0,
  TM1637_CODE::D1,
  TM1637_CODE::D2,
  TM1637_CODE::D3,
  TM1637_CODE::D4,
  TM1637_CODE::D5,
  TM1637_CODE::D6,
  TM1637_CODE::D7,
  TM1637_CODE::D8,
  TM1637_CODE::D9,
  TM1637_CODE::A,
  TM1637_CODE::b,
  TM1637_CODE::C,
  TM1637_CODE::d,
  TM1637_CODE::E,
  TM1637_CODE::F,
};

class XantoTM1637 {
  private:
    XantoI2C i2c;
    uint8_t brightness;
    uint8_t data[5] = {TM1637_COMMAND2, 0xFE, 0xFE, 0xFE, 0xFE};

    void digitsToSegments();
    void colonToSegments(uint8_t show_colon = true);

    void write_i2c();

  public:
    XantoTM1637(uint8_t clock_pin, uint8_t data_pin, uint8_t brightness = 3);

    /**
     * Display decimal number.
     * Max value: 9999
     */
    void displayNumber(uint16_t number);

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
};

#endif XANTO_TM1637
