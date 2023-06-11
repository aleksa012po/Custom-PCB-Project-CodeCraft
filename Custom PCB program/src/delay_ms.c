#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void delay_ms(unsigned int milliseconds)
{
	unsigned int i;
	
	for (i = 0; i < milliseconds; i++)
	{
		_delay_ms(1); // Use the built-in _delay_ms() function from <util/delay.h>
	}
}