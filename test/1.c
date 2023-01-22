#include <stdio.h>

int main()
{
int n = 123;
int s = 0;

while (s!=321)
{
	int r = n%10;
	s=321;
	int n = n/10;
}

printf("%i",s);

	return 0;
}