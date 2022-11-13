#include <stdio.h>

#define YEAR 1300
#define LENGHT_YEAR 365

#define MONTH 1
#define HALF_YEAR 6
#define LENGHT_MONTH1 31
#define LENGHT_MONTH2 30

#define DAY 1

int main(void)
{
	int input_day = 0;
	scanf("%i", &input_day);

	int buffer = input_day;

	/*calculate year*/
	int year = YEAR + buffer / LENGHT_YEAR;
	buffer %= LENGHT_YEAR;

	/*calculate month*/
	int month = MONTH;
	if (input_day < HALF_YEAR * LENGHT_MONTH1)
	{
		month += buffer / LENGHT_MONTH1;
		buffer %= LENGHT_MONTH1;
	}
	else
	{
		buffer -= HALF_YEAR * LENGHT_MONTH1;
		month = HALF_YEAR + buffer / LENGHT_MONTH2;
		buffer %= LENGHT_MONTH2;
	}

	/*calculate day*/
	int day = DAY + buffer;

	/*print ans*/
	printf("%i.%i.%i", year, month, day);

	return 0;
}
