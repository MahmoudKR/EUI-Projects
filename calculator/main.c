/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud A. Monaim
 */
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
#include "Dio.h"
#include "MyP_Types.h"
#include "lcd.h"
#include "key.h"
#include "calculator.h"



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




