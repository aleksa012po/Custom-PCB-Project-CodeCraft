Custom PCB Project 
CodeCraft

This project involves the design and implementation of a custom PCB with the following specifications:

Components Used
- MCU: atMega328p
- USB to UART Converter: FTDI FT232RL
- Piezzo Buzzer: BC546 NPN Transistor
- Real-Time Clock: DS1307
- Battery Holder: CR2032 for RTC
- EEPROM: 24LC256
- Serial Flash Memory: W25Q16JV (SPI)
- Voltage Regulators: BSS138 (3 units) for SPI W25Q16JV pins
- Linear Regulator: RT9080-33GJ5 for 5V and 3.3V outputs
- Crystal: 16MHz
- ICSP pins
- Reset jumper pin
- RGB LEDs: WS2812B (3 units)
- Voltage Output Pins: 4 pins (3.3V, 5V, GND, GND)
- Port Input/Output Pins: 8 pins (SCL, SDA, CLK, MISO, MOSI, SS, TX, RX)
- Second Port Input/Output Pins: 8 pins (PD2, PD3, PD4, PD5, PD6, PD7, PB0, PB1) from atMega328p
- Built-in LED
- Built-in RX/TX LEDs
- 
WinApi Code
The provided WinApi code establishes communication with the custom PCB through a serial port. 
It allows you to select and execute various programs on the PCB by sending commands via 
the serial connection. 
The available programs include:

1.UART LED Blink: Control the onboard LED with different blinking patterns.
2. PWM LED: Control the brightness of an LED using pulse-width modulation.
3. RGB WS2812 Effect: Apply different effects to the RGB LEDs.
4. Buzzer Music Box: Play music using the buzzer.
5. Buzzer Virtual Keyboard: Use the PCB as a virtual keyboard to play tunes.
6. SPI Flash Memory: Read various data from the SPI flash memory.
7. I2C RTC and EEPROM Memory: Read data from the I2C RTC and EEPROM memory.
8. 
To use the WinApi code, you need to compile and run it, and then follow the on-screen instructions
to select and execute the desired program.

Atmel Studio Code
The provided C program is written in Atmel Studio and is designed to run on the custom PCB. 
It includes various modules for controlling different features of the PCB, such as 
LED blinking, PWM control, RGB effects, UART communication, buzzer control, SPI communication,
and I2C communication.

To use the Atmel Studio code, you need to compile and flash it onto the custom PCB's MCU (atMega328p).
The code will enable the PCB to receive commands from the WinApi program and perform the corresponding actions.

Please make sure to include all necessary libraries and dependencies when using the provided code.

Feel free to customize the code and PCB design as per your requirements. Good luck with your project!

Note: Remember to provide detailed instructions on how to set up and use the custom PCB, including 
any additional hardware or software requirements.

![CodeCraft](https://github.com/aleksa012po/Custom-PCB-Project-CodeCraft/assets/102791994/bec13eca-b105-4d1e-9805-cc34ed47607e)
![CodeCraft PCB](https://github.com/aleksa012po/Custom-PCB-Project-CodeCraft/assets/102791994/ae64216e-5487-4005-a97b-5119e390cecd)
