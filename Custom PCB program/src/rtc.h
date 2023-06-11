/*
 * rtc.h
 *
 * Created: 19.1.2023. 00:33:52
 *  Author: Aleksandar Bogdanovic
 */ 

#ifndef RTC_H_
#define RTC_H_

void RTC_write(uint8_t data, uint8_t address);
void RTC_read(char address, char* ptr);
void RTC_setup();

#endif /* RTC_H_ */