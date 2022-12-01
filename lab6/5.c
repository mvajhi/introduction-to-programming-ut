#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


#define SIZE 70
#define SIZE2 2


int compare(char str1[], char str2[])
{
	if (!strcmp(str1, str2))
	{
		printf("TRUE");
	}
	else
	{
		printf("FALSE");
	}
	return 0;
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
