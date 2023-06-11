#define F_CPU 16000000UL

#include <avr/io.h>
#include <string.h>
#include <stdio.h>

void send_string(const char* str)
{
	
	size_t length = strlen(str);
	for (size_t i = 0; i < length; i++)
	{
		putChar(str[i]);
	}
}