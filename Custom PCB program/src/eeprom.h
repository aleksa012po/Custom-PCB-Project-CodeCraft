/*
 * eeprom.h
 *
 * Created: 17.1.2023. 01:45:57
 *  Author: Aleksandar Bogdanovic
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_Write (char data, char address);
void EEPROM_Read (char address, char* ptr);
void EEPROM_setup();
void led_notif();
void led_on();

#endif /* EEPROM_H_ */