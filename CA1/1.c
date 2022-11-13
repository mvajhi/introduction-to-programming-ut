#include <stdio.h>

#define True 1
#define False 0

int main(void)
{
	/******get inputs and check that******/
	/*get room and floor number*/
	int input1 = 0;

	scanf("%i", &input1);

	if (0 >= input1 || 0 >= (input1 % 100) || 16 <= (input1 % 100) || 0 >= (input1 / 100))
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}

	int room_number = input1 % 100;
	int floor_height = (input1 / 100) * 2 + 1;

	/*get jump height*/
	float jump_height = 0;
	scanf("%f", &jump_height);

	if (1 <= jump_height || 0 >= jump_height)
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}

	float increase_height = jump_height / 2;

	/******locate trampolini and print that******/

	if (1 <= room_number && room_number <= 4)
	{
		printf("1\n");
	}
	else if (5 <= room_number && room_number <= 8)
	{
		printf("2\n");
	}
	else if (9 <= room_number || room_number <= 12)
	{
		printf("3\n");
	}
	else if (13 <= room_number || room_number <= 16)
	{
		printf("4\n");
	}
	else
	{
		printf("error\n");
		return 0;
	}

	/******count jump and print that******/

	float height = jump_height;
	int counter = 0;
	while (floor_height > height)
	{
		height += increase_height;
		counter++;
	}

	printf("%i\n", counter);

	return 1;
}
