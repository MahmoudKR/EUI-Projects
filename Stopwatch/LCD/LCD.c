#include "LCD.h"

void LCD_Init(void)
{
    GPIO_Init(D4, OUTPUT, FLOAT);
    GPIO_Init(D5, OUTPUT, FLOAT);
    GPIO_Init(D6, OUTPUT, FLOAT);
    GPIO_Init(D7, OUTPUT, FLOAT);
    GPIO_Init(EN, OUTPUT, FLOAT);
    GPIO_Init(RS, OUTPUT, FLOAT);
    Delay(1000);
    Send_Command(0x28); /* 2 line, 5*7 matrix in 4-bit mode */
    Send_Command(0x0C); /* Display on cursor off */
    Send_Command(0x06); /* Increment cursor (shift cursor to right) */
    Send_Command(0x01); /* Clear display screen */
    Send_Command(First_Line);
}

void Send_Command(u8 command)
{
    u8 dataH = (command & 0xF0)>>4;
    u8 dataL = 0x0F & command;
    GPIO_Write_Port(LCD_Port, dataH<<4);
    GPIO_Write(RS, LOW);
    GPIO_Write(EN, HIGH);
    Delay_Micro(1);
    GPIO_Write(EN, LOW);
    Delay_Micro(200);
    GPIO_Write_Port(LCD_Port, dataL<<4);
    GPIO_Write(EN, HIGH);
    Delay_Micro(1);
    GPIO_Write(EN, LOW);
    Delay(2);
}

void Send_Data(u8 data)
{
    u8 dataH = (0xF0 & data) >> 4;
    u8 dataL = 0x0F & data;
    GPIO_Write_Port(LCD_Port, dataH<<4);
    GPIO_Write(RS, HIGH);
    GPIO_Write(EN, HIGH);
    Delay_Micro(1);
    GPIO_Write(EN, LOW);
    Delay_Micro(200);
    GPIO_Write_Port(LCD_Port, dataL<<4);
    GPIO_Write(EN, HIGH);
    Delay_Micro(1);
    GPIO_Write(EN, LOW);
    Delay(2);
}

void Send_String(char *str)
{
    Send_Command(Clear);
    int i;
    for (i = 0; str[i] != 0; i++) /* Send each char of string till the NULL */
    {
        Send_Data(str[i]);
    }
}

