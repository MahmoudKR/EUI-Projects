/*
 * DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef DIO_H_
#define DIO_H_
#include "Libraries\MyP_Types.h"

void GPIO_init_port(Int32_t port);
void GPIO_set_input (Int32_t port , Int32_t bit,Int32_t pull);
void GPIO_set_output (Int32_t port , Int32_t bit);

enum {PORTA,PORTB,PORTC,PORTD,PORTE,PORTF};
enum {HIGH,LOW};
enum {PULLUP,PULLDOWN};

#endif /* DIO_H_ */
