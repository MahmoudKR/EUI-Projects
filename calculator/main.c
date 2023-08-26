/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud A. Monaim
 */
#include "LIB/tm4c123gh6pm.h"
#include "LIB/bitwise_operations.h"
#include "MCAL/Dio.h"
#include "LIB/MyP_Types.h"
#include "HAL/lcd.h"
#include "HAL/key.h"
#include "HAL/calculator.h"



Int32_t main ()
{
    lcd_init();
    KeyPadInit();
    //send_digit(-123);

    k = 0;
    counter = 0;

  while (1)
    {
       delay (200);
       which_is_pressed ();
    }


    return 0;
}




