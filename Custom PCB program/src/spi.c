/*
 * C_Arduino_SPI_Flash_Memorija.c
 *
 * Created: 24.1.2023. 10:00:08
 * Author : Aleksandar Bogdanovic
 */

/********************************************/
/*					SPI Master				*/
/********************************************/
 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "spi_defines.h"

void SPI_init()
{
	DDRB |= (1 << SCK) | (1 << MOSI) | (1 << SS);
	PORTB |= (1 << SCK) | (1 << MOSI) | (1 << SS);					// Set MOSI, SCK, SS as output pins
	DDRB &= ~(1 << MISO);
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);	// Enable SPI, set as master, and set clock rate fck/128
}


void enable_SPI()
{
	PORTB &= ~(1 << SS);		// Set SS pin LOW to initiate communication
}

void disable_SPI()
{
	PORTB |= (1 << SS);			// Set SS pin HIGH to end communication
}

uint8_t write_byte(uint8_t data)
{
    SPDR = data;                // Load the data to be sent into the SPDR register
    while(!(SPSR & (1<<SPIF))); // Wait for the transmission to complete
    return SPDR;                // Return the received data
}

void enable_reset()
{
	enable_SPI();				
	write_byte(0x66);			// Enable Reset (66h)
	disable_SPI();
}

void reset_device()
{
	enable_SPI();				
	write_byte(0x99);			// Reset Device (99h)
	disable_SPI();
}

void write_enable_status_reg()
{
	enable_SPI();	
	write_byte(0x50);			// Write Enable for Volatile Status Register (50h)
	disable_SPI();
}

void write_enable()
{
	enable_SPI();
	write_byte(0x06);			// Send write enable command (06h)
	disable_SPI();
}

void write_disable()
{
	enable_SPI();				
	write_byte(0x04);			// Send write enable command (04h)
	disable_SPI();
}

void block_erase()
{
	enable_SPI();			
	write_byte(0xD8);			// Block Erase (64KB) (D8h)				
	write_byte(0x00);			// Security Register 1: A23-16 = 00h; A15-8 = 10h; A7-0 = byte address				
	write_byte(0x20);			// Address data
	write_byte(0x01);			// Address data
	disable_SPI();
}

void chip_erase()
{
	enable_SPI();			
	write_byte(0xC7);			// Chip Erase (C7h or 60h) 
	disable_SPI();
}

void status_register1()
{
	enable_SPI();		
	write_byte(0x05);			// Read Status Register-1 (05h) 
	// Receive status 1				
	write_byte(0x00);			// Misc data
	disable_SPI();
}

void status_register2()
{
	enable_SPI();				
	write_byte(0x35);			// Read Status Register-2 (35h) 
	// Receive status 1			
	write_byte(0x00);			// Misc data
	disable_SPI();
}

void status_register3()
{
	enable_SPI();				
	write_byte(0x15);			// Read Status Register-3 (15h) 
	// Receive status 1			
	write_byte(0x00);			// Misc data
	disable_SPI();
}

void write_status_register1()
{
	enable_SPI();				
	write_byte(0x01);			// Write Status Register-1 (01h)
	// Receive status 1			
	write_byte(0x00);			// Misc data
	disable_SPI();
}

void write_status_register2()
{
	enable_SPI();				
	write_byte(0x31);			// Write Status Register-2 (31h)
	// Receive status 1			
	write_byte(0x00);			// Misc data
	disable_SPI();
}

void write_status_register3()
{
	enable_SPI();			
	write_byte(0x11);			// Write Status Register-3 (11h)
	// Receive status 1				
	write_byte(0x00);			// Misc data
	disable_SPI();
}

void page_program()
{
	enable_SPI();
	write_byte(0x02);       // Page Program (02h)
	// Address data
	write_byte(0x00);       // Address data
	write_byte(0x20);       // Address data
	write_byte(0x01);       // Address data
	// Write bytes
	write_byte(0x43);       // 'C'
	write_byte(0x6F);       // 'o'
	write_byte(0x64);       // 'd'
	write_byte(0x65);       // 'e'
	write_byte(0x43);       // 'C'
	write_byte(0x72);       // 'r'
	write_byte(0x61);       // 'a'
	write_byte(0x66);       // 'f'
	write_byte(0x74);       // 't'
	disable_SPI();
}

void read_data()
{
	enable_SPI();			
	write_byte(0x03);			// Read Data (03h)
	// Address data				
	write_byte(0x00);			// Address data				
	write_byte(0x20);			// Address data			
	write_byte(0x01);			// Address data
	// Receive bytes
	for (int i = 0; i < 9; i++) 
	{
		write_byte(0x00);		// Misc data
	}				
	disable_SPI();
}

void read_flash_id() 
{
	enable_SPI();
	write_byte(0x4B);			// Read Flash memory UID (4Bh)
	for (int i = 0; i < 12; i++) 
	{
		write_byte(0xFF);
	}
	disable_SPI();
}

void read_jedec_id()
{
	enable_SPI();	
	write_byte(0x9F);			// Read JEDEC ID (9Fh)			
	for (int i = 0; i < 3; i++) 
	{
		write_byte(0x00);		// Misc data
	}				
	disable_SPI();
}

void read_manufacturer_id()
{
	enable_SPI();
	write_byte(0x90);			//Read Manufacturer / Device ID (90h)
	write_byte(0x00);
	write_byte(0x00);
	write_byte(0x00);
	disable_SPI();
}

void write_data(uint32_t address, uint8_t *data, uint16_t length)
{
	write_enable();		// Put the device into write-enabled state
	
	enable_SPI();
	write_byte(0x02);	// Send write command (02h)
	write_byte((address >> 16) & 0xFF);	// Send address - A23-16
	write_byte((address >> 8) & 0xFF);	// Send address - A15-8
	write_byte(address & 0xFF);			// Send address - A7-0
	
	data = 'A';
	for (uint16_t i = 0; i < length; i++) {
		write_byte(data[i]);	// Send data
	}
	disable_SPI();
	
	write_disable();	// Disable write
}

	// All the functions
	
	//-------------------------------
	//enable_reset();
	//-------------------------------
	//reset_device();
	//-------------------------------
	//read_jedec_id();
	//-------------------------------
	//read_flash_id();
	//-------------------------------
	// read_manufacturer_id();
	//-------------------------------
	//write_enable();
	//write_disable();
	//-------------------------------
	//block_erase();
	//-------------------------------
	//page_program();
	//-------------------------------
	//write_data(0x400000, &R, 2);
	//chip_erase();
	//-------------------------------
	//write_enable_status_reg();
	//-------------------------------
	//write_status_register1();
	//write_status_register2();
	//write_status_register3();
	//-------------------------------
	//status_register1();
	//status_register2();
	//status_register3();
	//-------------------------------
	//read_data();
	//-------------------------------
	
