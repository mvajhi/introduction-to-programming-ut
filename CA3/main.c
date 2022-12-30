#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

#define True 1
#define False 0

#define FIRST_WORD_LENGHT 15
#define FIRST_USER_ID 1
#define FIRST_POST_ID 0
#define LOGIN_AFTER_SIGNIN True
#define INFO_SHOW_PASS True
#define INFO_SHOW_OTHER_USER_PASS False
#define SIZE_OF_NULL 1

// define switch return
#define TIME_LINE 0
#define SIGNUP 1
#define LOGIN 2
#define POST 3
#define LIKE 4
#define LOGOUT 5
#define DELETE 6
#define INFO 7
#define FIND_USER 8
#define EXIT 9
#define NO_LOGGED 10
#define INVALID -1

// define get_dynamic_string return
#define SUCCESSFUL 1
#define SUCCESSFUL_NO_CLEAR 2
#define EMPTY 0
#define NO_MEMORY -1

// define get_two_arg return
#define SUCCESSFUL_GET_ARG 1
#define FAILED_ARG_ONE -1
#define FAILED_ARG_TWO -2

// define search return
#define FIND 1
#define FIND_BUT_HEAD 2
#define NOT_FIND 0
#define NULL_HEAD -1

// define search_post arg
#define RETURN_CUR 1
#define RETURN_PRE 2

// typedef struct User
// {
// 	int user_id;
// 	char *name;
// 	char *password;
// 	int last_post_id;
// 	struct User *next;
// } User;

// typedef struct Post
// {
// 	int user_id;
// 	char *user_name;
// 	int post_id;
// 	int like;
// 	int *users_id_liked;
// 	char *txt;
// 	struct Post *next;
// } Post;


int main(void)
{
	User *user_head = NULL;
	User *logged = NULL;
	Post *post_head = NULL;

	while (True)
	{
		print_menu(logged);
		log_state(logged);
		switch (first_word(logged))
		{
		case TIME_LINE:
			time_line(post_head);
			break;
		case SIGNUP:
			signup(&user_head, &logged);
			break;
		case LOGIN:
			login(user_head, &logged);
			break;
		case POST:
			posting(logged, &post_head);
			break;
		case LIKE:
			like(post_head, logged);
			break;
		case LOGOUT:
			logout(&logged);
			break;
		case DELETE:
			delete_post(&post_head, logged);
			break;
		case INFO:
			info(logged, post_head, INFO_SHOW_PASS);
			break;
		case FIND_USER:
			other_info(user_head, post_head);
			break;
		case EXIT:
			printf("free memory\n");
			free_memory(user_head, post_head);
			printf("bye!!\n");
			return 1;
		case INVALID:
			printf("Invalid selection\n");
			break;
		case NO_LOGGED:
			printf("You aren't in your account.\nPlease login and try again.\n");
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