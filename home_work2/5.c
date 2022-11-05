#include<stdio.h>



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

	if ((input1 % 10) % (input2 % 10) == 0 || (input2 % 10) % (input1 % 10) == 0)
	{
		printf("false\n");
		return 0;
	}
	else
	{
		printf("true\n");
		return 0;
	}

	return 0;
}
