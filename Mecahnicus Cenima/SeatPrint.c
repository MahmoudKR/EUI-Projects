#include "stdio.h"
#include "globals.h"

void SeatPrint ()
{
	int c=0;
	for (int i=0;i<100;i++)
	{
		switch (x[MovieIndex][i].Booked)
		{
			case 1:
				printf("# ");
				break;

			default :
				printf("%d ",i+1);
				break;

		}
		c++;
		if (c==10)
		{
			printf("\n");
			c=0;
		}

	}

}