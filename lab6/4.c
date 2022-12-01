#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


#define SIZE 70
#define SIZE2 2


int compare(char str1[], char str2[])
{
	int max = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);
	for (int i = 0; i < max; i++)
	{
		if (str1[i] != str2[i])
		{
			printf("FALSE\n");
			return 0;
		}
	}
	printf("TRUE\n");
	return 1;
}

int main(void)
{
	int i, sum = 0;
	char num[2][SIZE];
	for (i = 0; i < SIZE2; i++)
	{
		scanf("%s",  num[i]);
	}
	compare (num[0] , num[1]);
	return 0;
}
