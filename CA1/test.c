#include<stdio.h>


int main(void)
{
	int a = 1;
	int* b = &a;
	int c = 2;
	*b = 2;


	printf("%i\n", a);
	return 0;
}
