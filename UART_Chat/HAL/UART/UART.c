/*
 * UART.c
 *
 *  Created on: Sep 3, 2023
 *      Author: pc
 */


#include "UART.h"


void UART0_INIT(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                UART_CONFIG_PAR_NONE));

}
void UART5_INIT(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

    GPIOPinConfigure(GPIO_PE4_U5RX);
    GPIOPinConfigure(GPIO_PE5_U5TX);

    GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                UART_CONFIG_PAR_NONE));

}


char UART0_REC(void)
{
    char cThisChar;
    cThisChar = UARTCharGet(UART0_BASE);
    return cThisChar;

}

void UART0_SEND_char(char c)
{
    UARTCharPut(UART0_BASE, c);
}



char UART1_REC(void)
{
    char cThisChar;
    cThisChar = UARTCharGet(UART1_BASE);
    return cThisChar;

}

void UART1_SEND_char(char c)
{
    UARTCharPut(UART1_BASE, c);
}



void UART0_SEND_STRING(char *arr)
{
    int i=0;
    for(i=0;arr[i]!='\0';i++)
    {
        UARTCharPut(UART0_BASE, arr[i]);
    }
}
void UART1_SEND_STRING(char *arr)
{
    int i=0;
    for(i=0;arr[i]!='\0';i++)
    {
        UARTCharPut(UART1_BASE, arr[i]);
    }
}

void screen_READ_STRING(char*arr,char* s)
{
    int i;
    char arr2[100];

    do{
        arr2[*s]=UARTCharGet(UART0_BASE);
        (*s)++;
        UARTCharPut(UART0_BASE, arr2[*s]);
    }while((arr2[*s] != '\n') && (arr2[*s] != '\r'));

    UARTCharPut(UART0_BASE, '\n');

    for(i=0;i<(*s);i++)
    {
        UARTCharPut(UART0_BASE, arr2[i]);
    }
}
