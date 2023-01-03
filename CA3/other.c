#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

// get first word and return that switch
int first_word(User *logged)
{
	// get input and tolower that
	char first_word[FIRST_WORD_LENGHT];
	char c = '\0';
	int counter = 0;
	while ((c = getchar()) != ' ' && c != '\n')
	{
		first_word[counter] = c;
		counter++;
		if (counter == (FIRST_WORD_LENGHT - SIZE_OF_NULL))
		{
			free_buffer(1);
			return INVALID;
		}
	}

	first_word[counter] = '\0';

	for (int i = 0; i < strlen(first_word); i++)
	{
		first_word[i] = tolower(first_word[i]);
	}

	// find switch
	int return_val = INVALID;
	if (!strcmp(first_word, "time_line"))
		return_val = TIME_LINE;

	else if (!strcmp(first_word, "signup"))
		return_val = SIGNUP;

	else if (!strcmp(first_word, "login"))
		return_val = LOGIN;

	else if (!strcmp(first_word, "post"))
		return_val = POST;

	else if (!strcmp(first_word, "like"))
		return_val = LIKE;

	else if (!strcmp(first_word, "logout"))
		return_val = LOGOUT;

	else if (!strcmp(first_word, "delete"))
		return_val = DELETE;

	else if (!strcmp(first_word, "info"))
		return_val = INFO;

	else if (!strcmp(first_word, "find_user"))
		return_val = FIND_USER;

	else if (!strcmp(first_word, "exit"))
		return_val = EXIT;

	if ((return_val == TIME_LINE || return_val == INFO || return_val == LOGOUT || return_val == EXIT || return_val == INVALID) && c == ' ')
	{
		if (!free_buffer(2))
			return_val = INVALID;
	}
	else if ((return_val == TIME_LINE || return_val == POST || return_val == LIKE || return_val == DELETE || return_val == FIND_USER || return_val == INFO) && logged == NULL)
	{
		if (c == ' ')
			free_buffer(1);
		return_val = NO_LOGGED;
	}

	return return_val;
}

void print_menu(User *logged)
{
	printf("Command you can use:\n");
	if (logged == NULL)
	{
		printf("\tlogin <username> <password>\n");
		printf("\tsignup <username> <password>\n");
		printf("\texit\n");
	}
	else
	{
		printf("\ttime_line\n");
		printf("\tpost <text>\n");
		printf("\tlike <username> <post id>\n");
		printf("\tdelete <post id>\n");
		printf("\tinfo\n");
		printf("\tfind_user <username>\n");
		printf("\tlogout\n");
		printf("\texit\n");
	}
}

// free memory in end
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

	Post *p_cur = post_head;
	Post *p_pre = post_head;

	while (p_cur != NULL)
	{
		free(p_cur->txt);
		free(p_cur->users_id_liked);

		p_pre = p_cur;
		p_cur = p_cur->next;

		free(p_pre);
	}

	return 1;
}
