/*
 * lcd.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Mahmoud A. Monaim
 */
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
#include "Dio.h"
#include "MyP_Types.h"

void lcd_init()
{
    init_port(PORTE);
    init_port(PORTA);


    make_output(PORTA, 4); //D4
    make_output(PORTA, 5); //D5
    make_output(PORTA, 6); //D6
    make_output(PORTA, 7); //D7


    make_output(PORTE, 2); //enable pin
    make_output(PORTE, 1); //rs

    send_command(0x03);
    send_command(0x03);
    send_command(0x02);
    send_command(0x28);
    send_command(0x01);
    send_command(0x0f);
}
void send_bytes(Uint8_t b)
{
    Uint8_t data_h = (b&0xf0);
    Uint8_t data_l = (b<<4);


    Set_bit(GPIO_PORTE_DATA_R,2);
    delay(1);
    GPIO_PORTA_DATA_R= data_h;
    delay(1);
    Clear_bit(GPIO_PORTE_DATA_R,2);
    delay(1);

    Set_bit(GPIO_PORTE_DATA_R,2);
    delay(1);
    GPIO_PORTA_DATA_R=data_l;
    delay(1);
    Clear_bit(GPIO_PORTE_DATA_R,2);
    delay(1);


}
void send_command (Uint8_t c)
{
    Clear_bit(GPIO_PORTE_DATA_R, 1);
    send_bytes(c);
}

void send_char (Uint8_t d)
{
    Set_bit(GPIO_PORTE_DATA_R,1);
    send_bytes(d);
}

void send_digit(Int32_t digit)
{
    Set_bit(GPIO_PORTE_DATA_R,1);

    Int8_t d [16];
    Int8_t i=0;

    if (digit<0)
    {
        send_bytes(45);// sends a -ve sign.
        send_digit(0-digit);

    }
    else
    {
        while(digit)
        {
            d[i]= (digit%10)+48;
            digit/=10;
            i++;
        }
        for (--i;i>0;i--)
        {
            send_bytes(d[i]);
        }
        send_bytes(d[i]);
    }
}


