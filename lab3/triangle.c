#include <stdio.h>

int main(void)
{

	int length = 0;

	do
	{
		printf("enter length: ");
		scanf("%i", &length);
	} while (length % 2 != 1);

	for (int i = 1; i <= length; i += 2)
	{
		for (int j = 0; j < (length - i + 1) / 2; j++)
		{
			printf("-");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		for (int j = 0; j < (length - i + 1) / 2; j++)
		{
			printf("-");
		}
		printf("\n");
	}

	return 0;
}
