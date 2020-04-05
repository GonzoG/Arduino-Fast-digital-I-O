#include "fastdio.h"
typedef struct shReg{
	uint8_t dPin;
	uint8_t d1Pin;
	uint8_t d2Pin;	
	uint8_t d3Pin;	
	uint8_t rPin;
	uint8_t sPin;
	bool bOrder;
};

static inline void regOut8(shReg pins,uint8_t data)
{
	for(uint8_t i=0;i<8;i++)
	{
		if(pins.bOrder==LSBFIRST)
		{
			digitalWriteFast(pins.dPin,data&1);
			data>>=1;
		}else
		{
			digitalWriteFast(pins.dPin,data&B10000000);
			data<<=1;
		}
		digitalWriteFast(pins.rPin,1);
		digitalWriteFast(pins.rPin,0);
	}
}

static inline void regOut8D(shReg pins,uint8_t data)
{
	for(uint8_t i=0;i<8;i++)
	{
		if(pins.bOrder==LSBFIRST)
		{
			digitalWriteFast(pins.dPin,data&1);
			digitalWriteFast(pins.d1Pin,data&1);
			data>>=1;
		}else
		{
			digitalWriteFast(pins.dPin,data&B10000000);
			digitalWriteFast(pins.d1Pin,data&B10000000);
			data<<=1;
		}
		digitalWriteFast(pins.rPin,1);
		digitalWriteFast(pins.rPin,0);
	}
}

static inline void regOut8Q(shReg pins,uint8_t data)
{
	for(uint8_t i=0;i<8;i++)
	{
		if(pins.bOrder==LSBFIRST)
		{
			digitalWriteFast(pins.dPin,data&1);
			digitalWriteFast(pins.d1Pin,data&1);
			digitalWriteFast(pins.d2Pin,data&1);
			digitalWriteFast(pins.d3Pin,data&1);
			data>>=1;
		}else
		{
			digitalWriteFast(pins.dPin,data&B10000000);
			digitalWriteFast(pins.d1Pin,data&B10000000);
			digitalWriteFast(pins.d2Pin,data&B10000000);
			digitalWriteFast(pins.d3Pin,data&B10000000);
			data<<=1;
		}
		digitalWriteFast(pins.rPin,1);
		digitalWriteFast(pins.rPin,0);
	}
}

static inline void regOut8f(shReg pins,uint8_t data) 
{
	if(pins.bOrder==LSBFIRST)
	{
		digitalWriteFast(pins.dPin,data&B1);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
	}else
	{
		digitalWriteFast(pins.dPin,data&B10000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
	}
}

static inline void regOut8Df(shReg pins,uint8_t data) 
{
	if(pins.bOrder==LSBFIRST)
	{
		digitalWriteFast(pins.dPin,data&B1);
		digitalWriteFast(pins.d1Pin,data&B1);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10);
		digitalWriteFast(pins.d1Pin,data&B10);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100);
		digitalWriteFast(pins.d1Pin,data&B100);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000);
		digitalWriteFast(pins.d1Pin,data&B1000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10000);
		digitalWriteFast(pins.d1Pin,data&B10000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100000);
		digitalWriteFast(pins.d1Pin,data&B100000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000000);
		digitalWriteFast(pins.d1Pin,data&B1000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10000000);
		digitalWriteFast(pins.d1Pin,data&B10000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
	}else
	{
		digitalWriteFast(pins.dPin,data&B10000000);
		digitalWriteFast(pins.d1Pin,data&B10000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000000);
		digitalWriteFast(pins.d21Pin,data&B1000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100000);
		digitalWriteFast(pins.d1Pin,data&B100000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10000);
		digitalWriteFast(pins.d1Pin,data&B10000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1000);
		digitalWriteFast(pins.d1Pin,data&B1000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B100);
		digitalWriteFast(pins.d1Pin,data&B100);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B10);
		digitalWriteFast(pins.d1Pin,data&B10);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		digitalWriteFast(pins.dPin,data&B1);
		digitalWriteFast(pins.d1Pin,data&B1);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
	}
}

static inline void regOut8Qf(shReg pins,uint8_t data) 
{
	if(pins.bOrder==LSBFIRST)
	{
		digitalWriteFast(pins.dPin,data&B1);
		digitalWriteFast(pins.d1Pin,data&B1);
		digitalWriteFast(pins.d2Pin,data&B1);
		digitalWriteFast(pins.d3Pin,data&B1);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B10);
		digitalWriteFast(pins.d1Pin,data&B10);
		digitalWriteFast(pins.d2Pin,data&B10);
		digitalWriteFast(pins.d3Pin,data&B10);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B100);
		digitalWriteFast(pins.d1Pin,data&B100);
		digitalWriteFast(pins.d2Pin,data&B100);
		digitalWriteFast(pins.d3Pin,data&B100);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B1000);
		digitalWriteFast(pins.d1Pin,data&B1000);
		digitalWriteFast(pins.d2Pin,data&B1000);
		digitalWriteFast(pins.d3Pin,data&B1000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B10000);
		digitalWriteFast(pins.d1Pin,data&B10000);
		digitalWriteFast(pins.d2Pin,data&B10000);
		digitalWriteFast(pins.d3Pin,data&B10000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B100000);
		digitalWriteFast(pins.d1Pin,data&B100000);
		digitalWriteFast(pins.d2Pin,data&B100000);
		digitalWriteFast(pins.d3Pin,data&B100000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B1000000);
		digitalWriteFast(pins.d1Pin,data&B1000000);
		digitalWriteFast(pins.d2Pin,data&B1000000);
		digitalWriteFast(pins.d3Pin,data&B1000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B10000000);
		digitalWriteFast(pins.d1Pin,data&B10000000);
		digitalWriteFast(pins.d2Pin,data&B10000000);
		digitalWriteFast(pins.d3Pin,data&B10000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
	}else
	{
		digitalWriteFast(pins.dPin,data&B10000000);
		digitalWriteFast(pins.d1Pin,data&B10000000);
		digitalWriteFast(pins.d2Pin,data&B10000000);
		digitalWriteFast(pins.d3Pin,data&B10000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B1000000);
		digitalWriteFast(pins.d1Pin,data&B1000000);
		digitalWriteFast(pins.d2Pin,data&B1000000);
		digitalWriteFast(pins.d3Pin,data&B1000000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B100000);
		digitalWriteFast(pins.d1Pin,data&B100000);
		digitalWriteFast(pins.d2Pin,data&B100000);
		digitalWriteFast(pins.d3Pin,data&B100000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B10000);
		digitalWriteFast(pins.d1Pin,data&B10000);
		digitalWriteFast(pins.d2Pin,data&B10000);
		digitalWriteFast(pins.d3Pin,data&B10000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B1000);
		digitalWriteFast(pins.d1Pin,data&B1000);
		digitalWriteFast(pins.d2Pin,data&B1000);
		digitalWriteFast(pins.d3Pin,data&B1000);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B100);
		digitalWriteFast(pins.d1Pin,data&B100);
		digitalWriteFast(pins.d2Pin,data&B100);
		digitalWriteFast(pins.d3Pin,data&B100);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B10);
		digitalWriteFast(pins.d1Pin,data&B10);
		digitalWriteFast(pins.d2Pin,data&B10);
		digitalWriteFast(pins.d3Pin,data&B10);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
		
		digitalWriteFast(pins.dPin,data&B1);
		digitalWriteFast(pins.d1Pin,data&B1);
		digitalWriteFast(pins.d2Pin,data&B1);
		digitalWriteFast(pins.d3Pin,data&B1);
		digitalWriteFast(pins.sPin,1);
		digitalWriteFast(pins.sPin,0);
	}
}

void regOut8fl(shReg pins,uint8_t data)
{
	digitalWriteFast(pins.rPin,0);
	regOut8f(pins,data);
	digitalWriteFast(pins.rPin,1);
}

void regOut8l(shReg pins,uint8_t data)
{
	digitalWriteFast(pins.rPin,0);
	regOut8(pins,data);
	digitalWriteFast(pins.rPin,1);
}
//***********************************************************************************************************
void regOut16(uint8_t dataPin,uint8_t clockPin, bool bitOrder,uint16_t data)
{
	for(uint8_t i=0;i<16;i++)
	{
		if(bitOrder==LSBFIRST)
		{
			digitalWriteFast(dataPin,data&1);
			data>>=1;
		}else
		{
			digitalWriteFast(dataPin,data & 0x8000);
			data<<=1;
		}
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
	}
}

static inline void regOut16(uint8_t dataPin,uint8_t clockPin, bool bitOrder,uint16_t data)
{
	if(bitOrder==LSBFIRST)
	{
		digitalWriteFast(dataPin,data&0x1);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x2);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x4);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x8);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x10);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x20);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x40);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x80);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x100);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x200);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x400);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x800);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x1000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x2000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x4000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data&0x8000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
	}else
	{
		digitalWriteFast(dataPin,data & 0x8000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x4000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x2000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x1000);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x800);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x400);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x200);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x100);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x80);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x40);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x20);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x10);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x8);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x4);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x2);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
		digitalWriteFast(dataPin,data & 0x1);
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
	}
}


void regOut16l(uint8_t dataPin,uint8_t clockPin, bool bitOrder,uint16_t data, uint8_t latchPin)
{
	digitalWriteFast(latchPin,0);
	for(uint8_t i=0;i<16;i++)
	{
		if(bitOrder==LSBFIRST)
		{
			digitalWriteFast(dataPin,data&1);
			data>>=1;
		}else
		{
			digitalWriteFast(dataPin,data & 0x8000);
			data<<=1;
		}
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
	}
	digitalWriteFast(latchPin,1);
}
//***********************************************************************************************************
static inline void regOut32(uint8_t dataPin,uint8_t clockPin, bool bitOrder,uint32_t data)
{
	for(uint8_t i=0;i<32;i++)
	{
		if(bitOrder==LSBFIRST)
		{
			digitalWriteFast(dataPin,data&1);
			data>>=1;
		}else
		{
			digitalWriteFast(dataPin,data & 0x80000000);
			data<<=1;
		}
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
	}
}
void regOut32l(uint8_t dataPin,uint8_t clockPin, bool bitOrder,uint32_t data, uint8_t latchPin)
{
	digitalWriteFast(latchPin,0);
	for(uint8_t i=0;i<32;i++)
	{
		if(bitOrder==LSBFIRST)
		{
			digitalWriteFast(dataPin,data&1);
			data>>=1;
		}else
		{
			digitalWriteFast(dataPin,data & 0x80000000);
			data<<=1;
		}
		digitalWriteFast(clockPin,1);
		digitalWriteFast(clockPin,0);
	}
	digitalWriteFast(latchPin,1);
}
//		digitalWriteFast(dataArduPin,data & 0x80000000); //0x80 //128
