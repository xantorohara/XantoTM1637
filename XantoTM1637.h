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
const uint8_t TM1637_COMMAND3 = 0x01;

/**
 * Codes for digits and symbols.
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
struct TM1637_CODES {
  enum Enum : uint8_t {
    C0 = 0b11111100, //0
    C1 = 0b01100000, //1
    C2 = 0b11011010, //2
    C3 = 0b11110010, //3
    C4 = 0b01100110, //4
    C5 = 0b10110110, //5
    C6 = 0b10111110, //6
    C7 = 0b11100000, //7
    C8 = 0b11111110, //8
    C9 = 0b11110110, //9
    //   0bABCDEFGH
    CA = 0b11101110, //A
    Cb = 0b00111110, //b
    CC = 0b10011100, //C
    Cd = 0b01111010, //d
    CE = 0b10011110, //E
    CF = 0b10001110, //F
    Cr = 0b00001010, //For "Err " message
    MINUS = 0b00000010, // -
    DEGREE = 0b11000110, // degree sign
    SPACE = 0b00000000 //All segments off
  };
};

const uint8_t TM1637_DIGITS[16] = {
  TM1637_CODES::C0,
  TM1637_CODES::C1,
  TM1637_CODES::C2,
  TM1637_CODES::C3,
  TM1637_CODES::C4,
  TM1637_CODES::C5,
  TM1637_CODES::C6,
  TM1637_CODES::C7,
  TM1637_CODES::C8,
  TM1637_CODES::C9,
  TM1637_CODES::CA,
  TM1637_CODES::Cb,
  TM1637_CODES::CC,
  TM1637_CODES::Cd,
  TM1637_CODES::CE,
  TM1637_CODES::CF,
};

class XantoTM1637 {
  private:
    XantoI2C i2c;
    uint8_t control = TM1637_COMMAND3;
    uint8_t data[5] = {TM1637_COMMAND2, 0xFE, 0xFE, 0xFE, 0xFE};
    void digitsToSegments();
    void colonToSegments(uint8_t show_colon = true);
    void onToControl(uint8_t on);
    void brightnessToControl(uint8_t brightness);
    void write_i2c();

  public:

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
};

#endif XANTO_TM1637
