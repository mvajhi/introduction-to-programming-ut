#include<stdio.h>

#define True 1
#define False 0

int buffer_is_free(void);
int locate_terampolin(int room_number);
int jump_counter (int floor_height, float jump_height, float increase_height);

int main(void)
{
	/*get inputs and check that*/
	int input1 = 0;
	printf("Example: 315\n15 is room number and 3 is floor\n\nEnter room number and floor: ");
	scanf("%i", &input1);

	if (!buffer_is_free() || 0 >= input1 || 0 >= (input1 % 100) || 16 <= (input1 % 100) || 0 >= (input1 / 100))
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}
	
	int room_number = input1 % 100;
	int floor_height = (input1 / 100) * 2 + 1;
	
	float jump_height = 0;
	printf("Enter jump height: ");
	scanf("%f", &jump_height);
	
	if (!buffer_is_free() || 1 <= jump_height || 0 >= jump_height)
	{
		printf("\e[1;31minput wrong\nTry again\n");
		return 0;
	}

	float increase_height = jump_height / 2;

	/*locate trampolini and print that*/
	locate_terampolin(room_number);
	/*count jump and print that*/
	jump_counter(floor_height, jump_height, increase_height);

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

int locate_terampolin(int room_number)
{
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
	return 1;
}

int jump_counter (int floor_height, float jump_height, float increase_height)
{
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
