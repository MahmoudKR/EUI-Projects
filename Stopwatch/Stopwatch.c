#include "Stopwatch.h"

Time time;
Time lap1;
Time lap2;
Time lap3;
u8 Arr[5];
u8 Lap1[5];
u8 Lap2[5];
u8 Lap3[5];
u8 flag;
u8 Lap_Flag;

void Stopwatch_Init(void)
{
    Lap_Flag = 0;
    flag = 1;
    time.minutes = 0;
    time.seconds = 0;
    lap1.minutes = 0;
    lap1.seconds = 0;
    lap2.minutes = 0;
    lap2.seconds = 0;
    lap3.minutes = 0;
    lap3.seconds = 0;
    GPIO_Init(StartStop, INPUT, PULL_UP);
    GPIO_Init(Reset, INPUT, PULL_UP);
    GPIO_InterruptInit(PF0, FALLING_EDGE, 0);
    GPIO_InterruptInit(PF4, FALLING_EDGE, 0);
    LCD_Init();
    NVIC_ST_RELOAD_R = 4000000;
    NVIC_ST_CTRL_R = 0b11;
}

void toString(void)
{
//    Send_Command(Clear);
    Arr[0] = (time.minutes / 10) + '0';
    Arr[1] = (time.minutes % 10) + '0';
    Arr[2] = ':';
    Arr[3] = (time.seconds / 10) + '0';
    Arr[4] = (time.seconds % 10) + '0';
    u8 i;
    Send_Command(First_Line);
    for (i = 0; i < 5; i++)
    {
        Send_Data(Arr[i]);
    }

    if (Lap_Flag)
    {
        Lap1[0] = (lap1.minutes / 10) + '0';
        Lap1[1] = (lap1.minutes % 10) + '0';
        Lap1[2] = ':';
        Lap1[3] = (lap1.seconds / 10) + '0';
        Lap1[4] = (lap1.seconds % 10) + '0';
        Send_Command(0x80 + 0x08);
        //Send_Data('L');
        Send_Data('1');
        Send_Data('>');
        for (i = 0; i < 5; i++)
        {
            Send_Data(Lap1[i]);
        }

        Lap2[0] = (lap2.minutes / 10) + '0';
        Lap2[1] = (lap2.minutes % 10) + '0';
        Lap2[2] = ':';
        Lap2[3] = (lap2.seconds / 10) + '0';
        Lap2[4] = (lap2.seconds % 10) + '0';
        Send_Command(Second_Line);
        //Send_Data('L');
        Send_Data('2');
        Send_Data('>');
        for (i = 0; i < 5; i++)
        {
            Send_Data(Lap2[i]);
        }

        Lap3[0] = (lap3.minutes / 10) + '0';
        Lap3[1] = (lap3.minutes % 10) + '0';
        Lap3[2] = ':';
        Lap3[3] = (lap3.seconds / 10) + '0';
        Lap3[4] = (lap3.seconds % 10) + '0';
        Send_Command(0x80 + 0x48);
        //Send_Data('L');
        Send_Data('3');
        Send_Data('>');
        for (i = 0; i < 5; i++)
        {
            Send_Data(Lap3[i]);
        }
        Lap_Flag = 0;
    }
}

void Lap(void)
{

    lap3.minutes = lap2.minutes;
    lap3.seconds = lap2.seconds;
    lap2.minutes = lap1.minutes;
    lap2.seconds = lap1.seconds;
    lap1.minutes = time.minutes;
    lap1.seconds = time.seconds;
    Lap_Flag = 1;
}

void SYSTick_Handler(void)
{
    time.seconds++;
    if (time.seconds == 60)
    {
        time.seconds = 0;
        time.minutes++;
    }
    toString();

}

void GPIOF_Handler(void)
{
    if (GPIO_PORTF_MIS_R & (1 << 0))
    {
        if (flag)
        {
            NVIC_ST_CTRL_R &= ~(1 << 0);
            flag = 0;
        }
        else
        {
            NVIC_ST_CTRL_R |= (1 << 0);
            flag = 1;
        }
    }
    else
    {
        if (!flag)
        {
            Stopwatch_Init();
        }
        else
        {
            Lap();
        }
    }
    GPIO_PORTF_ICR_R |= 0xFF;
}
