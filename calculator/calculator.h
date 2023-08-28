/*
 * calculator.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "LIB/tm4c123gh6pm.h"
#include "LIB/bitwise_operations.h"
#include "MCAL/Dio.h"
#include "LIB/MyP_Types.h"
#include "HAL/lcd.h"
#include "HAL/key.h"

int digits[16];
char operations[16];
char data [16];

Uint8_t counter;


void calculate();
void get_operation(char arr[],int size);
void sort_operations (Int32_t index);
void shift(Int32_t index);
void HandlePP ();
void HandleM ();

#endif /* CALCULATOR_H_ */
