#include <stdio.h>


int main(void)
{
	int a = 3;
	int b = 5;
	b = b ^ 2;
	while(a > 0)
	{
		printf("%d\n", b % a);
		a -= a;
	}
	a += a * b;
	b = b / (++a);
	printf("a:%i\nb:%i\n",a,b);
	while(b > a)
	{
		b--;
		printf("%d %d\n", b , a);
		break;
	}
	char c = 'c';
	scanf("%c", &c);
	printf("%c", c);
	return 0;
	printf("ICSP 01!");
}
