#include<stdio.h>


int main(void)
{

	char a = 'a';

	printf("enter your number: ");
	scanf("%hhd", &a);

	printf("decimall to character is \e[1m%c\e[m.\n", a);

	return 0;
}
