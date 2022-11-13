#include <stdio.h>

int main(void)
{
	int input = 0;
	scanf("%i", &input);

	long long int number_past1 = 1;
	long long int number_past2 = 1;
	long long int number = 0;

	for (int i = 3; i <= input; i++)
	{
		number = number_past1 + number_past2;
		number_past2 = number_past1;
		number_past1 = number;
	}

	printf("%lli", number);

	return 0;
}
