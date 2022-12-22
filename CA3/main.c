#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int first_word();

int main (void)
{
	while (True)
	{
		//TODO get input
		//TODO check first word
		//TODO send to that switch
		switch (first_word())
		{
			case 1:
				printf("singup\n");
				break;
			case 2:
				printf("login\n");
				break;
			case 3:
				printf("post\n");
				break;
			case 4:
				printf("like\n");
				break;
			case 5:
				printf("logout\n");
				break;
			case 6:
				pritnf("delete\n");
				break;
			case 7:
				printf("info\n");
				break;
			case 8:
				printf("free memory\n");
				printf("bye!!\n");
				return 1;
			default:
				printf("error\n");
				break;
		}
	}
