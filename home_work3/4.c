#include <stdio.h>
#include <math.h>

#define True 1
#define False 0

int main2(void);

int main(void)
{
	main2();
	return 0;
}

int main2(void)
{
	int input = 0;
	scanf("%i", &input);

	for (int i = 2; i < input; i++)
	{
		float sqrt_i = sqrt(i);
		int is_prime = True;

		for (int j = 2; j < sqrt_i; j++)
		{
			if (i % j == 0)
			{
				is_prime = False;
				break;
			}
		}

		if (is_prime)
		{
			printf("%i ", i);
		}
	}

	return 0;
}
