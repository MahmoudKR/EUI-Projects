#include "stdio.h"
#include "globals.h"

void tickets ()
{
	system ("clear");
	int a;

	for (int i=0;i<ReservedSeats;i++)
	{
		a=BookedSeats[i];
		fflush stdin; fflush stdout;
		printf("\n****************************");
		printf("\nName :%s",x[MovieIndex][a].name);
		printf("\nPhone :%s",x[MovieIndex][a].phone);
		fflush stdin; fflush stdout;

		switch (MovieIndex)
		{
		case 0:
			fflush stdin; fflush stdout;
			printf("\nMovie: Openhimer");
			break;

		case 1:
			fflush stdin; fflush stdout;
			printf("\nMovie: Barbie");
			break;

		default :
			fflush stdin; fflush stdout;
			printf("\nMovie: Mission Impossible");
			break;
		}

		fflush stdin; fflush stdout;
		printf("\nSeat Number : %d",a+1);
		fflush stdin; fflush stdout;
		printf("\nPrice :%d",x[MovieIndex][a].price);
		printf("\n*****************************\n\n");
	}

	printf("\n\ntotalprice : %d\n\n\n",ReservedSeats*todays_price);



	OPmode =0;

}