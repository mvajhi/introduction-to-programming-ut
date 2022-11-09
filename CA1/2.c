#include<stdio.h>

#define True 1
#define False 0

int buffer_is_free(void);
int what_is_food(void);

int main(void)
{
	int day = 0;
	printf("how many days? ");
	scanf("%i", &day);
	
	if (!buffer_is_free() || 0 >= day)
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}
	
	int calories = -day * 100;
	for (int i = 0; i < day; i++)
	{
		calories += what_is_food();
	}

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

/*get number of food and return calories*/
int what_is_food(void)
{
	int food_number = 0;
	printf("what do you like today? ");
	scanf("%i", &food_number);

	while (!buffer_is_free() || 1 > food_number || 10 < food_number)
	{
		printf("\e[1;31minput wrong\e[0m\n");
		printf("what do you like today???? ");
		scanf("%i", &food_number);
	}

	switch (food_number)
	{
		case 1:
			return 329;
		case 2:
			return 127;
		case 3:
			return 61;
		case 4:
			return 83;
		case 5:
			return 156;
		case 6:
			return 296;
		case 7:
			return 496;
		case 8:
			return 73;
		case 9:
			return 34;
		case 10:
			return 16;



	}
	return 0;
}
