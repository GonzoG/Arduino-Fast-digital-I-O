# Arduino-Fast-digital-I-O
Fast digital IO for Arduino AVR boards.
Using port registers.

Usage is same as with standard arduino digitalRead / digitalWrite:
**bool digitalReadFast(uint8_t pin);
digitalWriteFast(uint8_t pin, uint8_t val);**

Speed difference:
Arduino Uno/Nano:
digitalWrite - 280k operations / s
digitalWriteFast
