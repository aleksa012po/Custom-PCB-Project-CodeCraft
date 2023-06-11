#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <fileapi.h>

#define COM_PORT "COM7"

    HANDLE hSerial;
    DCB dcbSerialParams = { 0 };
    COMMTIMEOUTS timeout;
    BOOL bStatus;
    BOOL skipSwitch;

int openSerialPort()
{

    hSerial = CreateFile("\\\\.\\COM7", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hSerial == INVALID_HANDLE_VALUE)
    {
        printf("Failed to open COM port %d\n", COM_PORT);
        return 1;
    }
    /*else
        printf("-------------------------------\nSuccessfully connected to %s\n", COM_PORT);*/

    // Configure the serial port
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    bStatus = GetCommState(hSerial, &dcbSerialParams);
    if (bStatus == FALSE)
    {
        printf("Error setting up UART parameters\n");
        CloseHandle(hSerial);
        return 1;
    }
    /*else
        printf("-------------------------------\nSuccessfully setting up UART parameters\n-------------------------------\n");*/


    dcbSerialParams.BaudRate = CBR_14400;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    bStatus = SetCommState(hSerial, &dcbSerialParams);
    if (bStatus == FALSE)
    {
        printf("Failed to set UART serial parameters.\n");
        CloseHandle(hSerial);
        return 1;
    }
    else
        printf("          *****************\n");
        printf("          *               *\n");
        printf("          *   CodeCraft   *\n");
        printf("          *               *\n");
        printf("          *****************\n");
        printf("\n");

    COMMTIMEOUTS timeouts = { 0 };
    GetCommTimeouts(hSerial, &timeout);
    GetCommState(hSerial, &dcbSerialParams);
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(hSerial, &timeouts))
        {
        printf("Failed to set COM port timeouts\n");
        return 1;
    }
}

void closeSerialPort()
{
    CloseHandle(hSerial);
}

void sendCharacter(char character)
{
    DWORD bytesWritten;
    WriteFile(hSerial, &character, 1, &bytesWritten, NULL);
}

int main()
{
    openSerialPort();

    char selectedProgram = 0;
        printf("-------------------------------\n\r");
        printf("Select a program from 1 to 7: \n\n");

        printf("*********************\n");
        printf("*1. UART LED Blink: *\n");
        printf("*********************\n");
        printf("a. LED ON and OFF  500ms, repetition 5 times,\n");
        printf("b. LED ON and OFF 1000ms, repetition 4 times,\n");
        printf("c. LED ON and OFF 1500ms, repetition 3 times,\n");
        printf("d. LED ON and OFF 2000ms, repetition 2 times.\n\n");

        printf("**************\n");
        printf("*2. PWM LED: *\n");
        printf("**************\n");
        printf("a. increment level of   5%%,\n");
        printf("b. increment level of  10%%,\n");
        printf("c. increment level of  20%%,\n");
        printf("d. increment level of  25%%,\n");
        printf("e. increment level of  50%%,\n");
        printf("f. increment level of 100%%.\n\n");

        printf("************************\n");
        printf("*3. RGB WS2812 effect: *\n");
        printf("************************\n");
        printf("a. Breathing Effect,\n");
        printf("b. Color Effect.\n\n");

        printf("***********************\n");
        printf("*4. Buzzer Music Box: *\n");
        printf("***********************\n");
        printf("a. Interstellar_theme,\n");
        printf("b. LinkinPark_Theme.\n\n");

        printf("******************************\n");
        printf("*5. Buzzer Virtual keyboard: *\n");
        printf("******************************\n\n");

        printf("***********************\n");
        printf("*6. SPI flash memory: *\n");
        printf("***********************\n");
        printf("a. Read jedec ID,\n");
        printf("b. Read flash ID,\n");
        printf("c. Read data from page program.\n\n");

        printf("********************************\n");
        printf("*7. I2C RTC and EEPROM memory: *\n");
        printf("********************************\n");
        printf("a. Read EEPROM memory,\n");
        printf("b. Read RTC memory.\n");
        printf("-------------------------------\n\r");
        printf("\n");
        fflush(stdout);

         while (1)
            {
                printf("Select a program from 1 to 7: \n\n");

                char userInput[4];
                scanf("%2s", userInput);  // Read up to 2 characters (e.g., '1a', '1b', etc.)
                getchar();  // Clear newline character from the input buffer

                char* endptr;   // Convert userInput to hexadecimal value
                unsigned int result = strtol(userInput, &endptr, 16);

                switch (userInput[0])
                {
                    case '1':
                        printf("\n");
                        // Handle level 1 commands

                        switch (userInput[1])
                        {
                            case 'a':
                                printf("*LED ON and OFF 500ms, repetition 5 times.*\n\n");
                                sendCharacter(result);

                                // Perform actions for level 1
                                break;

                            case 'b':
                                printf("*LED ON and OFF 1000ms, repetition 4 times.*\n\n");
                                sendCharacter(result);

                                // Perform actions for level 2
                                break;

                            case 'c':
                                printf("*LED ON and OFF 1500ms, repetition 3 times.*\n\n");
                                sendCharacter(result);

                                // Perform actions for level 3
                                break;

                            case 'd':
                                printf("*LED ON and OFF 2000ms, repetition 2 times.*\n\n");
                                sendCharacter(result);
                                // Perform actions for level 4
                                break;

                            default:
                                printf("Invalid subcommand received.\nPlease choose subcommands from 'a' to 'd'.\n\n");
                                sendCharacter(result);
                                break;
                        }
                        break;

                    case '2':
                        printf("\n");

                        switch (userInput[1])
                        {
                            case 'a':
                                printf("*PWM - Chosen increment level:  5%%.*\n\n");
                                sendCharacter(result);
                                // Perform actions for 5% increment
                                break;

                            case 'b':
                                printf("*PMW - Chosen increment level: 10%%.*\n\n");
                                sendCharacter(result);
                                // Perform actions for 10% increment
                                break;

                            case 'c':
                                printf("*PWM - Chosen increment level: 20%%.*\n\n");
                                sendCharacter(result);
                                // Perform actions for 20% increment
                                break;

                            case 'd':
                                printf("*PWM - Chosen increment level: 25%%.*\n\n");
                                sendCharacter(result);
                                // Perform actions for 25% increment
                                break;

                            case 'e':
                                printf("*PWM - Chosen increment level: 50%%.*\n\n");
                                sendCharacter(result);
                                // Perform actions for 50% increment
                                break;

                            case 'f':
                                printf("*PWM - Chosen increment level: 100%%.*\n\n");
                                sendCharacter(result);
                                // Perform actions for 100% increment
                                break;

                            default:
                                sendCharacter(result);
                                break;
                        }
                        break;

                    case '3':
                        printf("\n");
                        // Handle level 3 commands
                        switch (userInput[1])
                        {
                            case 'a':
                                printf("*You have chosen the Breathing Effect.*\n\n");
                                sendCharacter(result);
                                break;

                            case 'b':
                                printf("*You have chosen the Color Effect.*\n\n");
                                sendCharacter(result);
                                break;

                            default:
                                printf("Please choose letters 'a' or 'b'.\n\n");
                                sendCharacter(result);
                                break;
                        }
                        break;

                    case '4':
                        printf("\n");
                        switch (userInput[1])
                        {
                            case 'a':
                                printf("*You have chosen the Interstellar_theme.*\n\n");
                                sendCharacter(result);
                                break;

                            case 'b':
                                printf("*You have chosen the LinkinPark_Theme.*\n\n");
                                sendCharacter(result);
                                break;

                            default:
                                printf("*Please choose letters 'a' or 'b'.*\n\n");
                                sendCharacter(result);
                                break;
                        }
                        break;

                    case '5':
                        while (result == 5)
                        {
                            printf("\n");
                            printf("*You have chosen the virtual keyboard program. PLAY A TUNE PLEASE!*\n\n");
                            sendCharacter(result);

                            while (1)
                            {
                                char userInput = getch();
                                sendCharacter(userInput);
                                if (userInput == 'q')
                                    {
                                        sendCharacter('q');
                                        break;
                                    }
                            }
                            break;
                        }
                        while (result != 5)
                        {
                            skipSwitch = true;
                            sendCharacter(result);
                            break;
                        }
                        break;

                    default:
                        printf("*Invalid command received!\nPlease choose commands from '1' to '7'.*\n\n");
                        sendCharacter(result);
                        break;


                    case '6':
                         printf("\n");
                        switch (userInput[1])
                        {
                            case 'a':
                                printf("*You have chosen to read jedec ID.*\n\n");
                                sendCharacter(result);
                                break;

                            case 'b':
                                printf("*You have chosen to read flash ID.*\n\n");
                                sendCharacter(result);
                                break;

                            case 'c':
                                printf("*You have chosen to read data from page program.*\n\n");
                                sendCharacter(result);
                                break;

                            default:
                                printf("*Please choose letters 'a', 'b' or 'c'.*\n\n");
                                sendCharacter(result);
                                break;
                        }
                        break;

                    case '7':
                        printf("\n");
                        switch (userInput[1])
                        {
                            case 'a':
                                printf("*You have chosen to read EEPROM memory.*\n\n");
                                sendCharacter(result);
                                break;

                            case 'b':
                                printf("*You have chosen to read RTC memory.*\n\n");
                                sendCharacter(result);
                                break;

                            default:
                                printf("*Please choose letters 'a' or 'b'.*\n\n");
                                sendCharacter(result);
                                break;
                        }
                        break;

                }

    }

    closeSerialPort();

    return 0;
}
