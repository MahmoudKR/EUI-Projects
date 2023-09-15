/*
 * UART.h
 *
 *  Created on: Sep 3, 2023
 *      Author: pc
 */


#ifndef HAL_UART_UART_H_
#define HAL_UART_UART_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"



void UART0_INIT(void);
char UART0_REC(void);
void UART0_SEND_char(char c);
void UART0_SEND_STRING(char *c);

void UART5_INIT(void);
char UART1_REC(void);
void UART1_SEND_char(char c);
void UART1_SEND_STRING(char *arr);

void screen_READ_STRING(char*arr,char* s);

#endif /* HAL_UART_UART_H_ */


