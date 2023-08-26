/*
 * calculator.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
#include "Dio.h"
#include "MyP_Types.h"
#include "lcd.h"
#include "key.h"

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
