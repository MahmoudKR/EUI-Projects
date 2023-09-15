/*
 * app.h
 *
 *  Created on: Sep 3, 2023
 *      Author: pc
 */

#ifndef APPLECATION_APP_H_
#define APPLECATION_APP_H_


#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "HAL/UART/UART.h"
#include "applecation/gpio_int.h"
/**
 * main.c
 */

#define max 20
#define error_message "error exceded max number of letters"

void RW(char*arr,char *arr2,int *index,int *index2 );
void screen_print(char*arr,int index);
void app(void);
void read_only(char *arr2,int *index2 );

#endif /* APPLECATION_APP_H_ */
