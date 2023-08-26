/*
 * DIO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud A. Monaim
 */


#include "Libraries\tm4c123gh6pm.h"
#include "Libraries\bitwise.h"
#include "Dio.h"
#include "Libraries\MyP_Types.h"


void GPIO_init_port(Int32_t port)
{

    switch(port)
    {
    case 0:                                  //port A
        SYSCTL_RCGCGPIO_R|=(1<<0);           //CONNECT CLOCK TO PORTA
        while(SYSCTL_RCGCGPIO_R&(1<<0)==0){} //BOOLING TO CHECK PORTA CONNECTION IS ON
        GPIO_PORTA_LOCK_R=0X4C4F434B;
        GPIO_PORTA_CR_R=0XF0;                //UNLOCKING PORT A
        GPIO_PORTA_DEN_R = 0XF0;             //MAKE DIGITAL;

        break;


    case 1: //port B
        SYSCTL_RCGCGPIO_R|=(1<<1); //CONNECT CLOCK TO PORTB
        while(SYSCTL_RCGCGPIO_R&(1<<1)==0){} //BOOLING TO CHECK PORTB CONNECTION IS ON
        GPIO_PORTB_LOCK_R=0X4C4F434B;
        GPIO_PORTB_CR_R=0XFF;          //UNLOCKING PORT B
        GPIO_PORTB_DEN_R = 0XFF;//MAKE DIGITAL;
        //Port B does not need locking
        break;


    case 2: //port C
        SYSCTL_RCGCGPIO_R|=(1<<2); //CONNECT CLOCK TO PORTC
        while(SYSCTL_RCGCGPIO_R&(1<<2)==0){} //BOOLING TO CHECK PORTC CONNECTION IS ON
        GPIO_PORTC_LOCK_R=0X4C4F434B;
        GPIO_PORTC_CR_R=0X1F;          //UNLOCKING PORT c
        GPIO_PORTC_DEN_R = 0X1F;//MAKE DIGITAL;
        //port c need locking
        break;


    case 3: //port D
        SYSCTL_RCGCGPIO_R|=(1<<3); //CONNECT CLOCK TO PORTD
        while(SYSCTL_RCGCGPIO_R&(1<<3)==0){} //BOOLING TO CHECK PORTD CONNECTION IS ON
        GPIO_PORTD_LOCK_R=0X4C4F434B;
        GPIO_PORTD_CR_R=0XFF;          //UNLOCKING PORT D
        GPIO_PORTD_DEN_R = 0XFF;//MAKE DIGITAL;
        break;


    case 4: //port E
        SYSCTL_RCGCGPIO_R|=(1<<4); //CONNECT CLOCK TO PORTE
        while(SYSCTL_RCGCGPIO_R&(1<<4)==0){} //BOOLING TO CHECK PORTE CONNECTION IS ON
        GPIO_PORTE_DEN_R = 0X1F;//MAKE DIGITAL;
        //port E does not need locking
        break;


    case 5:
        SYSCTL_RCGCGPIO_R|=(1<<5); //CONNECT CLOCK TO PORTF
        while(SYSCTL_RCGCGPIO_R&(1<<5)==0){} //BOOLING TO CHECK PORTF CONNECTION IS ON
        GPIO_PORTF_LOCK_R=0X4C4F434B;
        GPIO_PORTF_CR_R=0X1F;          //UNLOCKING PORTF
        GPIO_PORTF_DEN_R = 0X1F; //MAKE DIGITAL;
    }
}





void GPIO_set_input (Int32_t port , Int32_t bit,Int32_t pull)
{
    switch (port)
        {
            case 0:
                Clear_bit(GPIO_PORTA_DIR_R,bit);
                if (pull)
                {
                    Set_bit(GPIO_PORTA_PUR_R,bit);
                    Clear_bit(GPIO_PORTA_PDR_R,bit);
                }
                else
                {
                    Clear_bit(GPIO_PORTA_PUR_R,bit);
                    Set_bit(GPIO_PORTA_PDR_R,bit);
                }
                break;

            case 1:
                Clear_bit(GPIO_PORTB_DIR_R,bit);
                if (pull)
                {
                    Set_bit(GPIO_PORTB_PUR_R,bit);
                    Clear_bit(GPIO_PORTB_PDR_R,bit);
                }
                else
                {
                    Clear_bit(GPIO_PORTB_PUR_R,bit);
                    Set_bit(GPIO_PORTB_PDR_R,bit);
                }
                break;

            case 2:
                Clear_bit(GPIO_PORTC_DIR_R,bit);
                if (pull)
                {
                    Set_bit(GPIO_PORTC_PUR_R,bit);
                    Clear_bit(GPIO_PORTC_PDR_R,bit);
                }
                else
                {
                    Clear_bit(GPIO_PORTC_PUR_R,bit);
                    Set_bit(GPIO_PORTC_PDR_R,bit);
                }
                break;

            case 3:
                Clear_bit(GPIO_PORTD_DIR_R,bit);
                if (pull)
                {
                    Set_bit(GPIO_PORTD_PUR_R,bit);
                    Clear_bit(GPIO_PORTD_PDR_R,bit);
                }
                else
                {
                    Clear_bit(GPIO_PORTD_PUR_R,bit);
                    Set_bit(GPIO_PORTD_PDR_R,bit);
                }
                break;

                Clear_bit(GPIO_PORTE_DIR_R,bit);
                if (pull)
                {
                    Set_bit(GPIO_PORTE_PUR_R,bit);
                    Clear_bit(GPIO_PORTE_PDR_R,bit);
                }
                else
                {
                    Clear_bit(GPIO_PORTE_PUR_R,bit);
                    Set_bit(GPIO_PORTE_PDR_R,bit);
                }
                break;

            case 5:
                Clear_bit(GPIO_PORTF_DIR_R,bit);
                if (pull)
                {
                    Set_bit(GPIO_PORTF_PUR_R,bit);
                    Clear_bit(GPIO_PORTF_PDR_R,bit);
                }
                else
                {
                    Clear_bit(GPIO_PORTF_PUR_R,bit);
                    Set_bit(GPIO_PORTF_PDR_R,bit);
                }
                break;
        }
}


void GPIO_set_output (Int32_t port , Int32_t bit)
{
    switch (port)
        {
            case 0:
                Set_bit(GPIO_PORTA_DIR_R,bit);
                break;

            case 1:
                Set_bit(GPIO_PORTB_DIR_R,bit);
                break;

            case 2:
                Set_bit(GPIO_PORTC_DIR_R,bit);
                break;

            case 3:
                Set_bit(GPIO_PORTD_DIR_R,bit);
                break;

            case 4:
                Set_bit(GPIO_PORTE_DIR_R,bit);
                break;

            case 5:
                Set_bit(GPIO_PORTF_DIR_R,bit);
                break;
        }
}


void GPIO_set_value (Int32_t port , Int32_t bit, Int32_t value )
{
    switch (port)
        {
            case 0:
                if (value)
                {
                    Clear_bit(GPIO_PORTA_DATA_R,bit);
                }
                else
                {
                    Set_bit(GPIO_PORTA_DATA_R,bit);
                }
                break;

            case 1:
                if (value)
                {
                    Clear_bit(GPIO_PORTB_DATA_R,bit);
                }
                else
                {
                    Set_bit(GPIO_PORTB_DATA_R,bit);
                }
                break;

            case 2:
                if (value)
                {
                    Clear_bit(GPIO_PORTC_DATA_R,bit);
                }
                else
                {
                    Set_bit(GPIO_PORTC_DATA_R,bit);
                }
                break;

            case 3:
                if (value)
                {
                    Clear_bit(GPIO_PORTD_DATA_R,bit);
                }
                else
                {
                    Set_bit(GPIO_PORTD_DATA_R,bit);
                }
                break;

            case 4:
                if (value)
                {
                    Clear_bit(GPIO_PORTE_DATA_R,bit);
                }
                else
                {
                    Set_bit(GPIO_PORTE_DATA_R,bit);
                }
                break;

            case 5:
                if (value)
                {
                    Clear_bit(GPIO_PORTF_DATA_R,bit);
                }
                else
                {
                    Set_bit(GPIO_PORTF_DATA_R,bit);
                }
                break;
        }
}


