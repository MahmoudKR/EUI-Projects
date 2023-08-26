#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#define D4 PA4
#define D5 PA5
#define D6 PA6
#define D7 PA7
#define RS PE1
#define EN PE2
#define LCD_Port PortA

#define Clear 0x01
#define Second_Line 0xC0
#define First_Line 0x80

#include "UTILS/Delay.h"
#include "MCAL/GPIO_Drivers/GPIO_CTL.h"

void LCD_Init(void);
void Send_Command(u8 command);
void Send_Data(u8 data);
void Send_String(char*);

#endif /* LCD_LCD_H_ */
