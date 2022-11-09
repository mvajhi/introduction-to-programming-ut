#include<stdio.h>


int main(void)
{
	int i = 0;
	int j = 0;
	
	int k = 2;

	for (int j = 0; j < 12; j += 2)
	{
		for (k = 0; k < 5; k++)
			i+=4;
	}

	printf("%i",i);



	return 0;
}

