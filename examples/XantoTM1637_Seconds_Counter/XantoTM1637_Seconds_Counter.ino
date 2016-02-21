/**
 * Display time in seconds with blinked colon.
 */
#include <XantoI2C.h>

#include <XantoTM1637.h>

const uint8_t PIN_DISPLAY_CLK = 5;
const uint8_t PIN_DISPLAY_DIO = 6;

XantoTM1637 display(PIN_DISPLAY_CLK, PIN_DISPLAY_DIO);

void setup() {
}

int i = 0;
void loop() {
  display.displayTime(i);
  delay(500);
  display.displayTime(i, false);
  delay(500);
  i++;
}
