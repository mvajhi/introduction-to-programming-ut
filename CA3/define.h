#ifndef UP
#define UP

typedef struct User
{
	int user_id;
	char *name;
	char *password;
	int last_post_id;
	struct User *next;
} User;

typedef struct Post
{
	int user_id;
	char *user_name;
	int post_id;
	int like;
	int *users_id_liked;
	char *txt;
	struct Post *next;
} Post;

#define True 1
#define False 0

#define FIRST_WORD_LENGHT 15
#define FIRST_USER_ID 1
#define FIRST_POST_ID 0
#define LOGIN_AFTER_SIGNIN True
#define INFO_SHOW_PASS True
#define INFO_SHOW_OTHER_USER_PASS False
#define SIZE_OF_NULL 1
#define POST_OUTPUT "posts.txt"
#define USER_OUTPUT "accounts.txt"

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
#define EXPORT 11
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

#endif