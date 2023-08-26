

/**
 * main.c
 */
#include "Libraries/MyP_Types.h"
#include "Libraries/bitwise.h"
#include "Libraries/tm4c123gh6pm.h"
#include "MCAL/GPIO/Dio.h"
#include "MCAL/GPTM/gptm.h"


Int32_t main(void)
{
    GPIO_init_port(PORTF);

    GPIO_set_output(PORTF, 1);
    GPIO_set_output(PORTF, 2);
    GPIO_set_output(PORTF, 3);

    GPIO_set_value(PORTF, 1, HIGH);
    GPIO_set_value(PORTF, 2, HIGH);
    GPIO_set_value(PORTF, 3, HIGH);

    GPTM_init_timer(T0,B32);
    GPTM_set_mode(T0,PERIODIC,DOWN);
    GPTM_set_time (T0,2000);

    GPTM_I_enable(T0,TATORIS); //enable timeout interrupt

    GPTM_start(T0);

    while (1)
    {

    }

	return 0;
}
