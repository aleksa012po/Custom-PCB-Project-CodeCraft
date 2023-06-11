#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "ws2811.h"

#define PAUSE 1000
#define DELAY 10
#define LENGTH 255
#define RGB_PIN PORTD4

#define __DELAY_BACKWARD_COMPATIBLE__

volatile RGB_t rgb[LENGTH];  // Array to hold the RGB values of each LED

volatile uint32_t timerMillis = 0;


DEFINE_WS2811_FN(WS2811RGB, PORTD, 4)

ISR(TIMER0_COMPA_vect)
{
	timerMillis++;
}

void initMillisTimer()
{
	// Set up Timer0 for 1ms interrupt using CTC mode
	OCR0A = F_CPU / 1000 / 8 - 1; // Set the compare value for 1ms
	TCCR0A = (1 << WGM01); // Set CTC mode
	TCCR0B = (1 << CS01) | (1 << CS00); // Set prescaler to 64
	TIMSK0 = (1 << OCIE0A); // Enable Timer0 compare interrupt
}

uint32_t millis()
{
	uint32_t ms;
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		ms = timerMillis;
	}
	return ms;
}

void setPixel(RGB_t pixel, uint8_t row, RGB_t *array)
{
	array[row].r = pixel.r;
	array[row].g = pixel.g;
	array[row].b = pixel.b;
}

void setPixelColor(uint8_t r, uint8_t g, uint8_t b, uint8_t row, RGB_t *array)
{
	array[row].r = r;
	array[row].g = g;
	array[row].b = b;
}

void setColor(uint8_t r, uint8_t g, uint8_t b, RGB_t *array)
{
	for (uint8_t i = 0; i < LENGTH; i++)
	{
		setPixelColor(r, g, b, i, array);
	}
}

void RGB_init(void)
{
	DDRD |= (1 << RGB_PIN);
	PORTD &= ~(1 << RGB_PIN);
}

void setRandomColor(RGB_t *array) 
{
	for (uint8_t i = 0; i < LENGTH; i++)
	{
		array[i].r = rand() % 32; // set red component to a random value between 0 and 32
		array[i].g = rand() % 32; // set green component to a random value between 0 and 32
		array[i].b = rand() % 32; // set blue component to a random value between 0 and 32
	}
}

void rotate(RGB_t *array)
{
	RGB_t temp = array[LENGTH - 1];  // Store the last LED color

	for (uint8_t i = LENGTH - 1; i > 0; i--)
	{
		array[i] = array[i - 1];  // Shift each LED color one position to the right
	}

	array[0] = temp;  // Set the first LED color to the stored last LED color
}

void onePulse(void)
{
	PORTD |= 0b00010000;
	PORTD |= 0b00010000;
	PORTD |= 0b00010000;
	PORTD &= 0b11101111;
}

void zeroPulse(void)
{
	PORTD |= 0b00010000;
	PORTD &= 0b11101111;
}

void ws_send_byte(unsigned char K)
{
	if(K & 0b10000000)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
	if(K & 0b01000000)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
	if(K & 0b00100000)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
	if(K & 0b00010000)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
	if(K & 0b00001000)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
	if(K & 0b00000100)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
	if(K & 0b00000010)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
	if(K & 0b00000001)
	{
		onePulse();
	}
	else
	{
		zeroPulse();
	}
}

void c_WS2812_Write(unsigned char R, unsigned char G, unsigned char B)
{
	ws_send_byte(G);
	ws_send_byte(R);
	ws_send_byte(B);
}

void colorRing(unsigned char R, unsigned char G, unsigned char B) 
{
	for(uint16_t i=0; i < 3; i++) 
	{
		c_WS2812_Write(R, G, B);
		R+=1;
		G+=1;
		B+=1;
	}
	_delay_ms(5);
}

void breathingEffect()
{
	RGB_init();
    int red = 0;
    int green = 0;
    int blue = 0;
    int n = 0;
	
	for(int i = 0; i < 3; i++)
	{

    // Breathing effect for yellow
    for (n = 0; n < 128; n++)
		{
			colorRing(red, green, blue);
			red++;
			green++;
		}
		
		for (n = 0; n < 128; n++)
		{
			colorRing(red, green, blue);
			red--;
			green--;
		}
		
		// Breathing effect for magenta
		for (n = 0; n < 128; n++)
		{
			colorRing(red, green, blue);
			red++;
			blue++;
		}

		for (n = 0; n < 128; n++)
		{
			colorRing(red, green, blue);
			red--;
			blue--;
		}
		
		// Breathing effect for orange
		for (n = 0; n < 128; n++)
		{
			colorRing(red, green, blue);
			green++;
			blue++;
		}

		for (n = 0; n < 128; n++)
		{
			colorRing(red, green, blue);
			green--;
			blue--;
		}

   }
		 // Turn off all LEDs
		 setColor(0, 0, 0, rgb);
		 WS2811RGB(rgb, LENGTH);
}

void Color_Effect()
{
	RGB_init();
	setRandomColor(rgb);  // Set random colors for each LED
	WS2811RGB(rgb, LENGTH);  // Update the LEDs with the current pixel data
	_delay_ms(200);

	uint32_t duration = 8000;  // Total duration in milliseconds (5 seconds)
	uint32_t startTime = millis();  // Get the current time in milliseconds

	while ((millis() - startTime) < duration)
	{
		rotate(rgb);  // Rotate the LED colors
		WS2811RGB(rgb, LENGTH);  // Update the LEDs with the current pixel data
		_delay_ms(200);  // Adjust the delay here (e.g., 100 milliseconds)
	}

	// Turn off all LEDs
	setColor(0, 0, 0, rgb);
	WS2811RGB(rgb, LENGTH);
}

