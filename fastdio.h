#ifndef fastdio_h
#define fastdio_h
#pragma once

#define BIT0 B1
#define BIT1 B10
#define BIT2 B100
#define BIT3 B1000
#define BIT4 B10000
#define BIT5 B100000
#define BIT6 B1000000
#define BIT7 B10000000

#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
static inline void DWMega1(uint8_t pin, bool bit){
	if(bit)
	{	
		switch(pin)
		{
			case 0: PORTE |= BIT0; return;
			case 1: PORTE |= BIT1; return;
			case 2: PORTE |= BIT4; return;
			case 3: PORTE |= BIT5; return;
			case 4: PORTG |= BIT5; return;
			case 5: PORTE |= BIT3; return;
			case 6: PORTH |= BIT3; return;
			case 7: PORTH |= BIT4; return;

			case 8: PORTH |= BIT5; return;
			case 9: PORTH |= BIT6; return;
			case 10: PORTB |= BIT4; return;
			case 11: PORTB |= BIT5; return;
			case 12: PORTB |= BIT6; return;
			case 13: PORTB |= BIT7; return;
			case 14: PORTJ |= BIT1; return;
			case 15: PORTJ |= BIT0; return;

			case 16: PORTH |= BIT1; return;
			case 17: PORTH |= BIT0; return;
			case 18: PORTD |= BIT3; return;
			case 19: PORTD |= BIT2; return;
			case 20: PORTD |= BIT1; return;
			case 21: PORTD |= BIT0; return;
			case 22: PORTA |= BIT0; return;
			case 23: PORTA |= BIT1; return;
		}
	}
	else
	{
		switch(pin)
		{
			case 0: PORTE &= ~BIT0; return;
			case 1: PORTE &= ~BIT1; return;
			case 2: PORTE &= ~BIT4; return;
			case 3: PORTE &= ~BIT5; return;
			case 4: PORTG &= ~BIT5; return;
			case 5: PORTE &= ~BIT3; return;
			case 6: PORTH &= ~BIT3; return;
			case 7: PORTH &= ~BIT4; return;

			case 8: PORTH &= ~BIT5; return;
			case 9: PORTH &= ~BIT6; return;
			case 10: PORTB &= ~BIT4; return;
			case 11: PORTB &= ~BIT5; return;
			case 12: PORTB &= ~BIT6; return;
			case 13: PORTB &= ~BIT7; return;
			case 14: PORTJ &= ~BIT1; return;
			case 15: PORTJ &= ~BIT0; return;

			case 16: PORTH &= ~BIT1; return;
			case 17: PORTH &= ~BIT0; return;
			case 18: PORTD &= ~BIT3; return;
			case 19: PORTD &= ~BIT2; return;
			case 20: PORTD &= ~BIT1; return;
			case 21: PORTD &= ~BIT0; return;
			case 22: PORTA &= ~BIT0; return;
			case 23: PORTA &= ~BIT1; return;
		}
	}
}
static inline void DWMega2(uint8_t pin, bool bit){
	if(bit)
	{	
		switch(pin)
		{
			case 24: PORTA |= BIT2; return;
			case 25: PORTA |= BIT3; return;
			case 26: PORTA |= BIT4; return;
			case 27: PORTA |= BIT5; return;
			case 28: PORTA |= BIT6; return;
			case 29: PORTA |= BIT7; return;
			case 30: PORTC |= BIT7; return;
			case 31: PORTC |= BIT6; return;
			case 32: PORTC |= BIT5; return;
			case 33: PORTC |= BIT4; return;
			case 34: PORTC |= BIT3; return;
			case 35: PORTC |= BIT2; return;
			case 36: PORTC |= BIT1; return;
			case 37: PORTC |= BIT0; return;
			case 38: PORTD |= BIT7; return;
			case 39: PORTG |= BIT2; return;
			case 40: PORTG |= BIT1; return;
			case 41: PORTG |= BIT0; return;
			case 42: PORTL |= BIT7; return;
			case 43: PORTL |= BIT6; return;
			case 44: PORTL |= BIT5; return;
			case 45: PORTL |= BIT4; return;
			case 46: PORTL |= BIT3; return;
			case 47: PORTL |= BIT2; return;
		}
	}
	else
	{
		switch(pin)
		{
			case 24: PORTA &= ~BIT2; return;
			case 25: PORTA &= ~BIT3; return;
			case 26: PORTA &= ~BIT4; return;
			case 27: PORTA &= ~BIT5; return;
			case 28: PORTA &= ~BIT6; return;
			case 29: PORTA &= ~BIT7; return;
			case 30: PORTC &= ~BIT7; return;
			case 31: PORTC &= ~BIT6; return;
			case 32: PORTC &= ~BIT5; return;
			case 33: PORTC &= ~BIT4; return;
			case 34: PORTC &= ~BIT3; return;
			case 35: PORTC &= ~BIT2; return;
			case 36: PORTC &= ~BIT1; return;
			case 37: PORTC &= ~BIT0; return;
			case 38: PORTD &= ~BIT7; return;
			case 39: PORTG &= ~BIT2; return;
			case 40: PORTG &= ~BIT1; return;
			case 41: PORTG &= ~BIT0; return;
			case 42: PORTL &= ~BIT7; return;
			case 43: PORTL &= ~BIT6; return;
			case 44: PORTL &= ~BIT5; return;
			case 45: PORTL &= ~BIT4; return;
			case 46: PORTL &= ~BIT3; return;
			case 47: PORTL &= ~BIT2; return;
		}
	}
}
static inline void DWMega3(uint8_t pin, bool bit){
	if(bit)
	{	
		switch(pin)
		{
			case 48: PORTL |= BIT1; return;
			case 49: PORTL |= BIT0; return;
			case 50: PORTB |= BIT3; return;
			case 51: PORTB |= BIT2; return;
			case 52: PORTB |= BIT1; return;
			case 53: PORTB |= BIT0; return;
			case 54: PORTF |= BIT0; return;
			case 55: PORTF |= BIT1; return;
			case 56: PORTF |= BIT2; return;
			case 57: PORTF |= BIT3; return;
			case 58: PORTF |= BIT4; return;
			case 59: PORTF |= BIT5; return;
			case 60: PORTF |= BIT6; return;
			case 61: PORTF |= BIT7; return;
			case 62: PORTK |= BIT0; return;
			case 63: PORTK |= BIT1; return;
			case 64: PORTK |= BIT2; return;
			case 65: PORTK |= BIT3; return;
			case 66: PORTK |= BIT4; return;
			case 67: PORTK |= BIT5; return;
			case 68: PORTK |= BIT6; return;
			case 69: PORTK |= BIT7; return;
		}
	}
	else
	{
		switch(pin)
		{
			case 48: PORTL &= ~BIT1; return;
			case 49: PORTL &= ~BIT0; return;
			case 50: PORTB &= ~BIT3; return;
			case 51: PORTB &= ~BIT2; return;
			case 52: PORTB &= ~BIT1; return;
			case 53: PORTB &= ~BIT0; return;
			case 54: PORTF &= ~BIT0; return;
			case 55: PORTF &= ~BIT1; return;
			case 56: PORTF &= ~BIT2; return;
			case 57: PORTF &= ~BIT3; return;
			case 58: PORTF &= ~BIT4; return;
			case 59: PORTF &= ~BIT5; return;
			case 60: PORTF &= ~BIT6; return;
			case 61: PORTF &= ~BIT7; return;
			case 62: PORTK &= ~BIT0; return;
			case 63: PORTK &= ~BIT1; return;
			case 64: PORTK &= ~BIT2; return;
			case 65: PORTK &= ~BIT3; return;
			case 66: PORTK &= ~BIT4; return;
			case 67: PORTK &= ~BIT5; return;
			case 68: PORTK &= ~BIT6; return;
			case 69: PORTK &= ~BIT7; return;
		}
	}
}

static inline bool DRMega1(uint8_t pin){
	switch(pin)
	{
		case 0: return PINE & B1;
		case 1: return PINE & B10;
		case 2: return PINE & B10000;
		case 3: return PINE & B100000;
		case 4: return PING & B100000;
		case 5: return PINE & B1000;
		case 6: return PINH & B1000;
		case 7: return PINH & B10000;
		case 8: return PINH & B100000;
		case 9: return PINH & B1000000;
		case 10: return PINB & B10000;
		case 11: return PINB & B100000;
		case 12: return PINB & B1000000;
		case 13: return PINB & B10000000;
		case 14: return PINJ & B10;
		case 15: return PINJ & B1;
		case 16: return PINH & B10;
		case 17: return PINH & B1;
		case 18: return PIND & B1000;
		case 19: return PIND & B100;
		case 20: return PIND & B10;
		case 21: return PIND & B1;
		case 22: return PINA & B1;
		case 23: return PINA & B10;
	}
}
static inline bool DRMega2(uint8_t pin){
	switch(pin)
	{
		case 24: return PINA & B100;
		case 25: return PINA & B1000;
		case 26: return PINA & B10000;
		case 27: return PINA & B100000;
		case 28: return PINA & B1000000;
		case 29: return PINA & B10000000;
		case 30: return PINC & B10000000;
		case 31: return PINC & B1000000;
		case 32: return PINC & B100000;
		case 33: return PINC & B10000;
		case 34: return PINC & B1000;
		case 35: return PINC & B100;
		case 36: return PINC & B10;
		case 37: return PINC & B1;
		case 38: return PIND & B10000000;
		case 39: return PING & B100;
		case 40: return PING & B10;
		case 41: return PING & B1;
		case 42: return PINL & B10000000;
		case 43: return PINL & B1000000;
		case 44: return PINL & B100000;
		case 45: return PINL & B10000;
		case 46: return PINL & B1000;
		case 47: return PINL & B100;
	}
}
static inline bool DRMega3(uint8_t pin){
	switch(pin)
	{
		case 48: return PINL & B10;
		case 49: return PINL & B1;
		case 50: return PINB & B1000;
		case 51: return PINB & B100;
		case 52: return PINB & B10;
		case 53: return PINB & B1;
		case 54: return PINF & B1;
		case 55: return PINF & B10;
		case 56: return PINF & B100;
		case 57: return PINF & B1000;
		case 58: return PINF & B10000;
		case 59: return PINF & B100000;
		case 60: return PINF & B1000000;
		case 61: return PINF & B10000000;
		case 62: return PINK & B1;
		case 63: return PINK & B10;
		case 64: return PINK & B100;
		case 65: return PINK & B1000;
		case 66: return PINK & B10000;
		case 67: return PINK & B100000;
		case 68: return PINK & B1000000;
		case 69: return PINK & B10000000;		
	}
}
#endif 

static inline void digitalWriteFast(uint8_t pin, bool bit)
{
	if(pin<0) return;
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) 				
	if(pin<0 || pin>21)
		return;
	if(bit)
	{
		switch(pin)
		{
			case 0:  PORTD |= B1; return;
			case 1:  PORTD |= B10; return;
			case 2:  PORTD |= B100; return;
			case 3:	 PORTD |= B1000; return;
			case 4:	 PORTD |= B10000; return;
			case 5:	 PORTD |= B100000; return;
			case 6:	 PORTD |= B1000000; return;
			case 7:	 PORTD |= B10000000; return;
			case 8:	 PORTB |= B1; return;
			case 9:	 PORTB |= B10; return;
			case 10: PORTB |= B100; return;
			case 11: PORTB |= B1000; return;
			case 12: PORTB |= B10000; return;
			case 13: PORTB |= B100000; return;
			case 14: PORTC |= B1; return;
			case 15: PORTC |= B10; return;
			case 16: PORTC |= B100; return;
			case 17: PORTC |= B1000; return;
			case 18: PORTC |= B10000; return;
			case 19: PORTC |= B100000; return;
			case 20: PORTC |= B1000000; return;
			case 21: PORTC |= B10000000; return;
		}
	}
	else
	{
		switch(pin)
		{
			case 0:  PORTD &= B11111110; return;
			case 1:  PORTD &= B11111101; return;
			case 2:  PORTD &= B11111011; return;
			case 3:  PORTD &= B11110111; return;
			case 4:  PORTD &= B11101111; return;
			case 5:  PORTD &= B11011111; return;
			case 6:  PORTD &= B10111111; return;
			case 7:  PORTD &= B01111111; return;
			case 8:  PORTB &= B11111110; return;
			case 9:  PORTB &= B11111101; return;
			case 10: PORTB &= B11111011; return;
			case 11: PORTB &= B11110111; return;
			case 12: PORTB &= B11101111; return;
			case 13: PORTB &= B11011111; return;
			case 14: PORTC &= B11111110; return;
			case 15: PORTC &= B11111101; return;
			case 16: PORTC &= B11111011; return;
			case 17: PORTC &= B11110111; return;
			case 18: PORTC &= B11101111; return;
			case 19: PORTC &= B11011111; return;
			case 20: PORTC &= B10111111; return;
			case 21: PORTC &= B01111111; return;		
		}
	}
#elif defined(__AVR_ATmega32U4__) 
	if(pin<0 || pin>23)
		return;
	if(bit)
	{
		switch(pin)
		{
			case 0:  PORTD |= B100; return;
			case 1:  PORTD |= B1000; return;
			case 2:  PORTD |= B10; return;
			case 3:  PORTD |= B1; return;
			case 4:  PORTD |= B10000; return;
			case 5:  PORTC |= B1000000; return;
			case 6:  PORTD |= B10000000; return;
			case 7:  PORTE |= B1000000; return;
			case 8:  PORTB |= B10000; return;
			case 9:  PORTB |= B100000; return;
			case 10: PORTB |= B1000000; return;
			case 11: PORTB |= B10000000; return;
			case 12: PORTD |= B1000000; return;
			case 13: PORTC |= B10000000; return;
			case 14: PORTB |= B1000; return;
			case 15: PORTB |= B10; return;
			case 16: PORTB |= B100; return;
			case 17: PORTB |= B1; return;
			case 18: PORTF |= B10000000; return;
			case 19: PORTF |= B1000000; return;
			case 20: PORTF |= B100000; return;
			case 21: PORTF |= B10000; return;
			case 22: PORTF |= B10; return;
			case 23: PORTF |= B1; return;
		}
	}
	else
	{
		switch(pin)
		{
			case 0:  PORTD &= B11111011; return;
			case 1:  PORTD &= B11110111; return;
			case 2:  PORTD &= B11111101; return;
			case 3:  PORTD &= B11111110; return;
			case 4:  PORTD &= B11101111; return;
			case 5:  PORTC &= B10111111; return;
			case 6:  PORTD &= B01111111; return;
			case 7:  PORTE &= B10111111; return;
			case 8:  PORTB &= B11101111; return;
			case 9:  PORTB &= B11011111; return;
			case 10: PORTB &= B10111111; return;
			case 11: PORTB &= B01111111; return;
			case 12: PORTD &= B10111111; return;
			case 13: PORTC &= B01111111; return;
			case 14: PORTB &= B11110111; return;
			case 15: PORTB &= B10111101; return;
			case 16: PORTB &= B11011011; return;
			case 17: PORTB &= B11111010; return;
			case 18: PORTF &= B01111111; return;
			case 19: PORTF &= B10111111; return;
			case 20: PORTF &= B11011111; return;
			case 21: PORTF &= B11101111; return;
			case 22: PORTF &= B11111101; return;
			case 23: PORTF &= B11111110; return;
		}
	}
#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
	if(pin<0 || pin>69)
		return;
	
	if(pin<24)
		DWMega1(pin,bit);
	else if(pin<48)
		DWMega2(pin,bit);
	else
		DWMega3(pin,bit);
#else
#error No support for this board.
#endif		
}

//**************************************************************
static inline bool digitalReadFast(uint8_t pin) 
{
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) 			
 if(pin<0 || pin>21)
	 return 0;

  switch(pin)
  {
	 case 0: return PIND & B1; 
	 case 1: return PIND & B10; 
	 case 2: return PIND & B100;
	 case 3: return PIND & B1000;
	 case 4: return PIND & B10000;
	 case 5: return PIND & B100000;
	 case 6: return PIND & B1000000;
	 case 7: return PIND & B10000000;
	 case 8: return PINB & B1;
	 case 9: return PINB & B10;
	 case 10: return PINB & B100;
	 case 11: return PINB & B1000;
	 case 12: return PINB & B10000;
	 case 13: return PINB & B100000;
	 case 14: return PINC & B1;
	 case 15: return PINC & B10;
	 case 16: return PINC & B100;
	 case 17: return PINC & B1000;
	 case 18: return PINC & B10000;
	 case 19: return PINC & B100000;
  }
 #elif defined(__AVR_ATmega32U4__)
 if(pin<0 || pin>23)
	 return 0;
  switch(pin)
  {
		case 0:  return PIND & B100; 
		case 1:  return PIND & B1000; 
		case 2:  return PIND & B10; 
		case 3:  return PIND & B1; 
		case 4:  return PIND & B10000;
		case 5:  return PINC & B1000000; 
		case 6:  return PIND & B10000000; 
		case 7:  return PINE & B1000000; 
		case 8:  return PINB & B10000; 
		case 9:  return PINB & B100000; 
		case 10: return PINB & B1000000; 
		case 11: return PINB & B10000000; 
		case 12: return PIND & B1000000; 
		case 13: return PINC & B10000000; 
		case 14: return PINB & B1000; 
		case 15: return PINB & B10; 
		case 16: return PINB & B100; 
		case 17: return PINB & B1; 
		case 18: return PINF & B10000000; 
		case 19: return PINF & B1000000;  
		case 20: return PINF & B100000;  
		case 21: return PINF & B10000;  
		case 22: return PINF & B10;  
		case 23: return PINF & B1;  
  }
 #elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
 if(pin<0 || pin>69)
	 return 0;
 if(pin<24)
	 return DRMega1(pin);
 else if(pin<48)
	 return DRMega2(pin);
 else
	 return DRMega3(pin);
#else
#error No support for this board.
#endif		
}
#endif