#ifndef multiplexer_h
#define multiplexer_h

#include "Arduino.h"
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) 
	#include "fastdio.h"
#endif

class MultiplexerD4
{
  public:
    MultiplexerD4(uint8_t data1, uint8_t data2, uint8_t a1, uint8_t a2, bool mode);
	bool scanD(bool r[]);
	bool scanA(int16_t r[]);	
	inline bool getDigital(uint8_t, bool& );
	inline bool getDigitalD(uint8_t, bool&,bool& );
	inline int16_t getAnalog(uint8_t a);
	void set(uint8_t pin, bool bit);
	void setMode(bool in);
	bool getMode();
  private:
	bool mode=0;
    uint8_t Z0;
	uint8_t Z1;
	uint8_t S0;
	uint8_t S1;
};
MultiplexerD4::MultiplexerD4(uint8_t data1, uint8_t data2, uint8_t a1, uint8_t a2, bool md)
{
	Z0=data1;
	Z1=data2;
	S0=a1;
	S1=a2;
	mode=md;
	pinMode(S0,OUTPUT);
	pinMode(S1,OUTPUT);
	pinMode(Z0,mode);
	pinMode(Z1,mode);
}
bool MultiplexerD4::scanD(bool r[])
{
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<4;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			r[i*2] = digitalReadFast(Z0);
			r[i*2+1] = digitalReadFast(Z1);
		}
		return 1;
	}
	else
		return 0;
}
bool MultiplexerD4::scanA(int16_t r[])
{
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<4;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			r[i*2] = analogRead(Z0);
			r[i*2+1] = analogRead(Z1);
		}
		return 1;
	}
	else
		return 0;
}
bool MultiplexerD4::getDigital(uint8_t a,bool &r1)
{
	if(mode==OUTPUT)
		return 0;
	
	if(a<=7 && a>=0)
	{
		digitalWriteFast(S0,a & 1);
		digitalWriteFast(S1,a & 2);
//		delayMicroseconds(5);
		if(a<4)
			r1= digitalReadFast(Z0);
		else
			r1= digitalReadFast(Z1);
		return 1;
	}else
		return 0;
}
bool MultiplexerD4::getDigitalD(uint8_t a,bool &r1,bool &r2)
{
	if(a<=7 && a>=0)
	{
			int8_t ret=0;
			digitalWriteFast(S0,a & 1);
			digitalWriteFast(S1,a & 2);
//			delayMicroseconds(5);
			r1= digitalReadFast(Z0);
			r2= digitalReadFast(Z1);
			return 1;
	}else
		return 0;
}
int16_t MultiplexerD4::getAnalog(uint8_t a)
{	
	if(a<=7 && a>=0)
	{
		digitalWriteFast(S0,a & 1);
		digitalWriteFast(S1,a & 2);
		if(a<4)
			return analogRead(Z0);
		else
			return analogRead(Z1);
	}else
		return -1;
}
void MultiplexerD4::set(uint8_t pin, bool bit)
{
	if(mode==OUTPUT)
	{
		if(pin>=0 && pin<8)
		{
			digitalWriteFast(S0,pin & 1);
			digitalWriteFast(S1,pin & 2);
			if(pin<4)
				digitalWriteFast(Z0,bit);
			else
				digitalWriteFast(Z1,bit);
		}
	}
}
//*************************************************** Multiplexer8 **************************************
class Multiplexer8
{
  public:
    Multiplexer8(uint8_t data1, uint8_t a1, uint8_t a2, uint8_t a3, bool md);
    Multiplexer8(uint8_t data1, uint8_t data2, uint8_t a1, uint8_t a2, uint8_t a3, bool md);
	inline bool scanD(bool r[]);
	inline bool scanD2(bool r1[],bool r2[]);
	inline bool scanA(int16_t r[]);	
	inline bool scanA2(int16_t r1[],int16_t r2[]);	
	inline bool getDigital(uint8_t, bool& );
	inline bool getDigital(uint8_t, bool&, bool&);
	inline int16_t getAnalog(uint8_t a);
	void set(uint8_t pin, bool bit);
	void set(uint8_t pin, bool bit1,bool bit2);	
	void setMode(bool in);
	bool getMode();
  private:
	bool mode=0;
    uint8_t Z0;
    uint8_t Z1;	
	uint8_t S0;
	uint8_t S1;
	uint8_t S2;
	bool dual=0;
};
Multiplexer8::Multiplexer8(uint8_t data1, uint8_t a1, uint8_t a2, uint8_t a3, bool md)
{
	Z0=data1;
	S0=a1;
	S1=a2;
	S2=a3;
	mode=md;
	pinMode(S0,OUTPUT);
	pinMode(S1,OUTPUT);
	pinMode(S2,OUTPUT);
	pinMode(Z0,mode);
}
Multiplexer8::Multiplexer8(uint8_t data1, uint8_t data2, uint8_t a1, uint8_t a2, uint8_t a3, bool md)
{
	Z0=data1;
	Z1=data2;
	S0=a1;
	S1=a2;
	S2=a3;
	mode=md;
	pinMode(S0,OUTPUT);
	pinMode(S1,OUTPUT);
	pinMode(S2,OUTPUT);
	pinMode(Z0,mode);
	pinMode(Z1,mode);
	dual=1;
}
inline bool Multiplexer8::scanD(bool r1[])
{
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<8;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			r1[i] = digitalReadFast(Z0);
		}
		return 1;
	}
	else
		return 0;
}
inline bool Multiplexer8::scanD2(bool r1[],bool r2[])
{
	if(!dual) return 0;
	
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<8;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			r1[i] = digitalReadFast(Z0);
			r2[i] = digitalReadFast(Z1);
		}
		return 1;
	}
	else
		return 0;
}
inline bool Multiplexer8::scanA(int16_t r[])
{
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<8;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			delayMicroseconds(5);
			r[i] = analogRead(Z0);
		}
		return 1;
	}
	else
		return 0;
}
inline bool Multiplexer8::scanA2(int16_t r1[],int16_t r2[])
{
	if(!dual) return 0;
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<8;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			r1[i] = analogRead(Z0);
			r2[i] = analogRead(Z1);
		}
		return 1;
	}
	else
		return 0;
}
bool Multiplexer8::getDigital(uint8_t a,bool &r1)
{
	if(mode==OUTPUT)
		return 0;
	
	if(a>=0 && a<8)
	{
		digitalWriteFast(S0,a & 1);
		digitalWriteFast(S1,a & 2);
		digitalWriteFast(S2,a & 4);
		r1= digitalReadFast(Z0);
	}else
		return 0;
}
bool Multiplexer8::getDigital(uint8_t a,bool &r1,bool &r2)
{
	if(mode==OUTPUT || !dual)
		return 0;
	
	if(a>=0 && a<8)
	{
		digitalWriteFast(S0,a & 1);
		digitalWriteFast(S1,a & 2);
		digitalWriteFast(S2,a & 4);
		r1= digitalReadFast(Z0);
		r2= digitalReadFast(Z1);
		return 1;
	}else
		return 0;
}
int16_t Multiplexer8::getAnalog(uint8_t a)
{	
	if(mode==INPUT)
	{
		if(a>=0)
		{
			if(a<8)
			{
				digitalWriteFast(S0,a & 1);
				digitalWriteFast(S1,a & 2);
				digitalWriteFast(S2,a & 4);		
				return analogRead(Z0);
			}
			else if(a>=8 && dual)
			{
				digitalWriteFast(S0,(a-8) & 1);
				digitalWriteFast(S1,(a-8) & 2);
				digitalWriteFast(S2,(a-8) & 4);		
				return analogRead(Z1);
			}
			else
				return -1;
		}else
			return -1;
	}
	else return -1;
}
void Multiplexer8::set(uint8_t pin, bool bit)
{
	if(mode==OUTPUT)
	{
		if(pin>=0 && pin<8)
		{
			digitalWriteFast(S0,pin & 1);
			digitalWriteFast(S1,pin & 2);
			digitalWriteFast(S2,pin & 4);
			digitalWriteFast(Z0,bit);
		}
	}
}
void Multiplexer8::set(uint8_t pin, bool bit1,bool bit2)
{
	if(!dual) return;
	if(mode==OUTPUT)
	{
		if(pin>=0 && pin<8)
		{
			digitalWriteFast(S0,pin & 1);
			digitalWriteFast(S1,pin & 2);
			digitalWriteFast(S2,pin & 4);
			digitalWriteFast(Z0,bit1);
			digitalWriteFast(Z1,bit2);			
		}
	}
}

//*************************************************** Multiplexer16 **************************************
class Multiplexer16
{
  public:
    Multiplexer16(uint8_t data1, uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4, bool md);
    Multiplexer16(uint8_t data1, uint8_t data2, uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4, bool md);
	inline bool scanD(bool r[]);
	inline bool scanD2(bool r1[],bool r2[]);
	inline bool scanA(int16_t r[]);	
	inline bool scanA2(int16_t r1[],int16_t r2[]);	
	inline bool getDigital(uint8_t, bool& );
	inline bool getDigital(uint8_t, bool&, bool&);
	inline int16_t getAnalog(uint8_t a);
	void set(uint8_t pin, bool bit);
	void set(uint8_t pin, bool bit1,bool bit2);	
	void setMode(bool in);
	bool getMode();
  private:
	bool mode=0;
    uint8_t Z0;
    uint8_t Z1;	
	uint8_t S0;
	uint8_t S1;
	uint8_t S2;
	uint8_t S3;
	bool dual=0;
};
Multiplexer16::Multiplexer16(uint8_t data1, uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4, bool md)
{
	Z0=data1;
	S0=a1;
	S1=a2;
	S2=a3;
	S3=a4;
	mode=md;
	pinMode(S0,OUTPUT);
	pinMode(S1,OUTPUT);
	pinMode(S2,OUTPUT);
	pinMode(S3,OUTPUT);
	pinMode(Z0,mode);
}
Multiplexer16::Multiplexer16(uint8_t data1, uint8_t data2, uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4, bool md)
{
	Z0=data1;
	Z1=data2;
	S0=a1;
	S1=a2;
	S2=a3;
	S3=a4;
	mode=md;
	pinMode(S0,OUTPUT);
	pinMode(S1,OUTPUT);
	pinMode(S2,OUTPUT);
	pinMode(S3,OUTPUT);
	pinMode(Z0,mode);
	pinMode(Z1,mode);
	dual=1;
}
inline bool Multiplexer16::scanD(bool r1[])
{
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<16;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			digitalWriteFast(S3,i&8);
			r1[i] = digitalReadFast(Z0);
		}
		return 1;
	}
	else
		return 0;
}
inline bool Multiplexer16::scanD2(bool r1[],bool r2[])
{
	if(!dual) return 0;
	
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<16;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			digitalWriteFast(S3,i&8);
			r1[i] = digitalReadFast(Z0);
			r2[i] = digitalReadFast(Z1);
		}
		return 1;
	}
	else
		return 0;
}
inline bool Multiplexer16::scanA(int16_t r[])
{
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<16;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			digitalWriteFast(S3,i&8);
//			delayMicroseconds(5);
			r[i] = analogRead(Z0);
		}
		return 1;
	}
	else
		return 0;
}
inline bool Multiplexer16::scanA2(int16_t r1[],int16_t r2[])
{
	if(!dual) return 0;
	if(mode==INPUT)
	{
		for(uint8_t i=0;i<16;i++)
		{
			digitalWriteFast(S0,i&1);
			digitalWriteFast(S1,i&2);
			digitalWriteFast(S2,i&4);
			digitalWriteFast(S3,i&8);
			r1[i] = analogRead(Z0);
			r2[i] = analogRead(Z1);
		}
		return 1;
	}
	else
		return 0;
}
bool Multiplexer16::getDigital(uint8_t a,bool &r1)
{
	if(mode==OUTPUT)
		return 0;
	
	if(a>=0 && a<16)
	{
		digitalWriteFast(S0,a & 1);
		digitalWriteFast(S1,a & 2);
		digitalWriteFast(S2,a & 4);
		digitalWriteFast(S3,a & 8);
		r1= digitalReadFast(Z0);
	}else
		return 0;
}
bool Multiplexer16::getDigital(uint8_t a,bool &r1,bool &r2)
{
	if(mode==OUTPUT || !dual)
		return 0;
	
	if(a>=0 && a<16)
	{
		digitalWriteFast(S0,a & 1);
		digitalWriteFast(S1,a & 2);
		digitalWriteFast(S2,a & 4);
		digitalWriteFast(S3,a & 8);
		r1= digitalReadFast(Z0);
		r2= digitalReadFast(Z1);
		return 1;
	}else
		return 0;
}
int16_t Multiplexer16::getAnalog(uint8_t a)
{	
	if(mode==INPUT)
	{
		if(a>=0)
		{
			if(a<16)
			{
				digitalWriteFast(S0,a & 1);
				digitalWriteFast(S1,a & 2);
				digitalWriteFast(S2,a & 4);		
				digitalWriteFast(S3,a & 8);
				return analogRead(Z0);
			}
			else if(a>=16 && dual)
			{
				digitalWriteFast(S0,(a-16) & 1);
				digitalWriteFast(S1,(a-16) & 2);
				digitalWriteFast(S2,(a-16) & 4);		
				digitalWriteFast(S3,(a-16) & 8);		
				return analogRead(Z1);
			}
			else
				return -1;
		}else
			return -1;
	}
	else return -1;
}
void Multiplexer16::set(uint8_t pin, bool bit)
{
	if(mode==OUTPUT)
	{
		if(pin>=0 && pin<16)
		{
			digitalWriteFast(S0,pin & 1);
			digitalWriteFast(S1,pin & 2);
			digitalWriteFast(S2,pin & 4);
			digitalWriteFast(S3,pin & 8);
			digitalWriteFast(Z0,bit);
		}
	}
}
void Multiplexer16::set(uint8_t pin, bool bit1,bool bit2)
{
	if(!dual) return;
	if(mode==OUTPUT)
	{
		if(pin>=0 && pin<16)
		{
			digitalWriteFast(S0,pin & 1);
			digitalWriteFast(S1,pin & 2);
			digitalWriteFast(S2,pin & 4);
			digitalWriteFast(S3,pin & 8);
			digitalWriteFast(Z0,bit1);
			digitalWriteFast(Z1,bit2);			
		}
	}
}

#endif