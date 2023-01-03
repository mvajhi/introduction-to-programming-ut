#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

int signup(User **head, User **logged)
{
	if (*logged != NULL)
	{
		printf("You are already logged in\nPlease logout and try again\n");
		free_buffer(1);
		return -1;
	}

	char *name = NULL;
	char *password = NULL;
	int flag = get_two_arg(&name, &password);
	if (flag != SUCCESSFUL_GET_ARG)
		return -2;

	// add to linke list and set data
	User *last_user = NULL;
	if (search_name(*head, &last_user, name) == FIND)
	{
		printf("This name is already exist\nTry again with another name\n");
		free(name);
		free(password);
		return -3;
	}

	User *new_user = (User *)malloc(sizeof(User));
	if (new_user == NULL)
	{
		printf("Can't get memory for signup\nTry again\n");
		free(name);
		free(password);
		return -4;
	}

	static int user_id = FIRST_USER_ID;
	new_user->user_id = user_id;
	new_user->name = name;
	new_user->password = password;
	new_user->last_post_id = FIRST_POST_ID;
	new_user->next = NULL;

	if (*head == NULL)
		*head = new_user;
	else
		last_user->next = new_user;

	user_id++;

	if (LOGIN_AFTER_SIGNIN)
		*logged = new_user;

	printf("\\\\\\\\\\\\\\\\\n");
	printf("id: %i\nname: %s\npassword: %s\n", new_user->user_id, new_user->name, new_user->password);
	printf("\\\\\\\\\\\\\\\\\n");

	return 1;
}

// print loggin state
void log_state(User *logged)
{
	if (logged == NULL)
	{
		printf("\nYou aren't logged in. Log in for more features!\n");
	}
	else
	{
		printf("\nYou are logged in with %s\n", logged->name);
	}
}

int login(User *head, User **logged)
{
	User *profile = NULL;
	char *name = NULL;
	char *password = NULL;
	int flag = get_two_arg(&name, &password);
	if (flag != SUCCESSFUL_GET_ARG)
		return -1;

	if (*logged != NULL)
	{
		printf("You are in an account.\nPlease logout and try again\n");
		free(name);
		free(password);
		return -2;
	}

	if (search_name(head, &profile, name) == NOT_FIND)
	{
		printf("User not found\nTry again\n");
		free(name);
		free(password);
		return -3;
	}

	if (strcmp(profile->password, password))
	{
		printf("Password incorrect\nTry again\n");
		free(name);
		free(password);
		return -4;
	}

	*logged = profile;
	free(name);
	free(password);

	return 1;
}

int logout(User **logged)
{
	if (*logged == NULL)
	{
		printf("You are already logout.\n");
		return 0;
	}

	*logged = NULL;
	printf("You have successfully logged out\nSee you later!!\n");
	return 1;
}

// return FIND if find and else return NOT_FIND
// save user addres or last user in cur
// args: first pointer of user linked list - pointer to pointer for save user pointer - name of user
int search_name(User *head, User **target, char *name)
{
	User *cur = head;
	User *pre = head;

	while (cur != NULL)
	{
		if (!strcmp(cur->name, name))
		{
			*target = cur;
			return FIND;
		}

		pre = cur;
		cur = cur->next;
	}

	*target = pre;
	return NOT_FIND;
}

int info(User *user, Post *head, int print_pass)
{
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("\tid: %i\n", user->user_id);
	printf("\tusername: %s\n", user->name);
	if (print_pass)
		printf("\tpassword: %s\n", user->password);
	for (int i = 1; i <= user->last_post_id; i++)
	{
		Post *cur = NULL;
		int flag = search_post(head, &cur, user->name, i, RETURN_CUR);
		if (flag == FIND || flag == FIND_BUT_HEAD)
		{
			printf("\t\t\\\\\\\\\\\\\\\\\\\n");
			printf("\t\t\tpost id: %i\n", cur->post_id);
			printf("\t\t\tlike: %i\n", cur->like);
			printf("\t\t\tpost: %s\n", cur->txt);
			printf("\t\t\\\\\\\\\\\\\\\\\\\n");
		}
	}
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\n");
	return 1;
}

int other_info(User *u_head, Post *p_head)
{
	char *username = NULL;
	int flag = get_dynamic_string(&username, 3);

	if (flag != SUCCESSFUL)
	{
		printf("error %i\ncan't get username.\nTry again.\n", flag);
		if (flag == SUCCESSFUL_NO_CLEAR)
			free(username);
		return -2;
	}

	User *user = NULL;
	flag = search_name(u_head, &user, username);
	if (flag == NOT_FIND)
	{
		printf("User not found.\n");
		free(username);
		return -1;
	}

	info(user, p_head, INFO_SHOW_OTHER_USER_PASS);

	free(username);
	return 1;
}