#include<stdio.h>

int fact(int x);

int main(void)
{
	int input = 0;

	printf("Enter your number: ");
	scanf("%i", &input);
	/*check buffer*/
	if (getchar() != '\n')
	{
		printf("Try again\n");
		return 0;
	}

	int sign = -1;
	int sum = 0;

	for (int i = 0; i < input; i++)
	{
		sign *= -1;
		sum += sign * fact(i);
	}

	printf("result: %i\n", sum);

	return 0;
}

int fact(int x)
{
	if (x > 1)
	{
		return x * fact(x - 1);
	}
	else
	{
		return 1;
	}
}
