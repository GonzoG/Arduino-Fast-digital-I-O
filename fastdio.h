static inline void digitalWriteFast(uint8_t pin, bool bit)
{
	if(bit)
	{
		switch(pin)
		{
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) 			
		case 0:  PORTD |= B1; break;
		case 1:  PORTD |= B10; break;
		case 2:  PORTD |= B100; break;
		case 3:	 PORTD |= B1000; break;
		case 4:	 PORTD |= B10000; break;
		case 5:	 PORTD |= B100000; break;
		case 6:	 PORTD |= B1000000; break;
		case 7:	 PORTD |= B10000000; break;
		case 8:	 PORTB |= B1; break;
		case 9:	 PORTB |= B10; break;
		case 10: PORTB |= B100; break;
		case 11: PORTB |= B1000; break;
		case 12: PORTB |= B10000; break;
		case 13: PORTB |= B100000; break;
		case 14: PORTC |= B1; break;
		case 15: PORTC |= B10; break;
		case 16: PORTC |= B100; break;
		case 17: PORTC |= B1000; break;
		case 18: PORTC |= B10000; break;
		case 19: PORTC |= B100000; break;
		case 20: PORTC |= B1000000; break;
		case 21: PORTC |= B10000000; break;
#elif defined(__AVR_ATmega32U4__) 
		case 0:  PORTD |= B100; break;
		case 1:  PORTD |= B1000; break;
		case 2:  PORTD |= B10; break;
		case 3:  PORTD |= B1; break;
		case 4:  PORTD |= B10000; break;
		case 5:  PORTC |= B1000000; break;
		case 6:  PORTD |= B10000000; break;
		case 7:  PORTE |= B1000000; break;
		case 8:  PORTB |= B10000; break;
		case 9:  PORTB |= B100000; break;
		case 10: PORTB |= B1000000; break;
		case 11: PORTB |= B10000000; break;
		case 12: PORTD |= B1000000; break;
		case 13: PORTC |= B10000000; break;
		case 14: PORTF |= B10000000; break;
		case 15: PORTF |= B1000000; break;
		case 16: PORTF |= B100000; break;
		case 17: PORTF |= B10000; break;
		case 18: PORTF |= B10; break;
		case 19: PORTF |= B1; break;
#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
		case 0: PORTE |= B1; break;
		case 1: PORTE |= B10; break;
		case 2: PORTE |= B10000; break;
		case 3: PORTE |= B100000; break;
		case 4: PORTG |= B100000; break;
		case 5: PORTE |= B1000; break;
		case 6: PORTH |= B1000; break;
		case 7: PORTH |= B10000; break;

		case 8: PORTH |= B100000; break;
		case 9: PORTH |= B1000000; break;
		case 10: PORTB |= B10000; break;
		case 11: PORTB |= B100000; break;
		case 12: PORTB |= B1000000; break;
		case 13: PORTB |= B10000000; break;

		case 14: PORTJ |= B10; break;
		case 15: PORTJ |= B1; break;
		case 16: PORTH |= B10; break;
		case 17: PORTH |= B1; break;
		case 18: PORTD |= B1000; break;
		case 19: PORTD |= B100; break;
		case 20: PORTD |= B10; break;
		case 21: PORTD |= B1; break;

		case 22: PORTA |= B1; break;
		case 23: PORTA |= B10; break;
		case 24: PORTA |= B100; break;
		case 25: PORTA |= B1000; break;
		case 26: PORTA |= B10000; break;
		case 27: PORTA |= B100000; break;
		case 28: PORTA |= B1000000; break;
		case 29: PORTA |= B10000000; break;

		case 30: PORTC |= B10000000; break;
		case 31: PORTC |= B1000000; break;
		case 32: PORTC |= B100000; break;
		case 33: PORTC |= B10000; break;
		case 34: PORTC |= B1000; break;
		case 35: PORTC |= B100; break;
		case 36: PORTC |= B10; break;
		case 37: PORTC |= B1; break;

		case 38: PORTD |= B10000000; break;
		case 39: PORTG |= B100; break;
		case 40: PORTG |= B10; break;
		case 41: PORTG |= B1; break;
		case 42: PORTL |= B10000000; break;
		case 43: PORTL |= B1000000; break;
		case 44: PORTL |= B100000; break;
		case 45: PORTL |= B10000; break;

		case 46: PORTL |= B1000; break;
		case 47: PORTL |= B100; break;
		case 48: PORTL |= B10; break;
		case 49: PORTL |= B1; break;
		case 50: PORTB |= B1000; break;
		case 51: PORTB |= B100; break;
		case 52: PORTB |= B10; break;
		case 53: PORTB |= B1; break;
#else
#error No support for this board.
#endif		
		}
	}else
	{
		switch(pin)
		{
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) 			
		case 0:  PORTD &= B11111110; break;
		case 1:  PORTD &= B11111101; break;
		case 2:  PORTD &= B11111011; break;
		case 3:  PORTD &= B11110111; break;
		case 4:  PORTD &= B11101111; break;
		case 5:  PORTD &= B11011111; break;
		case 6:  PORTD &= B10111111; break;
		case 7:  PORTD &= B01111111; break;
		case 8:  PORTB &= B11111110; break;
		case 9:  PORTB &= B11111101; break;
		case 10: PORTB &= B11111011; break;
		case 11: PORTB &= B11110111; break;
		case 12: PORTB &= B11101111; break;
		case 13: PORTB &= B11011111; break;
		case 14: PORTC &= B11111110; break;
		case 15: PORTC &= B11111101; break;
		case 16: PORTC &= B11111011; break;
		case 17: PORTC &= B11110111; break;
		case 18: PORTC &= B11101111; break;
		case 19: PORTC &= B11011111; break;
		case 20: PORTC &= B10111111; break;
		case 21: PORTC &= B01111111; break;
#elif defined(__AVR_ATmega32U4__) 
		case 0:  PORTD &= B11111011; break;
		case 1:  PORTD &= B11110111; break;
		case 2:  PORTD &= B11111101; break;
		case 3:  PORTD &= B11111110; break;
		case 4:  PORTD &= B11101111; break;
		case 5:  PORTC &= B10111111; break;
		case 6:  PORTD &= B01111111; break;
		case 7:  PORTE &= B10111111; break;
		case 8:  PORTB &= B11101111; break;
		case 9:  PORTB &= B11011111; break;
		case 10: PORTB &= B10111111; break;
		case 11: PORTB &= B01111111; break;
		case 12: PORTD &= B10111111; break;
		case 13: PORTC &= B01111111; break;
		case 14: PORTF &= B01111111; break;
		case 15: PORTF &= B10111111; break;
		case 16: PORTF &= B11011111; break;
		case 17: PORTF &= B11101111; break;
		case 18: PORTF &= B11111101; break;
		case 19: PORTF &= B11111110; break;
#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
		case 0:  PORTE &= B11111110; break;
		case 1:  PORTE &= B11111101; break;
		case 2:  PORTE &= B11101111; break;
		case 3:  PORTE &= B11011111; break;
		case 4:  PORTG &= B11011111; break;
		case 5:  PORTE &= B11110111; break;
		case 6:  PORTH &= B11110111; break;
		case 7:  PORTH &= B11101111; break;

		case 8:  PORTH &= B11011111; break;
		case 9:  PORTH &= B10111111; break;
		case 10: PORTB &= B11101111; break;
		case 11: PORTB &= B11011111; break;
		case 12: PORTB &= B10111111; break;
		case 13: PORTB &= B01111111; break;

		case 14: PORTJ &= B11111101; break;
		case 15: PORTJ &= B11111110; break;
		case 16: PORTH &= B11111101; break;
		case 17: PORTH &= B11111110; break;
		case 18: PORTD &= B11110111; break;
		case 19: PORTD &= B11111011; break;
		case 20: PORTD &= B11111101; break;
		case 21: PORTD &= B11111110; break;

		case 22: PORTA &= B11111110; break;
		case 23: PORTA &= B11111101; break;
		case 24: PORTA &= B11111011; break;
		case 25: PORTA &= B11110111; break;
		case 26: PORTA &= B11101111; break;
		case 27: PORTA &= B11011111; break;
		case 28: PORTA &= B10111111; break;
		case 29: PORTA &= B01111111; break;

		case 30: PORTC &= B01111111; break;
		case 31: PORTC &= B10111111; break;
		case 32: PORTC &= B11011111; break;
		case 33: PORTC &= B11101111; break;
		case 34: PORTC &= B11110111; break;
		case 35: PORTC &= B11111011; break;
		case 36: PORTC &= B11111101; break;
		case 37: PORTC &= B11111110; break;

		case 38: PORTD &= B01111111; break;
		case 39: PORTG &= B11111011; break;
		case 40: PORTG &= B11111101; break;
		case 41: PORTG &= B11111110; break;
		case 42: PORTL &= B01111111; break;
		case 43: PORTL &= B10111111; break;
		case 44: PORTL &= B11011111; break;
		case 45: PORTL &= B11101111; break;

		case 46: PORTL &= B11110111; break;
		case 47: PORTL &= B11111011; break;
		case 48: PORTL &= B11111101; break;
		case 49: PORTL &= B11111110; break;
		case 50: PORTB &= B11110111; break;
		case 51: PORTB &= B11111011; break;
		case 52: PORTB &= B11111101; break;
		case 53: PORTB &= B11111110; break;
#else
#error No support for this board.
#endif		
		}
	}
}
//**************************************************************
static inline bool digitalReadFast(uint8_t pin) 
{
  switch(pin)
  {
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) 			
	 case 0: return PIND & B1; 
	 case 1: return PIND & B10; 
	 case 2: return PIND & B100;
	 case 3: return PIND & B1000;
	 case 4: return PIND & B10000;
	 case 5: return PIND & B100000;
	 case 6: return PIND & B1000000;
	 case 7: return PIND & B10000000;
	 case 8: return PINB & B1;
	 case 9: return PINB & B01;
	 case 10: return PINB & B001;
	 case 11: return PINB & B0001;
	 case 12: return PINB & B00001;
	 case 13: return PINB & B000001;
	 case 14: return PINC & B1;
	 case 15: return PINC & B01;
	 case 16: return PINC & B001;
	 case 17: return PINC & B0001;
	 case 18: return PINC & B00001;
	 case 19: return PINC & B000001;
 #elif defined(__AVR_ATmega32U4__) 
 #elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
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
	case 48: return PINL & B10;
	case 49: return PINL & B1;
	case 50: return PINB & B1000;
	case 51: return PINB & B100;
	case 52: return PINB & B10;
	case 53: return PINB & B1;
#else
#error No support for this board.
#endif		
}
}
//**************************************************************
/*
void pinModeFast(uint8_t pin, bool mode)
{
  if(mode==INPUT)
  {
	  if(pin>=0 && pin<=7)
  		PORTD &= ~(1<<pin);
	  else if(pin>=8 && pin<=13)
    	PORTB &= ~(1<<(pin-8)); 
	  else if(pin>=14 && pin<=19)
  		PORTC &= ~(1<<(pin-14));        
  }else
  {
    if(pin>=0 && pin<=7)
	  	PORTD |= (1<<pin);
  	else if(pin>=8 && pin<=13)
    	PORTB |= (1<<(pin-8)); 
	else if(pin>=14 && pin<=19)
  		PORTC |= (1<<(pin-14));
  }
}
*/