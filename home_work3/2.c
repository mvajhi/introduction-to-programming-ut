#include <stdio.h>
#include <math.h>

#define True 1
#define False 0

int is_reverse(int number1, int number2);
int reverse_number(int number);
int main2(void);

int main(void)
{
	main2();
	return 0;
}

int main2(void)
{
	/*get input*/
	int input[2] = {0};

	scanf("%i , %i", &input[0], &input[1]);

	/*check are they reverse*/
	if (is_reverse(input[0], input[1]))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

	return 0;
}

/*check 2 number are reverse or no*/
int is_reverse(int number1, int number2)
{
	int reverse_num1 = reverse_number(number1);

	if (reverse_num1 == number2)
	{
		return True;
	}
	else
	{
		return False;
	}
}

/*reverse a number and return that*/
int reverse_number(int number)
{
	int reverse_num = 0;
	while (number > 0)
	{
		reverse_num *= 10;
		reverse_num += number % 10;
		number /= 10;
	}

	return reverse_num;
}
