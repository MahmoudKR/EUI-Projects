/*
 * globals.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Mahmoud A. Monaim
 * 
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

char temp_phone [12];
char temp_password[4];
char temp_name[50];
int mode;

int MovieIndex ;

int BookedSeats [100];

int ReservedSeats;
int yyyy  ;

extern int OPmode;

extern char u_password[4];
extern char a_password[4];

extern int todays_price;

struct seats {
	int price ;
	char name [50] ;
	char phone [12] ;
	int Booked;

};


struct seats x [3][100];

#endif /* GLOBALS_H_ */