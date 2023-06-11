#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

void UART_Init(unsigned int baud);
void putChar(uint8_t data);
int getChar();
void uart_start(uint8_t *receivedData);

#endif /* UART_H_ */

/*
REMINDER:

int main(void)
{
// Initialize UART at BAUD rate 14400
UART_Init(14400);
// Receive a character
int data = getChar();
// Print the received character
putChar(data);
	while(1)
	{
	}
}
*/