/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


//unsigned short x = ADC;

void ADC_init()
{
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_init();
    while (1) {
	unsigned short val = ADC;
	unsigned short MAX = 1011;
	if(val >= (MAX/2))
	{
		PORTB = 0x01;
	}
	else
	{
		PORTB = 0x00;
	}
	//unsigned char myVal = (char)val;
	//PORTB = myVal >> 0x02; //grabs the upper eight bits from ADC
	//unsigned char lowerBits = myVal & 0x03; //grabs the lower two bits from ADC
	//PORTD = lowerBits;

	//lowest value for photoresistor: 194 (integer)
	//highest value for photoresistor: 1011 (integer)
    }
    return 1;
}
