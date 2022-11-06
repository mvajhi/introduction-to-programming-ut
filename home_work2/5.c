#include<stdio.h>

#define True 1
#define False 0

int main(void)
{
	int input1 = 0, input2 = 0;
	int success = 0;
	printf("Example: 10 11\nEnter your numbers with space: ");
	success = scanf("%i %i", &input1, &input2);
	/*check input successful*/
	if ((getchar() != '\n') || success != 2 || input1 <= 0 || input2 <= 0)
	{
		printf("Try again\n");
		return 0;
	}
	
	int first_digit1 = input1 % 10;
	int first_digit2 = input2 % 10;
	
	if (first_digit1 == 0 || first_digit2 == 0)
	{
		printf("false\n");
		return 0;
	}

	int is_prime = True;

	for (int i = 2; i < 10; i++)
	{
		if (first_digit1 % i == 0 && first_digit2 % i == 0)
		{
			is_prime = False;
			break;
		}
	}

	if (is_prime == True)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	return 0;
}
