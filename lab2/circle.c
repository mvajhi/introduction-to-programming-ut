#include <stdio.h>
#define PI 3.1416

int main(void)
{

	double r = 0, area = 0;

	printf("enter radius: ");
	scanf("%lf", &r);

	area = r * r * PI;

	printf("area is \e[1m%.3f\e[m.\n", area);

	return 0;
}
