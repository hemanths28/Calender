//c program to print the calendar of a specific year
#include<stdio.h>

int daysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *strMonths[]= {" ","\nJANUARY","\n\nFEBRUARY","\n\nMARCH","\n\nAPRIL","\n\nMAY","\n\nJUNE","\n\nJULY","\n\nAUGUST","\n\nSEPTEMBER","\n\nOCTOBER","\n\nNOVEMBER","\n\nDECEMBER"};

int checkleapyear(int);
void calendar(int, int);

int main()
{
	int year, dayCode;

	printf("Enter the year: ");
	scanf("%d", &year);

	int x, y, z;
	x = (year - 1)/ 4;
	y = (year - 1)/ 100;
	z = (year - 1)/ 400;
	dayCode = (year + x - y + z) %7;
	checkleapyear(year);
	calendar(year, dayCode);
	return 0;
}

int checkleapyear(int year)
{
	if(year% 4 == 0 && year%100 != 0 || year%400 == 0) // if leap year then Feb has 29 days else 28 days
	{
		daysInMonth[2] = 29;
		return 1;
	}
	else
	{
		daysInMonth[2] = 28;
		return 0;
	}
}

void calendar(int year, int dayCode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", strMonths[month]);
		printf("\n\nSUN  MON  TUE  WED  THU  FRI  SAT\n" );

		for ( day = 1; day <= 1 + dayCode * 5; day++ ) // position for the first date
		{
			printf(" ");
		}

		for ( day = 1; day <= daysInMonth[month]; day++ ) // Printing all the dates of the month
		{
			printf("%2d", day );
			if ( ( day + dayCode ) % 7 > 0 ) // if the day is before sat
				printf("   " );
			else
				printf("\n " );
		}
			dayCode = ( dayCode + daysInMonth[month] ) % 7; //for next month
			printf("\n---------------------------------");
	}
}


