#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *input = fopen("input.bmp", "rb");
	if (input == NULL)
	{
		printf("can't open\n");
		return -1;
	}

	int header[154];
	unsigned char RGB[50][50][3];

	fread(header, 154, 1, input);

	for (int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			fread(RGB[i][j], sizeof(unsigned char), 3, input);
			for (int k = 0; k < 3; k++)
			{
				RGB[i][j][k] += 100;
			}
		}
	}

	fclose(input);

	FILE *output = fopen("output.bmp", "wr");

	fwrite(header, 154, 1, output);

	for (int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			fwrite(RGB[i][j], sizeof(unsigned char), 3, output);
		}
	}

	fclose(output);
	return 0;
}
