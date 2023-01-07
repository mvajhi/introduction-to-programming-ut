#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

int posting(User *logged, Post **head)
{
	char *txt = NULL;
	int flag = get_dynamic_string(&txt, 2);
	if (flag != SUCCESSFUL)
	{
		printf("error %i\nSomthing wrong in dynamic allocat text.\nTry again\n", flag);
		return -2;
	}

	Post *new_post = (Post *)malloc(sizeof(Post));
	if (new_post == NULL)
	{
		printf("Can't allocat memory for post.\nTry again.\n");
		free(txt);
		return -3;
	}

	new_post->post_id = ++logged->last_post_id;
	new_post->user_id = logged->user_id;
	new_post->user_name = logged->name;
	new_post->like = 0;
	new_post->users_id_liked = NULL;
	new_post->txt = txt;
	new_post->next = NULL;

	if (*head == NULL)
	{
		*head = new_post;
	}
	else
	{
		Post *cur = NULL;
		flag = search_post(*head, &cur, new_post->user_name, new_post->post_id, RETURN_PRE);
		if (flag != NOT_FIND)
		{
			printf("Somting wrong.\nTry again.\n");
			free(txt);
			free(new_post);
			return -4;
		}
		cur->next = new_post;
	}

	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("user: %s\n", new_post->user_name);
	printf("post_id: %i\n", new_post->post_id);
	printf("like: %i\n", new_post->like);
	printf("post: %s\n", new_post->txt);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

	return 1;
}

// if find return FIND and if that is head return FIND_BUT_HEAD and else NOT_FIND and NULL_HEAD if head NULL
// return:
// if mod RETURN_CUR:return that post
// if mod RETURN_PRE:return before post
int search_post(Post *head, Post **target, char *username, int post_id, int mod)
{
	if (head == NULL)
	{
		*target = NULL;
		return NULL_HEAD;
	}

	Post *cur = head;
	Post *pre = head;

	while (cur != NULL)
	{
		if (!(strcmp(cur->user_name, username)) && cur->post_id == post_id)
		{
			if (mod == RETURN_PRE)
				*target = pre;
			else if (mod == RETURN_CUR)
				*target = cur;

			if (cur == head)
				return FIND_BUT_HEAD;

			return FIND;
		}
		pre = cur;
		cur = cur->next;
	}

	if (mod == RETURN_PRE)
		*target = pre;
	else if (mod == RETURN_CUR)
		*target = cur;

	return NOT_FIND;
}

int like(Post *head, User *logged)
{
	char *username = NULL;
	char *char_post_id = NULL;
	int flag = get_two_arg(&username, &char_post_id);
	if (flag != SUCCESSFUL_GET_ARG)
		return -2;

	if (!is_number(char_post_id))
	{
		printf("Invalid post id.\nTry again.\n");
		free(username);
		free(char_post_id);
		return -3;
	}

	Post *cur = NULL;
	flag = search_post(head, &cur, username, atoi(char_post_id), RETURN_CUR);
	if (flag != FIND && flag != FIND_BUT_HEAD)
	{
		printf("Post not found.\n");
		free(username);
		free(char_post_id);
		return -4;
	}

	int *cur_to_like = NULL;
	if (FIND == search_liked_user(cur->users_id_liked, cur->like, logged->user_id, &cur_to_like))
	{
		printf("You already liked this post.\n");
		free(username);
		free(char_post_id);
		return -5;
	}

	cur->users_id_liked = (int *)realloc(cur->users_id_liked, (cur->like + 1) * sizeof(int));
	if (cur->users_id_liked == NULL)
	{
		printf("can't allocat memory for save your id in the post for like.\nTry again.\n");
		free(username);
		free(char_post_id);
		return -6;
	}

	cur->users_id_liked[cur->like] = logged->user_id;
	cur->like++;

	free(username);
	free(char_post_id);

	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("like: %i\n", cur->like);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	return 1;
}

// print all posts
int time_line(Post *head)
{
	Post *cur = head;

	while (cur != NULL)
	{
		printf("\t\\\\\\\\\\\\\\\\\\\n");
		printf("\t\tusername: %s\n", cur->user_name);
		printf("\t\tpost id: %i\n", cur->post_id);
		printf("\t\tlike: %i\n", cur->like);
		printf("\t\tpost: %s\n", cur->txt);
		printf("\t\\\\\\\\\\\\\\\\\\\n");

		cur = cur->next;
	}
}

int delete_post(Post **head, User *logged)
{
	char *char_post_id = NULL;
	int flag = get_dynamic_string(&char_post_id, 3);

	if (flag != SUCCESSFUL)
	{
		printf("error %i\ncan't get post id.\nTry again.\n", flag);
		if (flag == SUCCESSFUL_NO_CLEAR)
			free(char_post_id);
		return -2;
	}

	if (!is_number(char_post_id))
	{
		printf("Invalid post id.\nTry again.\n");
		free(char_post_id);
		return -3;
	}

	Post *cur = NULL;
	flag = search_post(*head, &cur, logged->name, atoi(char_post_id), RETURN_PRE);
	if (flag != FIND && flag != FIND_BUT_HEAD)
	{
		printf("Post not found.\n");
		free(char_post_id);
		return -4;
	}

	Post *pre;
	Post *next;

	if (flag == FIND_BUT_HEAD)
	{
		next = cur->next;
		*head = next;
	}
	else
	{
		pre = cur;
		cur = cur->next;
		next = cur->next;

		pre->next = next;
	}

	free(cur->txt);
	free(cur->users_id_liked);
	free(cur);

	free(char_post_id);

	return 1;
}

// return FIND if find and else NOT_FIND
// cur linked to id if not save last
int search_liked_user(int *head, int like, int id, int **cur)
{
	for (int i = 0; i < like; i++)
	{
		if (head[i] == id)
		{
			*cur = head + i;
			return FIND;
		}
	}

	*cur = head + like - 1;
	return NOT_FIND;
}

//return how meny post this user id send
int post_counter(Post *head, int user_id)
{
	Post *cur = head;
	int counter = 0;
	while (cur != NULL)
	{
		if (cur->user_id == user_id)
			counter++;
		cur = cur->next;
	}
	return counter;
}