/*
 * eeprom_define.h
 *
 * Created: 23.1.2023. 09:51:39
 *  Author: Aleksandar Bogdanovic
 */ 

#ifndef EEPROM_DEFINE_H_
#define EEPROM_DEFINE_H_

#define EE24LC256_ReadMode				0xA1
#define EE24LC256_WriteMode				0xA0
#define ADDRESS_HIGH_BYTE				0x01
#define ADDRESS_LOW_BYTE				0x02
#define LED_DELAY						120
#define EEPROM_DELAY					100
#define EEPROM_ADDRESS					0x50
#define CHECK_BYTE						0xAB

#endif /* EEPROM_DEFINE_H_ */