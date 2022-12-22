#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define True 1
#define False 0

#define FIRST_WORD_LENGHT 10

typedef struct User
{
	int user_id;
	char *name;
	char *password;
	int last_post_id;
	struct User *next;
}
User;

typedef struct Post
{
	int user_id;
	char *user_name;
	int post_id;
	int like;
	char *txt;
	struct Post *next;
}
Post;

int first_word();
int free_buffer();

int main (void)
{
	while (True)
	{
		switch (first_word())
		{
			case 0:
				printf("time line\n");
				free_buffer();
				break;
			case 1:
				printf("singup\n");
				break;
			case 2:
				printf("login\n");
				break;
			case 3:
				printf("post\n");
				break;
			case 4:
				printf("like\n");
				break;
			case 5:
				printf("logout\n");
				break;
			case 6:
				printf("delete\n");
				break;
			case 7:
				printf("info\n");
				break;
			case 8:
				printf("find user\n");
				break;
			case 9:
				printf("free memory\n");
				printf("bye!!\n");
				return 1;
			case -1:
				printf("Invalid selection\n");
				printf("free buffer\n");
				free_buffer();
				break;
			default:
				printf("error\n");
				printf("free buffer\n");
				free_buffer();
				break;
		}
	}
	return -1;
}

//get first word and return that switch
int first_word()
{
	//get input and tolower that
	char first_word[FIRST_WORD_LENGHT];
	scanf("%s", first_word);

	for (int i = 0; i < strlen(first_word); i++)
	{
		first_word[i] = tolower(first_word[i]);
	}
	

	//find switch
	int return_val = -2;
	if (!strcmp(first_word, "time_line"))
		return 0;

	else if (!strcmp(first_word, "singup"))
		return_val = 1;

	else if (!strcmp(first_word, "login"))
		return_val = 2;

	else if (!strcmp(first_word, "post"))
		return_val = 3;

	else if (!strcmp(first_word, "like"))
		return_val = 4;

	else if (!strcmp(first_word, "logout"))
		return_val = 5;

	else if (!strcmp(first_word, "delete"))
		return_val = 6;

	else if (!strcmp(first_word, "info"))
		return_val = 7;

	else if (!strcmp(first_word, "find_user"))
		return_val = 8;

	else if (!strcmp(first_word, "exit"))
		return 9;

	else
		return -1;

	//apart from exit and time line, the others get more than argument
	//remove space
	char c = getchar();

	return return_val;
}

//return True if free and False or not
int free_buffer()
{
	char c;
	int flag = True;
	while ((c = getchar()) != '\n')
		flag = False;
	return flag;
}
