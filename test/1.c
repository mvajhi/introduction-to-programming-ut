#include<stdio.h>


int main(void)
{
	int x = 0, i;
	scanf("%d", &x);
	while (1)
	{
		scanf("%d" , &i);
		printf("%d", x >> (i-1));
	}
	return 0;
}
