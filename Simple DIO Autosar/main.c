

/**
 * main.c
 */
#include "LIB/bitwise_operations.h"
#include "LIB/Std_Types.h"
#include "LIB/tm4c123gh6pm.h"
#include "MCAL/DIO/DIO.h"

Int32_t main(void)
{
    port_init();

    Dio_ChannelType channel=41;

    Dio_WriteChannel(channel, STD_HIGH);

	return 0;
}
