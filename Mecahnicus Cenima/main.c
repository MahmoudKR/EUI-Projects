/*
 * main.c
 *
 *  Created on: Nov 7, 2022
 *      Author: Mahmoud A. Monaim
 */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "globals.h"
#include "functions.h"
int OPmode ;
int todays_price=200 ;
int main ()
{
	system ("clear");
	printf("*******************************");
	printf("\nwelcome To mechanicus Cinema\n");
	printf("*******************************\n\n\n");

	while (1)
	{
		switch (OPmode)
		{
			case 0:
				AdminOrUser();
				break;

			case 1:
				GetAdminInfo();
				break;

			case 2:
				GetUserInfo();
				break;

			case 3:
				password();
				break;

			case 4:
				SelectMovie();
				break;

			case 5:
				SelectSeats();
				break;

			case 6:
				tickets ();
				break;

			case 7:
				SeeAllTickets();
				break;

			case 8:
				ChangePrice();
				break;

			//case 9:
				//canceling();



		}
	}

	return 0;

}
