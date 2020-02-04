/* converts date input into day of week output */
/* char and string input checks done */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {
	char daystring[3]={0}, monthstring[3]={0}, yearstring[5]={0};
	int day, month, zellermonth, year, zelleryear, century, year2digits, zeller, weekday;
	bool leap=false, notdigit; 
	void printDaysInMonth(int, char[], int * const);
	void printWeekDay(int, int, int, int);

	// Input year, month, day with date validation
	printf("Enter the date in Year, Month, Day.\n");
	do {
		notdigit = true;
		year = 0;
		printf("\nYear(from 1900 to 2100): ");
		scanf("%4s", &yearstring);
		// printf("Your input is %s\n", yearstring);
		// ternary year = ? : didn't work possibly due to error in expression
		if (isdigit(yearstring[0]) && isdigit(yearstring[1]) 
			&& isdigit(yearstring[2]) && isdigit(yearstring[3])) {
			notdigit = false;
			year = atoi(yearstring);
		}
	} while (year<1900 || year>2100 || notdigit);
	if (year%4==0 && year!=1900 && year!=2100) leap=true;
	do {
		notdigit = true;
		month = 0;
		printf("\nMonth(from 01 to 12): ");
		scanf(" %s", &monthstring);
		// printf("Your input is %s\n", monthstring);
		if (isdigit(monthstring[0]) && isdigit(monthstring[1])) { 
			notdigit = false;
			month = atoi(monthstring);
		}
		// "else if" not needed when scanf %s
		else if (isdigit(monthstring[0]) && monthstring[1]=='\n') {
			notdigit = false;
			month = atoi(monthstring);
		}
	} while (month<1 || month>12 || notdigit);
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: 
			printDaysInMonth(31, daystring, &day);
			break;
		case 4:
		case 6:
		case 9:
		case 11: 
			printDaysInMonth(30, daystring, &day);
			break;
		case 2: 
			if (leap) printDaysInMonth(29, daystring, &day);
			else printDaysInMonth(28, daystring, &day);
			break;
	}
	
	// Use of Zeller calculation to derive day of week from input date
	if (month==1 || month==2) {
		zelleryear = year - 1;
		zellermonth = month + 10;
	}
	else {
		zelleryear = year;
		zellermonth = month - 2;
	}
	century = zelleryear/100;
	year2digits = zelleryear%100;
	zeller = day + ((13*zellermonth-1)/5) +year2digits + year2digits/4 + century/4 - 2*century;
	printf("\nZeller = %d\n", zeller);
	weekday = zeller%7;
	if (zeller>=0) {
		printf("\nZeller Day = %d\n", weekday);
		printWeekDay(weekday, year, month, day);
	}
	else {
		printf("\nNegative Zeller Day = %d\n", weekday);
		if (weekday!=0) weekday+=7;
		printf("\nPositive Zeller Day = %d\n", weekday);
		printWeekDay(weekday, year, month, day);
	}
	return 0;
}

// dayaddress has to be const pointer so that int day in main function is updated
void printDaysInMonth (int daysinmonth, char daystring[], int * const dayaddress) {
	bool notdigit = true;
	do {
		*dayaddress = 0;
		printf("\nDay(from 01 to %d): ", daysinmonth);
		// %s cannot catch '\n' character, but %3c more problems
		// so checking daystring[1]=='\n' is optional
		scanf("%s", daystring); 
		// printf("Your input is %s", daystring);
		if (isdigit(daystring[0]) && isdigit(daystring[1]) 
			|| isdigit(daystring[0]) && daystring[1]=='\n')	{
			notdigit = false;
			*dayaddress = atoi(daystring);
		}
	} while (*dayaddress<1 || *dayaddress>daysinmonth || notdigit);
}

// print day of week from date
void printWeekDay (int weekday, int year, int month, int day) {
	if(weekday == 0)
    {
        printf("\nThe date %d/%d/%d is a Sunday.\n", day, month, year);
    }
    else if(weekday == 1)
    {
        printf("\nThe date %d/%d/%d is a Monday.\n", day, month, year);
    }
    else if(weekday == 2)
    {
        printf("\nThe date %d/%d/%d is a Tuesday.\n", day, month, year);
    }
    else if(weekday == 3)
    {
        printf("\nThe date %d/%d/%d is a Wednesday.\n", day, month, year);
    }
    else if(weekday == 4)
    {
        printf("\nThe date %d/%d/%d is a Thursday.\n", day, month, year);
    }
    else if(weekday == 5)
    {
        printf("\nThe date %d/%d/%d is a Friday.\n", day, month, year);
    }
    else if(weekday == 6)
    {
        printf("\nThe date %d/%d/%d is a Saturday.\n", day, month, year);
    }
}