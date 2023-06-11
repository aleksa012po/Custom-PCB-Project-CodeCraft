#define F_CPU 16000000UL

#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void PinInit()
{
	DDRD |= (1 << PORTD3);
	PORTD |= (1 << PORTD3);
}


void blinkLED(int onTime, int offTime, int repetitions)
{
	TCCR2A = 0;
	PinInit();
	for (int i = 0; i < repetitions; i++)
	{
		PORTD |= (1 << PORTD3);
		
		_delay_ms(onTime);
		
		PORTD &= ~(1 << PORTD3);
		
		_delay_ms(offTime);
		
	}
}