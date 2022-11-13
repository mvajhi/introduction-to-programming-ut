#include <stdio.h>

#define True 1
#define False 0

int main(void)
{
	/*get how many day and check input*/
	int day = 0;
	scanf("%i", &day);

	if (0 >= day)
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}

	/*calculat burned calories*/
	int calories = -day * 100;

	/*get number of food and add to calories*/
	for (int i = 0; i < day; i++)
	{

		int food_number = 0;
		scanf("%i", &food_number);

		while (1 > food_number || 10 < food_number)
		{
			printf("\e[1;31minput wrong\e[0m\n");
			printf("what do you like today???? ");
			scanf("%i", &food_number);
		}

		switch (food_number)
		{
		case 1:
			calories += 329;
			break;
		case 2:
			calories += 127;
			break;
		case 3:
			calories += 61;
			break;
		case 4:
			calories += 83;
			break;
		case 5:
			calories += 156;
			break;
		case 6:
			calories += 296;
			break;
		case 7:
			calories += 496;
			break;
		case 8:
			calories += 73;
			break;
		case 9:
			calories += 34;
			break;
		case 10:
			calories += 16;
			break;
		}
	}

	/***check calories and print ans***/
	if (calories > 0)
	{
		printf("chage\n");
	}
	else if (calories < 0)
	{
		printf("lagahr\n");
	}
	else
	{
		printf("bedoon taghir\n");
	}

	return 0;
}
