/*
 * AdminOrUser.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Mahmoud A. Monaim
 */

#include "stdio.h"
#include "functions.h"
#include "globals.h"

void AdminOrUser ()
{
	printf("\nPlease Choose Mode:\n1: User\n2:Admin\n");
	fflush stdin ; fflush stdout;
	scanf ("%d",&mode);

		switch (mode)
		{
		case 1:
			OPmode = 3;
			break;

		case 2:
			OPmode = 3;
			break;

		default:
			printf("\nWrong Input (X)\n");
			break;
		}
}

