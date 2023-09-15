/*
 * gpio_int.h
 *
 *  Created on: Sep 6, 2023
 *      Author: pc
 */

#ifndef APPLECATION_GPIO_INT_H_
#define APPLECATION_GPIO_INT_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"



//
void gpio_init(void);


#endif /* APPLECATION_GPIO_INT_H_ */
