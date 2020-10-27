# Arduino-Fast-digital-I-O
Fast digital IO for Arduino AVR boards.
Using port registers.

Usage is same as with standard arduino digitalRead / digitalWrite: <br>
**bool digitalReadFast(uint8_t pin);<br>
digitalWriteFast(uint8_t pin, uint8_t val);**<br>
<br>
Speed difference:<br>
**Arduino Uno/Nano:<br>**
-------------------------
digitalWrite - 0.28M operations/s<br>
digitalWriteFast - theoretical up to 8M operations/s, tested at 7.8M

digitalRead - 0.26M/s
digitalReadFast - 15.8M/s<br><br>

**Arduino Mega** (speed depends on pin. Some pins are slower, some faster)<br>
---------------------
digitalWrite - 0.18-0.26M/s<br>
digitalWriteFast - 3.2-7.9M/s
