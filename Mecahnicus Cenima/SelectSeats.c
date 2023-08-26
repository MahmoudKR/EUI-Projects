#include "stdio.h"
#include "globals.h"
#include "functions.h"
#include "string.h"

void SelectSeats()
	{
		fflush stdin; fflush stdout;
		int y;
		ReservedSeats =0 ;

		for (int i =0; i<100; i++)
		{
			system ("clear");

			SeatPrint ();

			fflush stdin; fflush stdout;
			printf("\n*******************" );
			printf("\nSelect Seats" );
			printf("\n0 : confirm\n" );
			fflush stdin; fflush stdout;

			scanf("%d",&y);
			//printf("\nMovieIndex : %d",MovieIndex);

			if (y<=100 & y>0)
			{
				x[MovieIndex][y-1].Booked=1;
				BookedSeats[ReservedSeats]=y-1;
				ReservedSeats++;
				strcpy(x[MovieIndex][y-1].name,temp_name);
				strcpy(x[MovieIndex][y-1].phone,temp_phone);
				x[MovieIndex][y-1].price=todays_price;


			}
			else if (y==0)
			{
				OPmode=6;
				break;
			}
			else
			{
				printf("\n Wrong Entry");
			}
		}
		printf("\n Confirmed");
	}
