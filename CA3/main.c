#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define True 1
#define False 0

#define FIRST_WORD_LENGHT 10
#define FIRST_USER_ID 1
#define FIRST_POST_ID 1

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
int free_buffer(int mod);
int signup(User **head, User *logged);
int get_dynamic_string(char **output, int mod);
int search_name(User *head, User **target, char *name);
int free_memory(User *user_head, Post *post_head);

int main (void)
{
	User *user_head = NULL;
	User *logged = NULL;
	Post *post_head = NULL;

	while (True)
	{
		switch (first_word())
		{
			case 0:
				printf("time line\n");
				free_buffer(1);
				break;
			case 1:
				signup(&user_head, logged);
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
				free_memory(user_head, post_head);
				printf("bye!!\n");
				return 1;
			case -1:
				printf("Invalid selection\n");
				printf("free buffer\n");
				free_buffer(1);
				break;
			default:
				printf("error\n");
				printf("free buffer\n");
				free_buffer(1);
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

	else if (!strcmp(first_word, "signup"))
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

//return True if free and False if not
//mod 1: flag False when get every char
//mod 2: flag False when get char expect (space)
int free_buffer(int mod)
{
	char c;
	int flag = True;
	while ((c = getchar()) != '\n')
		if (mod == 1 || c != ' ')
			flag = False;
	return flag;
}

int signup(User **head, User *logged)
{
	if (logged != NULL)
	{
		printf("You are already logged in\nPlease logout and try again\n");
		return -1;
	}
	
	//get name and password and check that and buffer
	char *name = NULL;
	int flag = get_dynamic_string(&name, 1);
	if (flag != 1)
	{
		printf("error %i\nsomthing wrong in dynamic allocat name\nTry again\n", flag);
		free(name);
		return -2;
	}

	char *password = NULL;
	flag = get_dynamic_string(&password, 3);
	if (flag != 1)
	{
		printf("error %i\nsomthing wrong in dynamic allocat password\nTry again\n", flag);
		free(name);
		free(password);
		return -3;
	}
	
	//add to linke list and set data
	User *last_user = NULL;
	if (search_name(*head, &last_user, name))
	{
		printf("This name is already exist\nTry again with another name\n");
		free(name);
		free(password);
		return -5;
	}

	User *new_user = (User *) malloc(sizeof(User));
	
	if (new_user == NULL)
	{
		printf("Can't get memory for signup\nTry again\n");
		free(name);
		free(password);
		return -6;
	}

	static user_id = FIRST_USER_ID;
	new_user->user_id = user_id;
	new_user->name = name;
	new_user->password = password;
	new_user->last_post_id = FIRST_POST_ID;
	new_user->next = NULL;
	if (*head == NULL)
	{
		*head = new_user;
		printf("hi\n");
	}
	else
	{
		last_user->next = new_user;
	}
	user_id++;

	printf("\\\\\\\\\\\\\\\\\n");
	printf("id: %i\nname: %s\npassword: %s\npost_id: %i\n", new_user->user_id, new_user->name, new_user->password, new_user->last_post_id);
	printf("\\\\\\\\\\\\\\\\\n");
	
	return 1;
}

//mod 1 : end when receive (space)
//mod 2 : end when receive (\n)
//mod 3 : end when receive (space) or (\n) and clear buffer
//
//return 2 if succesful in mod 3 with no clear buffer
//return 1 if succseful in mod 1, 2 and mod 3 with clear buffer
//return 0 if buffer is empty
//return -1 if unsuccesful to get memory
int get_dynamic_string(char **output, int mod)
{
	char *string = NULL;
	char c = '\0';
	int len = 0;
	while (((c = getchar()) != ' ' || mod == 2) && (c != '\n' || mod == 1))
	{
		len++;
		string = (char *) realloc(string, len * sizeof(char));
		if (string == NULL)
		{
			printf("Can't get memory for dynamic string\n");
			free(string);
			return -1;
		}
		string[len-1] = c;
	}

	if (len == 0)
	{
		printf("buffer is empty\n");
		return 0;
	}

	//add NULL
	string = (char *) realloc(string, (len + 1) * sizeof(char));
	string[len] = '\0';
	*output = string;

	if (mod == 3 && c == ' ')
	{
		if (!free_buffer(2))
		{
			printf("dynamic allocat succes but buffer have more string\n");
			return 2;
		}
	}

	return 1;
}

//return 1 if find and else return 0
//save user addres or last user in cur
int search_name(User *head, User **target, char *name)
{
	User *cur = head;
	User *pre = head;

	while (cur != NULL)
	{
		if (!strcmp(cur->name, name))
		{
			*target = cur;
			return 1;
		}
		
		pre = cur;
		cur = cur->next;
	}

	*target = pre;
	return 0;
}

//free memory
int free_memory(User *user_head, Post *post_head)
{
	User *u_cur = user_head;
	User *u_pre = user_head;

	while (u_cur != NULL)
	{
		free(u_cur->name);
		free(u_cur->password);
		
		u_pre = u_cur;
		u_cur = u_cur->next;

		free(u_pre);
	}

	//TODO post free
	
	return 1;
}