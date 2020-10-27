# Arduino-Fast-digital-I-O
Fast digital IO for Arduino AVR boards.
Using port registers.

Usage is same as with standard arduino digitalRead / digitalWrite: <br>
**bool digitalReadFast(uint8_t pin);<br>
digitalWriteFast(uint8_t pin, uint8_t val);**<br>
<br>
Speed difference:<br>
Arduino Uno/Nano:<br>
digitalWrite - 280k operations/s<br>
digitalWriteFast - about 7800k operations/s
