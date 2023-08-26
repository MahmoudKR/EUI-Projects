#include "stdio.h"
#include "globals.h"

void SeeAllTickets()
{

	for (int i=0;i<3;i++)
	{
		for(int j =0;j<100;j++)
		{
			if (x[i][j].Booked==1)
			{
				fflush stdin; fflush stdout;
				printf("\n****************************");
				printf("\nName :%s",x[i][j].name);
				printf("\nPhone :%s",x[i][j].phone);

				fflush stdin; fflush stdout;
				switch (i)
				{
				case 0:
					printf("\nMovie :Openhimer");
					break;
				case 1:
					printf("\nMovie :Barbie");
					break;

				case 2:
					printf("\nMovie :Mission Impossible");
					break;
				}

				printf("\nSeat Number :%d",j+1);
				printf("\nPrice :%d",x[i][j].price);
				printf("\n****************************");
				fflush stdin; fflush stdout;
			}

		}
	}

	OPmode=0;

}