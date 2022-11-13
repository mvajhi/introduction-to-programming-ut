#include<stdio.h>
#include<math.h>

int main(void)
{
	int input = 0;
	scanf("%i", &input);

	for (int i = 2; i < (float)sqrt(input); i++)
	{
		if (input % i == 0)
		{
			printf("%i ", i);
		}
	}

	return 0;
}
