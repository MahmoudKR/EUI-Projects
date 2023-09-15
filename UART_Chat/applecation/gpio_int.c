/*
 * gpio_int.c
 *
 *  Created on: Sep 6, 2023
 *      Author: pc
 */
#include "gpio_int.h"
void gpio_init(void)
{
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LEDS);
//    GPIOPadConfigSet(GPIO_PORTF_BASE, PINS, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
//
//    GPIOIntEnable(GPIO_PORTF_BASE, PINS);
//    GPIOIntTypeSet(GPIO_PORTF_BASE, PINS, GPIO_LOW_LEVEL);
//    IntPrioritySet(INT_GPIOF, 0);
//    IntRegister(INT_GPIOF, GPIOIntHandler);
//    IntEnable(INT_GPIOF);
//    IntMasterEnable();

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_0);

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);





}

//void GPIOIntHandler(void){
//
//    counter++;
//    if(counter==3)
//    {
//        counter=0;
//    }
//
//
//
//    }

