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
