#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
/**
 * main.c
 */



#include "applecation/app.h"
#include"applecation/gpio_int.h"



int32_t main(void)
{
    UART0_INIT();
    UART5_INIT();

    gpio_init();


    while (1)
    {
        app();
    }


    return 0;
}



