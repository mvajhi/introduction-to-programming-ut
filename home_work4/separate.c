#include <stdio.h>

#define True 1
#define False 0
#define SIZE 50

void separate(int arr[], int sizeArr)
{
	int odd[SIZE] = {0};
	int even[SIZE] = {0};
	int size_odd = 0;
	int size_even = 0;

	/*separate odd & even*/
	for (int i = 0; i < sizeArr; i++)
	{
		if (arr[i] % 2 == 1)
		{
			odd[size_odd] = arr[i];
			size_odd++;
		}
		else
		{

			even[size_even] = arr[i];
			size_even++;
		}
	}

	/*sort odd*/
	for (int i = 0; i < size_odd; i++)
	{
		for (int j = 0; j < size_odd - i - 1; j++)
		{
			if (odd[j] > odd[j + 1])
			{
				int tmp = odd[j + 1];
				odd[j + 1] = odd[j];
				odd[j] = tmp;
			}
		}
	}

	/*sort even*/
	for (int i = 0; i < size_even; i++)
	{
		for (int j = 0; j < size_even - i - 1; j++)
		{
			if (even[j] > even[j + 1])
			{
				int tmp = even[j + 1];
				even[j + 1] = even[j];
				even[j] = tmp;
			}
		}
	}
	/*print odd*/
	for (int i = 0; i < size_odd; i++)
	{
		printf("%i", odd[i]);
		if (i != size_odd - 1)
		{
			printf(",");
		}
	}
	printf("\n");
	/*print even*/
	for (int i = 0; i < size_even; i++)
	{
		printf("%i", even[i]);
		if (i != size_even - 1)
		{
			printf(",");
		}
	}
}

/*
int main(void)
{
	int a[] = {6, 9, 3, 8, 7, 10, 1};
	separate(a, 7);
	return 0;
}
*/
