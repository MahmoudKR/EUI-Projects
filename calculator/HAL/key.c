/*
 * key.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud A. Monaim
 */
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
#include "Dio.h"
#include "MyP_Types.h"
#include "lcd.h"
#include "key.h"
#include "calculator.h"

void KeyPadInit ()
{
    init_port(PORTB);

    make_output(PORTB, 0);
    make_output(PORTB, 1);
    make_output(PORTB, 2);
    make_output(PORTB, 3);

    Set_bit(GPIO_PORTB_DATA_R,0);
    Set_bit(GPIO_PORTB_DATA_R,1);
    Set_bit(GPIO_PORTB_DATA_R,2);
    Set_bit(GPIO_PORTB_DATA_R,3);

    make_input_UP(PORTB, 4);
    make_input_UP(PORTB, 5);
    make_input_UP(PORTB, 6);
    make_input_UP(PORTB, 7);


    arr[0][0] ='1';
    arr[0][1] ='2';
    arr[0][2] ='3';
    arr[0][3] ='+';

    arr[1][0] ='4';
    arr[1][1] ='5';
    arr[1][2] ='6';
    arr[1][3] = '-';

    arr[2][0] ='7';
    arr[2][1] ='8';
    arr[2][2] ='9';
    arr[2][3] ='/';

    arr[3][0] ='*';
    arr[3][1] ='0';
    arr[3][2] ='#';
    arr[3][3] ='=';

}

void which_is_pressed ()
{

    Uint8_t i,j;
    for (i=0;i<4;i++)
    {
        Clear_bit(GPIO_PORTB_DATA_R,i);
        delay (1);
        for (j=0;j<4;j++)
        {
          if ((GPIO_PORTB_DATA_R & (1<<(j+4)))==0)
          {
              send_char(arr[i][j]);
              data [k]=arr[i][j];
              counter ++;
              k++;
              if (i==3 & j==3)
              {
                  get_operationseration();
                  calculate();
                  break;
              }
          }
        }
        Set_bit(GPIO_PORTB_DATA_R,i);
    }

}

