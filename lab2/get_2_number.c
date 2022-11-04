#include <stdio.h>

int main(void)
{

	int a = 0, b = 0;

	printf("enter 2 numbers with space: ");
	scanf("%i %i", &a, &b);

	printf("%i\n", ((a + b) << 2) % 3);

	return 0;
}
