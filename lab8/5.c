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
		in_order_array[cur] = buffer;
		cur++;
	}	
	fclose(input);
	return in_order_array;
}

void write_in_file(char *in_order_array)
{
	FILE *output = fopen(OUTPUT_FILE_ADDRESS, "a");
	fwrite(in_order_array , sizeof(char), strlen(in_order_array), output);
	fclose(output);
}
int main()
{
	char *in_order_array = read_input_file();
	write_in_file(in_order_array);
	return 0;
}
