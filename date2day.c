#include <stdio.h>

int main(void) {
	int day, month, year, century, year2digits, zeller, weekday;
	void printWeekDay(int);
	
	printf("Enter the date in Year, Month, Day.\n");
	printf("\nYear: ");
	scanf("%d", &year);
	printf("\nMonth: ");
	scanf("%d", &month);
	printf("\nDay: ");
	scanf("%d", &day);
	
	if (month==1 || month==2) {
		--year;
		month+=10;
	}
	else month-=2;
	century = year/100;
	year2digits = year%100;
	zeller = day + ((13*month-1)/5) +year2digits+year2digits/4+century/4-2*century;
	printf("\nZeller = %d\n", zeller);
	weekday = zeller%7;
	if (zeller>=0) {
		printf("\nZeller Day = %d\n", weekday);
		printWeekDay(weekday);
	}
	else {
		printf("\nNegative Zeller Day = %d\n", weekday);
		if (weekday!=0) weekday+=7;
		printf("\nPositive Zeller Day = %d\n", weekday);
		printWeekDay(weekday);
	}
}

void printWeekDay (int weekday) {
	if(weekday == 0)
    {
        printf("\nSunday\n");
    }
    else if(weekday == 1)
    {
        printf("\nMonday\n");
    }
    else if(weekday == 2)
    {
        printf("\nTuesday\n");
    }
    else if(weekday == 3)
    {
        printf("\nWednesday\n");
    }
    else if(weekday == 4)
    {
        printf("\nThursday\n");
    }
    else if(weekday == 5)
    {
        printf("\nFriday\n");
    }
    else if(weekday == 6)
    {
        printf("\nSaturday\n");
    }
}