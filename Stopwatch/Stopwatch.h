#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include "LCD/LCD.h"
#include "MCAL/GPIO_Drivers/GPIO_CTL.h"
#include "MCAL/GPIO_Drivers/GPIO_INT.h"

#define StartStop PF0
#define Reset PF4

typedef struct
{
    u8 hours;
    u8 minutes;
    u8 seconds;
} Time;

void Stopwatch_Init(void);
void toString(void);
void Lap(void);
void SYSTick_Handler(void);
void GPIOF_Handler(void);

#endif /* STOPWATCH_H_ */
