/**
   Output numbers using array of two display modules.

   Actually these modules may use the same clock line.
   So less digital pins required for a bunch of modules.
*/
#include <XantoTM1637.h>

const uint8_t PIN_DISPLAY_CLK1 = 2;
const uint8_t PIN_DISPLAY_DIO1 = 3;

const uint8_t PIN_DISPLAY_CLK2 = 4;
const uint8_t PIN_DISPLAY_DIO2 = 5;

XantoTM1637 displays[] {
  {PIN_DISPLAY_CLK1, PIN_DISPLAY_DIO1},
  {PIN_DISPLAY_CLK2, PIN_DISPLAY_DIO2}
};

void setup() {
}

int i = 0;
void loop() {
  displays[0].displayNumber(i++);
  displays[1].displayNumber(1000 + i++);
  delay(500);
}

