#include<stdio.h>

#define True 1
#define False 0

int buffer_is_free(void);
float pow_max(float numbers[3]);
int find_roots(float coeffcient[3], float pow_max_coeffcient , double approximation);
double function(double x, float coeffcient[3]);

int main(void)
{
	/*get input and check that*/
	float coeffcient[3] = {0};
	
	printf("sort coeffient like this:\nx²: 2\nx: 1\nc: 0\n\n");

	for (int i = 2; i >= 0; i--)
	{
		printf("Enter %i coeffcient: ", i);
		scanf("%f", &coeffcient[i]);
	
		if (!buffer_is_free())
		{
			printf("\e[1;31minput wrong\nTry again\n");
			return 0;
		}
	}
	
	double approximation = 0;

	printf("\nEnter approximation: ");
	scanf("%lf", &approximation);


	if (!buffer_is_free() || 0 >= approximation)
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}

	float pow_max_coeffcient = pow_max(coeffcient);
	
	find_roots(coeffcient, pow_max_coeffcient ,approximation);

	return 0;
}

/*check buffer is free and if not free that*/
int buffer_is_free(void)
{
	int is_free = True;

	while (getchar() != '\n')
	{
		is_free = False;
	}
	
	return is_free;
}

/*find max and return max ^ 2 */
float pow_max(float numbers[3])
{
	float max = 1;
	for (int i = 0; i < 3; i++)
	{
		if (numbers[i] > max)
		{
			max = numbers[i];
		}
	}

	return max * max;
}

/*find root(s) and print that*/
int find_roots(float coeffcient[3], float pow_max_coeffcient , double approximation)
{
	int counter = 0;
	double test_number = -pow_max_coeffcient;
	double function_value = function(test_number, coeffcient);
	double pre_function_value = function_value;

	while (test_number < pow_max_coeffcient)
	{
		test_number += approximation;
		function_value = function(test_number, coeffcient);
		
		/*Bolzano's theorem*/
		if (function_value * pre_function_value <= 0)
		{
			printf("%.2lf\n", test_number);
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

	return counter;
}

/*calculat 3rd degree function*/
double function(double x, float coeffcient[3])
{
	return (x * x * x) + coeffcient[2] * (x * x) + coeffcient[1] * x + coeffcient[0];
}
