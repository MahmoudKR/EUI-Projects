/*
 * calculator.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mahmoud A. Monaim
 */

#include "LIB/MyP_Types.h"
#include "HAL/lcd.h"
#include "calculator.h"

 Int32_t digitC=0;
 Int32_t opC=0;



void get_operationseration()
{
    Int32_t i,j,k=0;
    HandlePP ();
    HandleM ();

    for(i=counter-1;i>=0;i--)
    {
        data[i+1] = data[i];
    }
    data[0]='0';
    counter++;



    for(i = 0; i<counter;i++,k++)
    {
        if(data[i]=='*'|data[i]=='/'|data[i]=='-'|data[i]=='+'|data[i]=='=')
            {
                operations[opC] = data[i];
                opC++;
                digitC++;
                i++;
                k = 0;
            }
        digits[digitC]=digits[digitC]*10+(data[i]-'0');
    }

}

void calculate()
{
    Int32_t i=0,count=2;


    while(count)
    {
        switch (count){
        case 2:
            for(i=0;i<opC;i++)
            {
                if(operations[i]=='*'| operations[i]=='/')
                {
                    if(operations[i]=='*')
                    {
                        digits[i]*=digits[i+1];
                        shift(i+1);
                        sort_operations(i+1);
                        i=-1;
                    }
                    else
                    {
                        digits[i]/=digits[i+1];
                        shift(i+1);
                        sort_operations(i+1);
                        i=-1;
                    }

                }
            }
            count--;
            break;

        case 1:
            for(i=0;i<opC;i++)
            {
                if(operations[i]=='+'| operations[i]=='-')
                {
                    if(operations[i]=='+')
                    {
                        digits[i]+=digits[i+1];
                        shift(i+1);
                        sort_operations(i+1);
                        i=-1;
                    }
                    else
                    {
                        digits[i]-=digits[i+1];
                        shift(i+1);
                        sort_operations(i+1);
                        i=-1;
                    }

                }
            }
            count--;
            break;
        }
    }
        send_command(0x01);
        send_digit(digits[0]);

}
void sort_operations (Int32_t index)
{
    Int32_t j;
    for(j= index ;j<opC;j++)
    {
        operations[j-1]=operations[j];
    }
    operations[j-1]=0;

}

void shift(Int32_t index)
{
    Int32_t i=0;
    for(i=index+1;i<digitC+1;i++)
    {
        digits[i-1]=digits[i];
    }
    digits[i-1]=0;
}


void HandlePP ()
{
    Uint8_t h,l;
    for (h=0; h<counter;h++)
    {
        if (data [h]=='+'& data[h+1]=='+')
        {
            for(l=counter;l>(h-1);l--)
            {
                data[l+1] = data[l];
            }
            data[h+1]='0';
            counter++;
        }
    }
}
void HandleM ()
{
    Uint8_t h,l;
    for (h=0; h<counter;h++)
    {
        if (data [h]=='-' && data[h+1]=='-')
        {
            for(l=counter;l>(h-1);l--)
            {
                data[l+1] = data[l];
            }
            data[h+1]='0';
            data[h+2]='+';
            counter++;
        }
    }
}
