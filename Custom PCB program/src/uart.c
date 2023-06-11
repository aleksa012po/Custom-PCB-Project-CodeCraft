#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdio.h>

void UART_Init(unsigned int baud)
{
	unsigned int ubrr = F_CPU / 16 / baud - 1;
	
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0A = 0;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void putChar(uint8_t data)
{
	// Wait until the transmit buffer is empty
	while(!(UCSR0A &(1 << UDRE0)));
	
	// Transmit the data
	UDR0 = data;
}

int getChar()
{
	// Wait until data is available to be received
	while (!(UCSR0A &(1 << RXC0)));
	
	// Return the received data
	return UDR0;
}

void uart_start(uint8_t *receivedData)
{
	while (!(UCSR0A & (1 << RXC0)))
	{
	}

	*receivedData = UDR0;
}

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