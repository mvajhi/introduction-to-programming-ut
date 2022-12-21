#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

sort(int *a ,int *b, int *c);

int main() 
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	sort(&a, &b, &c);
	printf("%d < %d < %d", a, b, c);
	return 0;
}
void sort(int *a ,int *b, int *c)
{
	int tmp = 0;

	if (*a > *b)
	{

}
