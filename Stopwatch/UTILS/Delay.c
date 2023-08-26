#include "Delay.h"

void Delay(u32 delay)
{
    delay *= 762;
    u32 i;
    for(i = delay; i > 0; i--);
}

void Delay_Micro(u32 delay)
{
    u32 i;
    for(i = delay; i > 0; i--);
}
