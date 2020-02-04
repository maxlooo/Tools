/* converts date input into day of week output */
/* only int input checks done */
#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int day, month, zellermonth, year, zelleryear, century, year2digits, zeller, weekday;
	bool leap=false;
	void printDaysInMonth(int, int * const);
	void printWeekDay(int, int, int, int);

	// Input year, month, day with date validation
	printf("Enter the date in Year, Month, Day.\n");
	do {
		printf("\nYear(from 1900 to 2100): ");
		scanf("%d", &year);
	} while (year<1900 || year>2100);
	if (year%4==0 && year!=1900 && year!=2100) leap=true;
	do {
		printf("\nMonth(from 1 to 12): ");
		scanf("%d", &month);
	} while (month<1 || month>12);
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: 
			printDaysInMonth(31, &day);
			break;
		case 4:
		case 6:
		case 9:
		case 11: 
			printDaysInMonth(30, &day);
			break;
		case 2: 
			if (leap) printDaysInMonth(29, &day);
			else printDaysInMonth(28, &day);
			break;
	}
	
	// Use of Zeller calculation to derive day of week from input date
	if (month==1 || month==2) {
		zelleryear = year - 1;
		zellermonth = month + 10;
	}
	else zellermonth = month - 2;
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
void printDaysInMonth (int daysinmonth, int * const dayaddress) {
	do {
		printf("\nDay(from 1 to %d): ", daysinmonth);
		scanf("%d", dayaddress);
	} while (*dayaddress<1 || *dayaddress>daysinmonth);
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