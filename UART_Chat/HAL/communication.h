/*
 * communication.h
 *
 *  Created on: Sep 2, 2023
 *      Author: pc
 */

#ifndef HAL_COMMUNICATION_H_
#define HAL_COMMUNICATION_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

void UART_INIT();
void UART_SEND(char x);
char UART_REC();

#endif /* HAL_COMMUNICATION_H_ */
