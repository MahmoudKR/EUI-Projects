#include "stdio.h"
#include "globals.h"


void ChangePrice()
{
	system("clear");
	fflush stdin; fflush stdout;

	printf("\n****************************");
	printf("\nCurrent Price : %d",todays_price);
	printf("\nEnter New Price : ");
	fflush stdin;fflush stdout;
	scanf("%d",&todays_price);
	fflush stdin;fflush stdout;fflush stdin;fflush stdout;
	printf("\nPrice Changed");

	OPmode=0;


}