/*
 * password.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Mahmoud A. Monaim
 */
#include "stdio.h"
#include "stdlib.h"
#include "globals.h"

void password ()

{
	int c=0;
	char u_password [] = "1234";
	char a_password [] = "4321";
	system ("clear");
	printf("\nplease enter password \n");
	fflush stdin;fflush stdout;
	scanf("%s",&temp_password);

	switch (mode)
	{
	case 1:
		for (int i=0;i<4;i++)
		{
			if (u_password[i]==temp_password[i])
			{
				c++;

			}
		}
		if (c==4)
		{
			OPmode = 2;
		}
		else
		{
			printf("Wrong %d",OPmode);
			OPmode = 3;
		}
		break;



	case 2:
		for (int i=0;i<4;i++)
		{
			if (a_password[i]==temp_password[i])
			{
				c++;

			}
		}
		if (c==4)
		{
			OPmode=1;
		}
		else
		{
			printf("Wrong admin password");
			OPmode =3;
		}
		break;
	}


}
