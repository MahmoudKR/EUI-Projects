/*
 * applecation.c
 *
 *  Created on: Sep 3, 2023
 *      Author: pc
 */


/*
 * RO.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Mahmoud A. Monaim
 */

#include "app.h"

char error_msg[]={error_message};
int size=sizeof(error_msg)/sizeof(error_msg[0]);
int counter=0;

void app(void)
{
    char screen_data[100];
    char recieved_data[100];
    int index2=0;
    int index=0;
    int i;


    if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)!=1)
            {
                for(i=0;i<15000;i++){}
                if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)!=1)
                {
                    if(counter<2)
                    {
                        counter++;
                    }
                    else
                    {
                        counter=0;
                    }

                }

            }
            switch (counter)
            {
            case 0:
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x02);
                read_only(recieved_data,&index2 );
                break;
            case 1:
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x04);
                RW(screen_data,recieved_data,&index,&index2);
                break;
            case 2:
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0xFF);

                break;

            }


    //screen_print(screen_data,index);
}
void RW(char*arr,char *arr2,int *index,int *index2 )
{
    int i;
    (*index)=0;
    (*index2)=0;

    //reciveing from pc to tiva (uart0 to uart1)
    if(UARTCharsAvail(UART0_BASE))
    {
        UARTCharPut(UART0_BASE, '>');
        UARTCharPut(UART0_BASE, '>');

        do{
            if(UARTCharsAvail(UART0_BASE))
            {
                arr[(*index)]=UARTCharGetNonBlocking(UART0_BASE);
                UARTCharPut(UART0_BASE, arr[(*index)]);  //print character on the screen
                (*index)++;
            }

        }while((arr[(*index)-1] != 13));

        UARTCharPut(UART0_BASE, '\n'); //leave a space

        if((*index)<max)
        {
            for(i=0;i<(*index)-1;i++)
            {
                UARTCharPut(UART5_BASE, arr[i]); //put character on screen
            }
        }
        else
        {
            for(i=0;i<size;i++)
            {
                UARTCharPut(UART0_BASE, error_msg[i]); //put character on screen
            }
        }


    }











    if(UARTCharsAvail(UART5_BASE))
    {
        (*index2)=0;
        do{
            if(UARTCharsAvail(UART5_BASE))
            {
                arr2[(*index2)]=UARTCharGet(UART5_BASE);
                UARTCharPut(UART0_BASE, arr2[(*index2)]);  //print character on the screen
                if((arr2[(*index2)-1] != 13))
                {
                    break;
                }
                (*index2)++;

            }



        }while((arr2[(*index2)-1] != 13));





//        UARTCharPut(UART0_BASE, '\n');
//        for(i=0;i<(*index2)-1;i++)
//        {
//            UARTCharPut(UART0_BASE, arr2[i]); //put character on screen
//        }


    }


}


void read_only(char *arr2,int *index2 )
{
    (*index2)=0;
    if(UARTCharsAvail(UART5_BASE))
    {
        do{
            if(UARTCharsAvail(UART5_BASE))
            {
                arr2[(*index2)]=UARTCharGet(UART5_BASE);
                UARTCharPut(UART0_BASE, arr2[(*index2)]);  //print character on the screen
                if((arr2[(*index2)-1] != 13))
                {
                    break;
                }
                (*index2)++;

            }

        }while((arr2[(*index2)-1] != 13));
}
}
