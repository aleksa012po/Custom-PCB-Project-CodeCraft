/*
 * eeprom.c
 *
 * Created: 17.1.2023. 01:44:08
 *  Author: Aleksandar Bogdanovic
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "eeprom_define.h"

#define LED_PORT PORTD3

void EEPROM_Write (uint8_t data, uint8_t address)		// Write to EEEPROM
{
	data = 0xAB;
	
	TWI_Start();

	TWI_Write(EE24LC256_WriteMode);						// Master address is 1010 and a 0 in the 4th bit to indicate WRITING
	
	TWI_Write(ADDRESS_HIGH_BYTE);
	
	TWI_Write(ADDRESS_LOW_BYTE);

	TWI_Write(data);

	TWI_Stop();

}

void EEPROM_Read (char address, char* ptr)// The function arguments are an address in the EEPROM to read from and a pointer to a memory place in the MCU to store the read data in
{	
	TWI_Start();

	TWI_Write(EE24LC256_WriteMode);
	
	TWI_Write(ADDRESS_HIGH_BYTE);
	
	TWI_Write(ADDRESS_LOW_BYTE);

	TWI_Start();

	TWI_Write(EE24LC256_ReadMode);						// Master address is 1011 and a 1 in the 4th bit to indicate READING

	TWI_Read_Nack(ptr);

	TWI_Stop();
}

void led_on()
{
	DDRD = 0xFF;
	PORTD |= (1 << LED_PORT);
}

void led_notif()
{
	led_on();
		_delay_ms(LED_DELAY);
		PORTD &= ~(1 << LED_PORT);
		_delay_ms(LED_DELAY);
		led_on();
		_delay_ms(LED_DELAY);
		PORTD &= ~(1 << LED_PORT);
		_delay_ms(LED_DELAY);
}

void EEPROM_setup()
{
	uint8_t e_read, byte;
	EEPROM_Write(byte, EEPROM_ADDRESS);
	_delay_ms(EEPROM_DELAY);
	EEPROM_Read(EEPROM_ADDRESS, &e_read);
	
	if (e_read == CHECK_BYTE)
	{
		led_notif();								// LED On function
	}
	else
	{
		PORTD &= ~(1 << LED_PORT);					// Turn off
	}
}
