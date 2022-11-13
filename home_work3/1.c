/*we remove input printf and user message for similar to the example*/

#include <stdio.h>
#include <math.h>

int root_finder(float a, float b, float c);

int main(void)
{
	/*get coefficient (ax^2 + bx + c)*/
	float user_input[3] = {0};

	scanf("a = %f , b = %f , c = %f", &user_input[0], &user_input[1], &user_input[2]);

	root_finder(user_input[0], user_input[1], user_input[2]);

	return 0;
}

/* calculat roots of ax^2 + bx + c */
int root_finder(float a, float b, float c)
{
	/*calculat delta*/
	float delta = (b * b) - (4 * a * c);

	if (delta < 0)
	{
		printf("NO ROOT FOUND");
		return 0;
	}

	/*calculat roots*/
	float root[2] = {0};
	root[0] = (-b + sqrt(delta)) / (2 * a);
	root[1] = (-b - sqrt(delta)) / (2 * a);

	/*print roots*/
	printf("%f , %f", root[0], root[1]);

	return 1;
}
