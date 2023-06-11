/*
 * twi.c
 *
 * Created: 19.1.2023. 00:24:39
 *  Author: Aleksandar Bogdanovic
 */ 
#define F_CPU 16000000
#include <avr/io.h>

#define get_bit(reg,bitnum) ((reg & (1<<bitnum))>>bitnum)// Get bit macro used to get the value of a certain bit

void TWI_Init(void)
{
	TWSR = 0;											// TWI Status Register
	TWBR = 0x48;										// TWBR = ((F_CPU / frequency) - 16) / 2, TWBR = 72(0x48), 100 kHz (default), TWBR – TWI Bit Rate Register
	TWCR |= (1 << TWEN);								// TWCR - TWI Control Register, TWEN - TWI Enable Bit

}

void TWI_Start(void)									// Start 2-wire Serial Interface
{
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);				// TWCR = (TWINT: TWI Interrupt Flag) + (TWSTA: TWI START Condition Bit) + (TWEN: TWI Enable Bit)

	while (get_bit(TWCR,TWINT)==0)
	{
		//
	}
}

void TWI_Stop(void)										// Stop 2-wire Serial Interface
{
	TWCR=(1<<TWSTO)|(1<<TWEN)|(1<<TWINT);				// TWCR = (TWSTO: TWI STOP Condition Bit) + (TWEN: TWI Enable Bit) + (TWINT: TWI Interrupt Flag)
}


void TWI_Write(uint8_t data)							// 2-wire write to TWDR – TWI Data Register
{
	TWDR=data;

	TWCR= (1<<TWINT)|(1<<TWEN);							// TWCR = (TWINT: TWI Interrupt Flag) + (TWEN: TWI Enable Bit)

	while (get_bit(TWCR,TWINT)==0)
	{

	}

}

void TWI_Read_Nack(uint8_t* ptr)						// The function argument is a pointer to a memory place in the MCU to store the received data in
{
	TWCR=(1<<TWINT)|(1<<TWEN);							// TWCR = (TWINT: TWI Interrupt Flag) + (TWEN: TWI Enable Bit)

	while (get_bit(TWCR,TWINT)==0)
	{

	}

	*ptr=TWDR;

}