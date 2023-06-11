#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include "config.h"
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int dutyCycle = 0;

void pwmSetup()
{
	TCCR2A = (1 << COM2B1) | (1 << WGM20) | (1 << WGM21);    // TCCR2A = 0b10000011, Fast PWM, Clear OC2B on Compare match, set OC2B at bottom
	TIMSK2 = (1 << TOIE2);                                   // TIMSK2 = 0b00000001

	OCR2B = (dutyCycle / 100.0) * 255;

	sei();                                                  // Interrupt Enable

	TCCR2B = (1 << CS20) | (1 << CS21) | (1 << CS22);        // TCCR2B = 0b00000111
}


void pwmLEDControl(int increment)
{
	int direction = 1;
	int delay = 150;
	int repeatCount = 0;

	while (repeatCount < 5)
	{
		_delay_ms(delay);

		dutyCycle += increment * direction;

		if (dutyCycle >= 100)
		{
			dutyCycle = 100;
			direction = -1;
		}
		else if (dutyCycle <= 0)
		{
			dutyCycle = 0;
			direction = 1;
		}

		// Check if 5 repetitions have been completed
		if (dutyCycle == 0 && direction == 1)
		{
			repeatCount++;
		}
	}
}

void pwmOff(void)
{
	blinkLED(20,20,1);
}




