/*
 * GetUserInfo.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Mahmoud A. Monaim
 */

#include "stdio.h"
#include "globals.h"



void GetUserInfo ()
{
	int BorC;

	printf("\nplease enter name \n");
	fflush stdin;fflush stdout;
	scanf("%s",&temp_name);

	// name check shall be added

	printf("\nplease enter phone number \n");
	fflush stdin;fflush stdout;
	scanf("%s",&temp_phone);

	// Phone check shall be added

	system("clear");
	printf("\n**************************");
	printf("\n1-book a ticket\n2-cancle a ticket\n");

	fflush stdin;fflush stdout;

	scanf("%d",&BorC);

	switch (BorC)
	{
	case 1:
		OPmode = 4;
		break;

	case 2:
		OPmode = 9;
		break ;

	default :
		OPmode = 2;
		printf("Wrong entry");
		break;
	}


	// Phone check shall be added

}

