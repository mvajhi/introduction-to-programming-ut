#include <stdio.h>

#define True 1
#define False 0

void recoginze(char s[], int sizeString)
{
	int counter = 0;
	for (int i = 0; i < sizeString; i++)
	{
		int flag = True;
		for (int j = 0; j < sizeString; j++)
		{
			if (s[i] == s[j] && i != j)
			{
				flag = False;
				break;
			}
		}

		if (flag)
		{
			counter++;
		}
	}

	if (counter % 2 == 0)
	{
		printf("CHAT WITH THIS USER");
	}
	else
	{
		printf("BLOCK THIS USER");
	}
}
/*
int main(void)
{
	char a[20];
	scanf("%s", a);
	int b = printf("%s", a);
	recoginze(a, b);
	return 0;
}
*/