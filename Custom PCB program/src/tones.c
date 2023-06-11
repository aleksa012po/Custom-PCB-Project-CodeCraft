// All defines
#define __DELAY_BACKWARD_COMPATIBLE__

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "blink_led.h"
#include "tones.h"
#include "defines.h"

int tempo;
double length;

// Sound function
void soundOn(double tone, double len)
{
	DDRD = (1 << SOUND_PIN);		// Enable PORTD5 as output
	TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);		//  Compare Output Mode, non-PWM Mode, Clear OC0B on compare match, set OC0B at BOTTOM, (non-inverting mode), Fast PWM
	TCCR0B = (1 << WGM02) | (1 << CS02);		// Prescaler - Clk / 8
	OCR0A = tone;
	OCR0B = tone/2;
	length = (60.0/tempo)*len*4*1000.0;
	_delay_ms(length);
	DDRD &= ~(1 << SOUND_PIN);		// Disable PORTD5 as output
	//_delay_ms(10);
}

// Pause/mute function
void pause(double len)
{
	DDRD &= ~(1 << SOUND_PIN);
	length = (60.0/tempo)*len*4*1000.0;
	_delay_ms(length);
}


void ErrorBeepAndSound()
{
	tempo = 180;  
	blinkLED(100, 50, 4);
    soundOn(a5, sixteenth);
    soundOn(e6, sixteenth);
    pause(eight);
}

void InterstellarTheme(void)
{
		// Interstellar song
		tempo = 86;
		soundOn(a4, quarter);
		soundOn(e5, half);
		soundOn(a4, quarter);
		soundOn(e5, half);
		
		soundOn(b4, quarter);
		soundOn(e5, half);
		soundOn(b4, quarter);
		soundOn(e5, half);
		
		soundOn(c5, quarter);
		soundOn(e5, half);
		soundOn(c5, quarter);
		soundOn(e5, half);
		
		soundOn(d5, quarter);
		soundOn(e5, half);
		soundOn(d5, quarter);
		soundOn(e5, half);
		//*******************
// 		soundOn(a4, quarter);
// 		soundOn(e5, half);
// 		soundOn(a4, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(b4, quarter);
// 		soundOn(e5, half);
// 		soundOn(b4, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(c5, quarter);
// 		soundOn(e5, half);
// 		soundOn(c5, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(d5, quarter);
// 		soundOn(e5, half);
// 		soundOn(d5, quarter);
// 		soundOn(e5, half);
// 		//*******************
// 		soundOn(a4, quarter);
// 		soundOn(e5, half);
// 		soundOn(a4, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(b4, quarter);
// 		soundOn(e5, half);
// 		soundOn(b4, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(c5, quarter);
// 		soundOn(e5, half);
// 		soundOn(c5, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(d5, quarter);
// 		soundOn(e5, half);
// 		soundOn(d5, quarter);
// 		soundOn(e5, half);
// 		//*******************
// 		soundOn(a4, quarter);
// 		soundOn(e5, half);
// 		soundOn(a4, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(b4, quarter);
// 		soundOn(e5, half);
// 		soundOn(b4, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(c5, quarter);
// 		soundOn(e5, half);
// 		soundOn(c5, quarter);
// 		soundOn(e5, half);
// 		
// 		soundOn(d5, quarter);
// 		soundOn(e5, half);
// 		soundOn(d5, quarter);
// 		soundOn(e5, half);
//**********************************
//		The end of a song
//**********************************

		pause(whole+whole+whole);
}


void LinkingParkTheme(void)
{
	// Linkin Park - Numb
		tempo = 100;
		
		pause(whole);
		pause(eight);
		soundOn(cs5, eight);
		soundOn(e5,	 eight);
		soundOn(cs5, eight);

		soundOn(fs5, quarter+eight);
		soundOn(a5,  quarter+eight);
		soundOn(gs5, half+quarter);
		
		pause(eight);
		soundOn(cs5, eight);
		soundOn(e5,	 eight);
		soundOn(cs5, eight);
		soundOn(a5,  quarter+eight);
		soundOn(gs5, quarter+eight);
		soundOn(e5,  half+quarter);
		
		pause(eight);
		soundOn(cs5, eight);
		soundOn(e5,	 eight);
		soundOn(cs5, eight);
		soundOn(fs5, quarter+eight);
		soundOn(a5,  quarter+eight);
		soundOn(gs5, half+quarter);
		
		pause(eight);
		soundOn(cs5, eight);
		soundOn(e5,	 eight);
		soundOn(cs5, eight);
		soundOn(a5,  quarter+eight);
		soundOn(gs5, quarter+eight);
		soundOn(e5,  half+quarter);
//**********************************

// 		pause(eight);
// 		soundOn(fs4, eight);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(d5, eight);
// 		soundOn(cs5, eight+eight);
// 		soundOn(cs5, eight);
// 		soundOn(b4, eight);
// 		soundOn(a4, quarter+eight);
// 		
// 		pause(quarter);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(a4, eight);
// 		soundOn(b4, quarter);
// 		soundOn(a4, quarter);
// 		soundOn(e4, eight);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(a4, eight);
// 		soundOn(b4, quarter);
// 		soundOn(a4, quarter+eight);
// 		
// 		pause(quarter);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(d5, eight);
// 		soundOn(cs5, eight+eight);
// 		soundOn(cs5, eight);
// 		soundOn(b4, eight);
// 		soundOn(a4, quarter+eight);
// 		
// 		pause(eight);
// 		soundOn(a4, eight);
// 		soundOn(cs5, eight);
// 		soundOn(cs5, eight);
// 		soundOn(b4, eight);
// 		soundOn(a4, quarter);
// 		soundOn(b4, quarter);
// 		soundOn(e4, eight);
// 		soundOn(cs5, eight);
// 		soundOn(b4, quarter);
// 		soundOn(a4, quarter);
// 		soundOn(b4, quarter);
// 		soundOn(b4, eight);
// 		soundOn(cs5, whole);
//**********************************
//		The end of a song
//**********************************
		
		pause(whole+whole+whole);
}