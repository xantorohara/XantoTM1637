# XantoTM1637
"Digital tube" library implementation for Arduino

## Quick start
1. Download XantoI2C library: [XantoI2C-master.zip](https://github.com/xantorohara/XantoI2C/archive/master.zip)
2. Download XantoTM1637 library: [XantoTM1637-master.zip](https://github.com/xantorohara/XantoTM1637/archive/master.zip)
3. Install these libraries (for example, via Arduino IDE: Sketch -> Include Library -> Add .ZIP Library...)
3. Todo

[ ] Todo write code sample

```cpp
#include <XantoTM1637.h>

void setup() {
}

void loop() {
}
```


## About XantoTM1637
[ ] Todo write about

## Drawing
 
![Drawing](https://github.com/xantorohara/XantoTM1637/raw/master/extras/XantoTM1637-drawing.png?raw=true)

Symbol to byte code mapping table:

Symbol |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  | HEX byte code
------ | --- | --- | --- | --- | --- | --- | --- | --- | -------------
   0   |  1  |  1  |  1  |  1  |  1  |  1  |  0  |  0  |   0xFC
   1   |  0  |  1  |  1  |  0  |  0  |  0  |  0  |  0  |   0x60
   2   |  1  |  1  |  0  |  1  |  1  |  0  |  1  |  0  |   0xDA   
   3   |  1  |  1  |  1  |  1  |  0  |  0  |  1  |  0  |   0xF2   
   4   |  0  |  1  |  1  |  0  |  0  |  1  |  1  |  0  |   0x66   
   5   |  1  |  0  |  1  |  1  |  0  |  1  |  1  |  0  |   0xB6   
   6   |  1  |  0  |  1  |  1  |  1  |  1  |  1  |  0  |   0xBE   
   7   |  1  |  1  |  1  |  0  |  0  |  0  |  0  |  0  |   0xE0   
   8   |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  0  |   0xFE   
   9   |  1  |  1  |  1  |  1  |  0  |  1  |  1  |  0  |   0xF6   
   A   |  1  |  1  |  1  |  0  |  1  |  1  |  1  |  0  |   0xEE   
   b   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |   0x00   
   C   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |   0x00   
   d   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |   0x00   
   E   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |   0x00   
   F   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |   0x00   
   A   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |   0x00   
   -   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |   0x00   
 
## Class API
[ ] Todo write methods
```cpp

```

## TM1637 devices
"Digital tube" module for Arduino:

<a href="http://s.click.aliexpress.com/e/FiqN3JQfe" target="_blank">
![Digital tubes](https://github.com/xantorohara/XantoTM1637/raw/master/extras/digital-tube-blue.png?raw=true)
</a>


## Examples
- [XantoTM1637_Seconds_Counter](https://github.com/xantorohara/XantoTM1637/tree/master/examples/XantoTM1637_Seconds_Counter)
[ ] TODO write text


## Related projects
- [XantoTM1637](https://github.com/xantorohara/XantoTM1637) - a library for a "Digital Tube" (4-digit display module).
XantoI2C uses XantoI2C library for I2C communications with TM1637 chip.

  
## References
* :blue_book: [TM1637 datasheeet (English version)](http://xantorohara.github.io/datasheets/TM1637_V2.4_EN.pdf)

## Author
Xantorohara <xantorohara@gmail.com>
