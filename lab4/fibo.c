#include<stdio.h>

long fibo(int n);


int main(void)
{
	int input = 0;

	printf("Enter your number: ");
	scanf("%i", &input);

	/*check buffer*/
	if (getchar() != '\n' || input <= 0)
	{
		printf("Try again\n");
		return 0;
	}

	printf("result: %li\n", fibo(input));

	return 1;
}

long fibo(int n)
{
	if (n > 2)
	{
		return fibo(n - 1) + fibo(n - 2);
	}
	else
	{
		return 1;
	}
}
