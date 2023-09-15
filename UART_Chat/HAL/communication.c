/*
 * communication.c
 *
 *  Created on: Sep 2, 2023
 *      Author: pc
 */
#include "communication.h"

void UART_INIT()
{


    //
    // Enable the UART0 module.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    //
    // Wait for the UART0 module to be ready.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
    {
    }
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                UART_CONFIG_PAR_NONE));
}

void UART_SEND(char x)
{
    UARTEnable(UART0_BASE);
    UARTCharPut(UART0_BASE, x);

    //
    // Put a character in the output buffer.
    //
    //UARTCharPut(UART0_BASE, 'c');
    //
    // Disable the UART.
    //
    UARTDisable(UART0_BASE);
}
char UART_REC()
{
    char x;
    UARTEnable(UART0_BASE);
    x = UARTCharGet(UART0_BASE);
    UARTDisable(UART0_BASE);
    return x;
}

