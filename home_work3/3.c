#include<stdio.h>

#define NUM_WORKER 4
#define CYCLE 48

int main(void)
{
	int hours = 0;

	scanf("%i", &hours);

	/*skip complete cycle*/
	hours %= CYCLE;
	char worker[NUM_WORKER] = {'A', 'B', 'C', 'D'};
	
	for (int i = 0; i < NUM_WORKER; i++)
	{
		if ((i + 1) * 12 > hours)
		{
			printf("%c", worker[i]);
			return 0;
		}
	}

	return 0;
}
