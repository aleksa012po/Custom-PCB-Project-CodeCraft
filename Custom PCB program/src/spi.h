/*
 * spi.h
 *
 * Created: 8.6.2023. 00:13:32
 *  Author: user
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

void SPI_init();
void enable_SPI();
void disable_SPI();
uint8_t write_byte(uint8_t data);
void enable_reset();
void reset_device();
void write_enable_status_reg();
void write_enable();
void write_disable();
void block_erase();
void chip_erase();
void status_register1();
void status_register2();
void status_register3();
void write_status_register1();
void write_status_register2();
void write_status_register3();
void page_program();
void read_data();
void read_flash_id();
void read_jedec_id();
void read_manufacturer_id();
void write_data(uint32_t address, uint8_t *data, uint16_t length);


#endif /* SPI_H_ */