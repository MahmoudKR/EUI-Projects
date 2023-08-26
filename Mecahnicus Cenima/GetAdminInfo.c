/*
 * GetAdminInfo.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Mahmoud A. Monaim
 */

#include "stdio.h"
#include "globals.h"

void GetAdminInfo ()
{
	int y;
	system ("clear");
	fflush stdin; fflush stdout;
	printf("\n*******************" );
	printf("\nSelect Option :" );
	printf("\n1-See Reserved Tickets" );
	printf("\n2- Change Price" );
	printf("\n*******************\n" );
	fflush stdin; fflush stdout;
	scanf("%d",&y);

	switch (y)
	{
	case 1:
		OPmode =7;
		break;

	case 2:
		OPmode =8;
		break;
	}


}
