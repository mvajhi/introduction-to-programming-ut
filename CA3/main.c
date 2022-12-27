#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define True 1
#define False 0

#define FIRST_WORD_LENGHT 15
#define FIRST_USER_ID 1
#define FIRST_POST_ID 0
#define LOGIN_AFTER_SIGNIN True
#define INFO_SHOW_PASS True
#define INFO_SHOW_OTHER_USER_PASS False
#define RETURN_CUR 1
#define RETURN_PRE 2
#define SIZE_OF_NULL 1

//define switch return
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

//define get_dynamic_string return
#define SUCCESSFUL 1
#define SUCCESSFUL_NO_CLEAR 2
#define EMPTY 0
#define NO_MEMORY -1

//define get_two_arg return
#define SUCCESSFUL_GET_ARG 1
#define FAILED_ARG_ONE -1
#define FAILED_ARG_TWO -2

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
	int *users_id_liked;
	char *txt;
	struct Post *next;
}
Post;

int first_word(User *logged);
int free_buffer(int mod);
int signup(User **head, User **logged);
int get_dynamic_string(char **output, int mod);
int search_name(User *head, User **target, char *name);
int free_memory(User *user_head, Post *post_head);
void log_state(User *logged);
int login(User *head, User **logged);
int get_two_arg(char **arg1, char **arg2);
int logout(User **logged);
void print_menu(User *logged);
int posting(User *logged, Post **head);
int search_post(Post *head, Post **target, char *username, int post_id, int mod);
int like(Post *head, User *logged);
int delete_post(Post **head, User *logged);
int search_liked_user(int *head, int like, int id, int **cur);
int is_number(char *number);
int info(User *user, Post *head, int print_pass);
int other_info(User *u_head, Post *p_head);
int time_line(Post *head);

int main (void)
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

//get first word and return that switch
int first_word(User *logged)
{
	//get input and tolower that
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
	

	//find switch
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
	
	//add to linke list and set data
	User *last_user = NULL;
	if (search_name(*head, &last_user, name))
	{
		printf("This name is already exist\nTry again with another name\n");
		free(name);
		free(password);
		return -3;
	}

	User *new_user = (User *) malloc(sizeof(User));
	
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
	{
		*head = new_user;
	}
	else
	{
		last_user->next = new_user;
	}
	user_id++;

	if(LOGIN_AFTER_SIGNIN)
		*logged = new_user;

	printf("\\\\\\\\\\\\\\\\\n");
	printf("id: %i\nname: %s\npassword: %s\npost_id: %i\n", new_user->user_id, new_user->name, new_user->password, new_user->last_post_id);
	printf("\\\\\\\\\\\\\\\\\n");
	
	return 1;
}

//mod 1 : end when receive (space)
//mod 2 : end when receive (\n)
//mod 3 : end when receive (space) or (\n) and clear buffer
//
//return SUCCESSFUL_NO_CLEAR if succesful in mod 3 with no clear buffer
//return SUCCESSFUL if succseful in mod 1, 2 and mod 3 with clear buffer
//return EMPTY if buffer is empty
//return NO_MEMORY if unsuccesful to get memory
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
			return NO_MEMORY;
		}
		string[len-1] = c;
	}

	if (len == 0)
	{
		printf("buffer is empty\n");
		return EMPTY;
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
			return SUCCESSFUL_NO_CLEAR;
		}
	}

	return SUCCESSFUL;
}

//return 1 if find and else return 0
//save user addres or last user in cur
//args: first pointer of user linked list - pointer to pointer for save user pointer - name of user
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

//print loggin state
void log_state(User *logged)
{
	if(logged == NULL)
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

	if (!search_name(head, &profile, name))
	{
		printf("User not found\nTry again\n");
		free(name);
		free(password);
		return -3;
	}

	if(strcmp(profile->password, password))
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

//get two argument (example: name and password) and check that and buffer
//return 1 if successful if can't get arg 1 return -1 and can't get arg 2 return -2
int get_two_arg(char **arg1, char **arg2)
{
	int flag = get_dynamic_string(arg1, 1);
	if (flag != SUCCESSFUL)
	{
		printf("error %i\nsomthing wrong in dynamic allocat arg1\nTry again\n", flag);
		free(*arg1);
		return FAILED_ARG_ONE;
	}

	flag = get_dynamic_string(arg2, 3);
	if (flag != SUCCESSFUL)
	{
		printf("error %i\nsomthing wrong in dynamic allocat arg2\nTry again\n", flag);
		free(*arg1);
		free(*arg2);
		return FAILED_ARG_TWO;
	}

	return SUCCESSFUL_GET_ARG;
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

int posting(User *logged, Post **head)
{
	char *txt = NULL;
	int flag = get_dynamic_string(&txt, 2);
	if (flag != SUCCESSFUL)
	{
		printf("error %i\nSomthing wrong in dynamic allocat text.\nTry again\n", flag);
		free(txt);
		return -2;
	}

	Post *new_post = (Post *) malloc(sizeof(Post));
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
		if (flag != 0)
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

//if find return 1 and if that is head return 2 and else 0 and -1 if head NULL
//return:
//if mod RETURN_CUR:return that post
//if mod RETURN_PRE:return before post
int search_post(Post *head, Post **target, char *username, int post_id, int mod)
{
	if (head == NULL)
	{
		*target = NULL;
		return -1;
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
			else
				return -2;
			if (cur == head)
				return 2;
			return 1;
		}
		pre = cur;
		cur = cur->next;
	}

	if (mod == RETURN_PRE)
		*target = pre;
	else if (mod == RETURN_CUR)
		*target = cur;
	else
		return -2;
	return 0;
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
	if (flag < 1)
	{
		printf("Post not found.\n");
		free(username);
		free(char_post_id);
		return -4;
	}

	int *cur_to_like = NULL;
	if (search_liked_user(cur->users_id_liked, cur->like, logged->user_id, &cur_to_like))
	{
		printf ("You already liked this post.\n");
		free(username);
		free(char_post_id);
		return -5;
	}
	
	cur->users_id_liked = (int *) realloc(cur->users_id_liked, (cur->like + 1) * sizeof(int));
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

//return 1 if find and else 0
//cur linked to id if not save last
int search_liked_user(int *head, int like, int id, int **cur)
{
	for (int i = 0; i < like; i++)
	{
		if (head[i] == id)
		{
			*cur = head + i;
			return 1;
		}
	}

	*cur = head + like - 1;
	return 0;
}

int delete_post(Post **head, User *logged)
{
	char *char_post_id = NULL;
	int flag = get_dynamic_string(&char_post_id, 3);

	if (flag != SUCCESSFUL)
	{
		printf("error %i\ncan't get post id.\nTry again.\n", flag);
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
	if (flag < 1)
	{
		printf("Post not found.\n");
		free(char_post_id);
		return -4;
	}

	Post *pre;
	Post *next;

	if (flag == 2)
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

//if input is number retrun True else False
int is_number(char *number)
{
	for (int i = 0; i < strlen(number); i++)
	{
		if (!isdigit(number[i]))
			return False;
	}

	return True;
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
		if (flag >= 1)
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
		free(username);
		return -2;
	}

	User *user = NULL;
	flag = search_name(u_head, &user, username);
	if (flag == 0)
	{
		printf("User not found.\n");
		free(username);
		return -1;
	}

	info(user, p_head,INFO_SHOW_OTHER_USER_PASS);

	free(username);
	return 1;
}

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
