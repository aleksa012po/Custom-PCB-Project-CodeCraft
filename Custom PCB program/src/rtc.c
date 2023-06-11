/*
 * rtc.c
 *
 * Created: 19.1.2023. 00:32:11
 *  Author: Aleksandar Bogdanovic
 */ 

#include "config.h"
#include "rtc_define.h"
#include <avr/io.h>
#include <util/delay.h>


void RTC_write (uint8_t data, uint8_t address) // Write to RTC
{
	// Setup time and date that will be displayed
	uint8_t second, minute, hour, day, date, month, year;

	year	= 0x23;
	month	= 0x06;
	date	= 0x04;
	day		= 0x01;
	hour	= 0x23;
	minute	= 0x42;
	second	= 0x01;
	
// --------------------------------
	// Year
	TWI_Start();

	TWI_Write(DS3231_WriteMode);	// Master address is 1010 and a 0 in the 4th bit to indicate WRITING
	
	TWI_Write(DS3231_REG_Year);		// Year address
	
	TWI_Write(year);				// 2023.

	TWI_Stop();
// --------------------------------
	// Month
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Month);	// Month address
	
	TWI_Write(month);				// 01 - January

	TWI_Stop();
// --------------------------------
	// Date
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Date);		// Date address
	
	TWI_Write(date);				// 23.

	TWI_Stop();
// --------------------------------
	// Week day (01 - 07, 01 = Sunday)
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Day);		// Day of the week
	
	TWI_Write(day);					// Monday

	TWI_Stop();
// --------------------------------
	// Hours
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Hour);		// Hours
	
	TWI_Write(hour);				// 00

	TWI_Stop();
// --------------------------------
	// Minutes
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Minutes);	// Minutes
	
	TWI_Write(minute);				// 31

	TWI_Stop();
// --------------------------------
	// Seconds
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Seconds);	// Seconds
	
	TWI_Write(second);				// 51

	TWI_Stop();
}

void RTC_read (char address, char* ptr)// The function arguments are an address in the EEPROM to read from and a pointer to a memory place in the MCU to store the read data in
{
	// Year
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Year);		// Year address

	TWI_Start();

	TWI_Write(DS3231_ReadMode);		// Master address is 1011 and a 1 in the 4th bit to indicate READING

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Month
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Month);	// Month address
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Date
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Date);		// Date address
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Week day (01 - 07, 01 = Sunday)
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Day);		// Day of the week
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Hours
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Hour);		// Hours
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Minutes
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Minutes);	// Minutes

	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Seconds
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Seconds);	// Seconds
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
}

void RTC_setup()
{
	TWI_Init();
	
	uint8_t byte, stored;
	
	RTC_write(byte, DS3231_REG_RTC_ADDRESS);
	_delay_ms(100);
	RTC_read(DS3231_REG_RTC_ADDRESS, &stored);
}
