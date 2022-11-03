#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0

int is_buffer_free(void);

int main(void)
{
	int seed = 810101558;
	srand(seed);

	int random_number = rand() % 100;


	while(True)
	{
		int guess = 0;

		printf("guess: ");
		scanf("%i", &guess);
		if(!is_buffer_free())
		{
			printf("error\n");
			continue;
		}

		if(guess > random_number)
		{
			printf("smaller than your guess.\n");
		}
		else if(guess < random_number)
		{
			printf("bigger than your guess.\n");
		}
		else
		{
			printf("\e[2;32mthat right!!!\e[0m\n");
			return 0;
		}
	}

	return 0;
}


/*check buffer is free and if not clear that*/
int is_buffer_free(void)
{
    int c;
    int is_free = True;
    while ((c = getchar()) != '\n') {is_free = False;}
    return is_free;
}


