/*
 * systick.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud A. Monaim
 */

#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
#include "Dio.h"
#include "MyP_Types.h"


void delay (Uint16_t t)
{
    NVIC_ST_RELOAD_R= (t*4000)-1;
    Set_bit(NVIC_ST_CTRL_R,0);
    while (!(NVIC_ST_CTRL_R&(1<<16)));// waiting
    NVIC_ST_CURRENT_R=0; // stops timer
    Clear_bit(NVIC_ST_CTRL_R,0);


}
