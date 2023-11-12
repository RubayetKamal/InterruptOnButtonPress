/*
* Interrupt.c
*
* Created: 03/11/2023 10:22:11
* Author : $RHEK00-BS9TAG427UBC
*/

#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"
#include <avr/interrupt.h>
void initPorts();
void initInterrupt();

uint8_t gBtnFlag = 0x00;

ISR(INT0_vect)
{
	gBtnFlag = (gBtnFlag ^ 0x01);
	if(gBtnFlag)
	{
		PORTA |=(1 << 0);
	}
	else
	{
		PORTA &=~(1 << 0);
	}
}
int main(void)
{
	initPorts();
	initInterrupt();
	sei();
	
	while (1)
	{
		uint32_t i;
		
		for(i = 0; i < 1000000; i++)
		{
			asm("nop");
		}
		for(i = 0; i < 2000000; i++)
		{
			asm("nop");
		}
	}
}

void initPorts(){
		
		DDRA |= (1 << 0);
		DDRD &=~(1 << 0);
		
		PORTA &=~(1 << 0);
		PORTD |= (1 << 0);
}

void initInterrupt(){
		EIMSK |=(1 << INT0);
		
		EICRA |=(1 << ISC00) | (1 << ISC01);
		

}
