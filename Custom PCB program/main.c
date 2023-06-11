/*
 * C_Zavrsni_program.c
 *
 * Created: 5.6.2023. 00:32:41
 * Author : Aleksandar Bogdanovic
 */ 

// All defines

#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/ws2811.h"
#include "src/blink_led.h"
#include "src/defines.h"
#include "src/pwm.h"
#include "src/rgb.h"
#include "src/uart.h"
#include "src/sstring.h"
#include "src/tones.h"
#include "src/delay_ms.h"
#include "src/blink_led.h"
#include "src/keyboard.h"
#include "src/spi.h"
#include "src/rtc.h"
#include "src/eeprom.h"
#include "src/twi.h"
#include <avr/wdt.h>

volatile uint8_t data = 0;
volatile uint8_t receivedChar = 0;

int main(void)
{
	UART_Init(14400);
	RGB_init();
	SPI_init();
	while (1)
	{
		uart_start(&data);
		switch (data)
		{
			case 0x1a:
			{
				blinkLED(500, 500, 5);
				break;
			}
			case 0x1b:
			{
				blinkLED(1000, 1000, 4);
				break;
			}
			case 0x1c:
			{
				blinkLED(1500, 1500, 3);
				break;
			}
			case 0x1d:
			{
				blinkLED(2000, 2000, 2);
				break;
			}
			
			case 0x2a:
			{
				PinInit();
				pwmSetup();
				pwmLEDControl(5);
				pwmOff();
				break;
			}
			case 0x2b:
			{
				PinInit();
				pwmSetup();
				pwmLEDControl(10);
				pwmOff();
				break;
			}
			case 0x2c:
			{
				PinInit();
				pwmSetup();
				pwmLEDControl(20);
				pwmOff();
				break;
			}
			case 0x2d:
			{
				PinInit();
				pwmSetup();
				pwmLEDControl(25);
				pwmOff();
				break;
			}
			case 0x2e:
			{	
				PinInit();
				pwmSetup();
				pwmLEDControl(50);
				pwmOff();
				break;
			}
			case 0x2f:
			{
				PinInit();
				pwmSetup();
				pwmLEDControl(100);
				pwmOff();
				break;
			}
					
			case 0x3a:
			{
				breathingEffect();
				break;
			}
			case 0x3b:
			{
				 initMillisTimer();
				Color_Effect();
				break;
			}
			case 0x4a:
			{
				InterstellarTheme();
				break;
			}
			case 0x4b:
			{
				LinkingParkTheme();
				break;
			}
			case 0x05:
			{
				receivedChar = 0; 

				while (1)
				{
					audioON();
					receivedChar = UDR0;
					if (receivedChar == 'q')
					{
						break; 
					}
				}
				break;
			}
			case 0x6a:
			{
				read_jedec_id();
				break;
			}
			case 0x6b:
			{
				read_flash_id();
				break;
			}
			case 0x6c:
			{
				write_disable();
				read_data();
				break;
			}
			case 0x7a:
			{
				EEPROM_setup();
				break;
			}
			case 0x7b:
			{
				RTC_setup();
				break;
			}

			default:
			{
				ErrorBeepAndSound();
				break;
			}
		}
	}

	return 0;
}


ISR(TIMER2_OVF_vect)
{
	OCR2B = (dutyCycle / 100.0) * 255;
}


