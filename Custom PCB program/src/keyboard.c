#define F_CPU 16000000UL

#include <stdbool.h>
#include "tones.h"
#include "uart.h"

void audioON()
{
	char key;
	key = getChar();
	tempo = 512;
	switch (key)
	{
		case 'z':
			soundOn(c4, eight);
			break;
		case 's':
			soundOn(cs4, eight);
			break;
		case 'x':
			soundOn(d4, eight);
			break;
		case 'd':
			soundOn(ds4, eight);
			break;
		case 'c':
			soundOn(e4, eight);
			break;
		case 'v':
			soundOn(f4, eight);
			break;
		case 'g':
			soundOn(fs4, eight);
			break;
		case 'b':
			soundOn(g4, eight);
			break;
		case 'h':
			soundOn(gs4, eight);
			break;
		case 'n':
			soundOn(a4, eight);
			break;
		case 'j':
			soundOn(as4, eight);
			break;
		case 'm':
			soundOn(b4, eight);
			break;
		case ',':
			soundOn(c5, eight);
			break;
 		case 'q':
			// quit
 			break;
		case '2':
			soundOn(cs5, eight);
			break;
		case 'w':
			soundOn(d5, eight);
			break;
		case '3':
			soundOn(ds5, eight);
			break;
		case 'e':
			soundOn(e5, eight);
			break;
		case 'r':
			soundOn(f5, eight);
			break;
		case '5':
			soundOn(fs5, eight);
			break;
		case 't':
			soundOn(g5, eight);
			break;
		case '6':
			soundOn(gs5, eight);
			break;
		case 'y':
			soundOn(a5, eight);
			break;
		case '7':
			soundOn(as5, eight);
			break;
		case 'u':
			soundOn(b5, eight);
			break;
		case 'i':
			soundOn(c6, eight);
			break;
		case '9':
			soundOn(cs6, eight);
			break;
		case 'o':
			soundOn(d6, eight);
			break;
		case '0':
			soundOn(ds6, eight);
			break;
		case 'p':
			soundOn(e6, eight);
			break;
		case '[':
			soundOn(f6, eight);
			break;
		case '=':
			soundOn(fs6, eight);
			break;
		case ']':
			soundOn(g6, eight);
			break;

		default:
			printf("exiting sound program.");
			break;
	}
}