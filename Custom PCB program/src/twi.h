/*
 * twi.h
 *
 * Created: 19.1.2023. 00:25:22
 *  Author: Aleksandar Bogdanovic
 */ 

#ifndef TWI_H_
#define TWI_H_

void TWI_Init (void);
void TWI_Start (void);
void TWI_Stop (void);
void TWI_Write (char data);
void TWI_Read_Nack (char* ptr);

#endif /* TWI_H_ */