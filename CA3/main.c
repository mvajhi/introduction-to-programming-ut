#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

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