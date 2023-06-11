/*
 * rtc_define.h
 *
 * Created: 23.1.2023. 00:59:16
 *  Author: Aleksandar Bogdanovic
 */ 

#ifndef RTC_DEFINE_H_
#define RTC_DEFINE_H_

#define DS3231_ReadMode             0xD1
#define DS3231_WriteMode            0xD0
#define DS3231_REG_Seconds          0x00
#define DS3231_REG_Minutes          0x01
#define DS3231_REG_Hour             0x02
#define DS3231_REG_Day              0x03
#define DS3231_REG_Date             0x04
#define DS3231_REG_Month            0x05
#define DS3231_REG_Year             0x06
#define DS3231_REG_RTC_ADDRESS      0x68

#endif /* RTC_DEFINE_H_ */