#include "stdio.h"
#include "globals.h"

void SelectMovie ()
{
	int y;

	system ("clear");
	fflush stdin; fflush stdout;
	printf("\n*******************" );
	printf("\nSelect Your Movie :" );
	printf("\n1-Openhimer" );
	printf("\n2-Barbie" );
	printf("\n3-Mission Impossible" );
	printf("\n*******************\n" );
	fflush stdin; fflush stdout;
	scanf("%d",&y);
	printf("\nMovieIndex : %d",MovieIndex);

	switch (y)
	{
	case 1:
		MovieIndex = 0;
		OPmode = 5;
		break;

	case 2:
		MovieIndex = 1;
		OPmode = 5;
		break;

	case 3:
		MovieIndex = 2;
		OPmode = 5;
		break;

	default :
		printf ("\nWrong Entry");
		OPmode = 4;
		break;
	}


}