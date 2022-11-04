#include<stdio.h>

#define True 1
#define False 0


int main(void)
{
	int input = 0;
	int success = 0;
	
	printf("enter your number: ");
	success = scanf("%d", &input);
	/* check input */
	int buffer = False;
	if(!success || (buffer = getchar()) != '\n')
	{
		printf("Try again\n");
		return 0;
	}

	for (int i = 3; i <= input; i++)
	{
		int is_prime = True;
		
		for(int j = 2; j < i; j++)
		{
			if(i % j == 0)
			{
				is_prime = False;
				break;
			}
		}
	
		if(is_prime)
		{
			printf("%i ", i);
		}
	}
	
	printf("\n");

	return 0;
}
