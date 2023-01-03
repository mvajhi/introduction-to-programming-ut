#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

#define True 1
#define False 0

// define get_dynamic_string return
#define SUCCESSFUL 1
#define SUCCESSFUL_NO_CLEAR 2
#define EMPTY 0
#define NO_MEMORY -1

// define get_two_arg return
#define SUCCESSFUL_GET_ARG 1
#define FAILED_ARG_ONE -1
#define FAILED_ARG_TWO -2

// return True if free and False if not
// mod 1: flag False when get every char
// mod 2: flag False when get char expect (space)
int free_buffer(int mod)
{
	char c;
	int flag = True;
	while ((c = getchar()) != '\n')
		if (mod == 1 || c != ' ')
			flag = False;
	return flag;
}

// mod 1 : end when receive (space)
// mod 2 : end when receive (\n)
// mod 3 : end when receive (space) or (\n) and clear buffer
//
// return SUCCESSFUL_NO_CLEAR if succesful in mod 3 with no clear buffer
// return SUCCESSFUL if succseful in mod 1, 2 and mod 3 with clear buffer
// return EMPTY if buffer is empty
// return NO_MEMORY if unsuccesful to get memory
// WARNING: if func return SUCCESSFUL_NO_CLEAR string not free
int get_dynamic_string(char **output, int mod)
{
	char *string = NULL;
	char c = '\0';
	int len = 0;
	while (((c = getchar()) != ' ' || mod == 2) && (c != '\n' || mod == 1))
	{
		len++;
		string = (char *)realloc(string, len * sizeof(char));
		if (string == NULL)
		{
			printf("Can't get memory for dynamic string\n");
			free(string);
			return NO_MEMORY;
		}
		string[len - 1] = c;
	}

	if (len == 0)
	{
		printf("buffer is empty\n");
		return EMPTY;
	}

	// add NULL
	string = (char *)realloc(string, (len + 1) * sizeof(char));
	if (string == NULL)
	{
		printf("Can't get memory for dynamic string\n");
		free(string);
		return NO_MEMORY;
	}

	string[len] = '\0';
	*output = string;

	if (mod == 3 && c == ' ')
	{
		if (!free_buffer(2))
		{
			printf("dynamic allocat succes but buffer have more string\n");
			return SUCCESSFUL_NO_CLEAR;
		}
	}

	return SUCCESSFUL;
}

// get two argument (example: name and password) and check that and buffer
// return 1 if successful if can't get arg 1 return -1 and can't get arg 2 return -2
int get_two_arg(char **arg1, char **arg2)
{
	int flag = get_dynamic_string(arg1, 1);
	if (flag != SUCCESSFUL)
	{
		printf("error %i\nsomthing wrong in dynamic allocat arg1\nTry again\n", flag);
		return FAILED_ARG_ONE;
	}

	flag = get_dynamic_string(arg2, 3);
	if (flag != SUCCESSFUL)
	{
		printf("error %i\nsomthing wrong in dynamic allocat arg2\nTry again\n", flag);
		free(*arg1);
		if (flag == SUCCESSFUL_NO_CLEAR)
			free(*arg2);
		return FAILED_ARG_TWO;
	}

	return SUCCESSFUL_GET_ARG;
}

// if input is number retrun True else False
int is_number(char *number)
{
	for (int i = 0; i < strlen(number); i++)
	{
		if (!isdigit(number[i]))
			return False;
	}

	return True;
}