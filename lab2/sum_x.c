#include<stdio.h>


int main(void)
{

	float x = 0.3;

	printf("%.30f\n", x + x + x + x + x + x + x + x + x + x);
	printf("%.5f\n", x + x + x + x + x + x + x + x + x + x);

	return 0;
}
