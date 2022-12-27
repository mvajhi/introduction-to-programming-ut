#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZERO 0
#define ONE 1
#define READ_CHAR_SIZE 100
#define WRITE_CHAR_SIZE 100
#define INPUT_TXT_ADDRESS "input.txt"
#define OUTPUT_FILE_ADDRESS "output.txt"
char *read_input_file()
{
	char *in_order_array = (char *)malloc(READ_CHAR_SIZE * sizeof(char));
	FILE *input = fopen(INPUT_TXT_ADDRESS, "r");
	
	char buffer;
	int cur = 0;
	while ((buffer = fgetc(input)) != EOF)
	{
		fseek(input,3,SEEK_CUR);
		in_order_array[cur] = buffer;
		cur++;
	}	
	fclose(input);
	return in_order_array;
}
char *reverse_array(char *in_order_array)
{
	char *reversed_array = (char *)malloc(READ_CHAR_SIZE * sizeof(char));
	int len = strlen(in_order_array);
	for (int i = ZERO; i < len; i++)
	{
		reversed_array[i] = in_order_array[len - 1 - i];
	}
	return reversed_array;
}
void write_reversed_array_in_file(char *in_order_array)
{
	char *reversed_array = reverse_array(in_order_array);
	FILE *output = fopen(OUTPUT_FILE_ADDRESS, "w");
	fwrite(reversed_array , sizeof(char), strlen(reversed_array), output);
	fclose(output);
}
int main()
{
	char *in_order_array = read_input_file();
	write_reversed_array_in_file(in_order_array);
	return 0;
}
