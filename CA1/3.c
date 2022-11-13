#include <stdio.h>

#define True 1
#define False 0

int main(void)
{
	/***get input and check that***/
	float coeffcient[3] = {0};

	for (int i = 2; i >= 0; i--)
	{
		scanf("%f", &coeffcient[i]);
	}
	double approximation = 0;

	scanf("%lf", &approximation);

	if (0 >= approximation)
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}

	/***find max and save max ^ 2 ***/
	float max = 1;
	for (int i = 0; i < 3; i++)
	{
		if (coeffcient[i] > max)
		{
			max = coeffcient[i];
		}
	}

	float pow_max_coeffcient = max * max;

	/***find root(s) and print that***/
	int counter = 0;
	double test_number = -pow_max_coeffcient;
	double function_value = (test_number * test_number * test_number) + coeffcient[2] * (test_number * test_number) + coeffcient[1] * test_number + coeffcient[0];
	double pre_function_value = function_value;

	while (test_number < pow_max_coeffcient)
	{

		/*calculat 3rd degree function*/
		test_number += approximation;
		function_value = (test_number * test_number * test_number) + coeffcient[2] * (test_number * test_number) + coeffcient[1] * test_number + coeffcient[0];

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
