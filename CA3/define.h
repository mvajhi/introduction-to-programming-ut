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