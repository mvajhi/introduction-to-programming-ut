#include <stdio.h>

#define True 1
#define False 0

int main(void)
{
	/***get input and check that***/
	float coeffcient1 = 0;
	float coeffcient2 = 0;
	float coeffcient3 = 0;

	scanf("%f", &coeffcient3);
	scanf("%f", &coeffcient2);
	scanf("%f", &coeffcient1);

	double approximation = 0;

	scanf("%lf", &approximation);

	if (0 >= approximation)
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}

	/***find max and save max ^ 2 ***/
	float max = 1;

	if (coeffcient1 > max)
	{
		max = coeffcient1;
	}
	else if (coeffcient2 > max)
	{
		max = coeffcient2;
	}
	else if (coeffcient3 > max)
	{
		max = coeffcient3;
	}

	float pow_max_coeffcient = max * max;

	/***find root(s) and print that***/
	int counter = 0;
	double test_number = -pow_max_coeffcient;
	double function_value = (test_number * test_number * test_number) + coeffcient3 * (test_number * test_number) + coeffcient2 * test_number + coeffcient1;
	double pre_function_value = function_value;

	while (test_number < pow_max_coeffcient)
	{

		/*calculat 3rd degree function*/
		test_number += approximation;
		function_value = (test_number * test_number * test_number) + coeffcient3 * (test_number * test_number) + coeffcient2 * test_number + coeffcient1;

		/*Bolzano's theorem*/
		if (function_value * pre_function_value <= 0)
		{
			printf("%lf\n", test_number);
			counter++;

			if (counter == 3)
			{
				return 3;
			}

			/*prevent reprint root*/
			if (function_value == 0)
			{
				pre_function_value *= -1;
				continue;
			}
		}

		pre_function_value = function_value;
	}

	for (int i = 0; i < (3 - counter); i++)
	{
		printf("bedoon rishe\n");
	}

	return 0;
}
