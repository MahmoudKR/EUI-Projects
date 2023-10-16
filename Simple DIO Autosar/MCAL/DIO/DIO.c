/*
 * DIO.c
 *
 *  Created on: Oct 14, 2023
 *      Author: eme
 */
#include "LIB/bitwise_operations.h"
#include "LIB/Std_Types.h"
#include "LIB/tm4c123gh6pm.h"
#include "DIO.h"






void port_init (void)
{
   Set_bit(SYSCTL_RCGCGPIO_R,5);
   GPIO_PORTF_LOCK_R |= 0x4c4f434b;
   GPIO_PORTF_CR_R |= 0x000000ff;
   Set_bit(GPIO_PORTF_DIR_R ,1);
   Set_bit(GPIO_PORTF_DEN_R,1);
   Set_bit(GPIO_PORTF_DR2R_R,1);

};

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType Level;

    if ( ChannelId <=7)
    {
        ChannelId = ChannelId % 8;
        Level= ((GPIO_PORTA_DATA_R &(1<< ChannelId))>>ChannelId);
    }
    else if (ChannelId>8 && ChannelId <16)
    {
        ChannelId = ChannelId % 8;
        Level = ((GPIO_PORTB_DATA_R &(1<< ChannelId))>>ChannelId);
    }
    else if (ChannelId>16 && ChannelId <24)
    {
        ChannelId = ChannelId % 8;
        Level = ((GPIO_PORTC_DATA_R &(1<< ChannelId))>>ChannelId);
    }
    else if (ChannelId>24 && ChannelId <32)
    {
        ChannelId = ChannelId % 8;
        Level = ((GPIO_PORTD_DATA_R &(1<< ChannelId))>>ChannelId);
    }
    else if (ChannelId>32 && ChannelId <40)
    {
        ChannelId = ChannelId % 8;
        Level = ((GPIO_PORTE_DATA_R &(1<< ChannelId))>>ChannelId);
    }
    else if (ChannelId>40 && ChannelId <48)
    {
        ChannelId = ChannelId % 8;
        Level = ((GPIO_PORTF_DATA_R &(1<< ChannelId))>>ChannelId);
    }
    else
    {
       //do nothing
    }

    return Level;
}






void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    if ( ChannelId <=7)
    {
        ChannelId = ChannelId % 8;
        if (Level == STD_HIGH)
        {
            Set_bit(GPIO_PORTA_DATA_R,ChannelId);
        }
        else if (Level ==STD_LOW)
        {
            Clear_bit(GPIO_PORTA_DATA_R,ChannelId);
        }
        else
        {
            //Do nothing
        }
    }


    else if (ChannelId>8 && ChannelId <16)
    {
        ChannelId = ChannelId % 8;
        if (Level == STD_HIGH)
        {
            Set_bit(GPIO_PORTB_DATA_R,ChannelId);
        }
        else if (Level ==STD_LOW)
        {
            Clear_bit(GPIO_PORTB_DATA_R,ChannelId);
        }
        else
        {
            //Do nothing
        }
    }


    else if (ChannelId>16 && ChannelId <24)
    {
        ChannelId = ChannelId % 8;
        if (Level == STD_HIGH)
        {
            Set_bit(GPIO_PORTC_DATA_R,ChannelId);
        }
        else if (Level ==STD_LOW)
        {
            Clear_bit(GPIO_PORTC_DATA_R,ChannelId);
        }
        else
        {
            //Do nothing
        }
    }


    else if (ChannelId>24 && ChannelId <32)
    {
        ChannelId = ChannelId % 8;
        if (Level == STD_HIGH)
        {
            Set_bit(GPIO_PORTD_DATA_R,ChannelId);
        }
        else if (Level ==STD_LOW)
        {
            Clear_bit(GPIO_PORTD_DATA_R,ChannelId);
        }
        else
        {
            //Do nothing
        }
    }


    else if (ChannelId>32 && ChannelId <40)
    {
        ChannelId = ChannelId % 8;
        if (Level == STD_HIGH)
        {
            Set_bit(GPIO_PORTE_DATA_R,ChannelId);
        }
        else if (Level ==STD_LOW)
        {
            Clear_bit(GPIO_PORTE_DATA_R,ChannelId);
        }
        else
        {
            //Do nothing
        }
    }


    else if (ChannelId>40 && ChannelId <48)
    {
        ChannelId = ChannelId % 8;
        if (Level == STD_HIGH)
        {
            Set_bit(GPIO_PORTF_DATA_R,ChannelId);
        }
        else if (Level ==STD_LOW)
        {
            Clear_bit(GPIO_PORTF_DATA_R,ChannelId);
        }
        else
        {
            //Do nothing
        }
    }


    else
    {
       //do nothing
    }

}

