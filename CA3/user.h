int signup(User **head, User **logged);
void log_state(User *logged);
int login(User *head, User **logged);
int logout(User **logged);
int search_name(User *head, User **target, char *name);
int info(User *user, Post *head, int print_pass);
int other_info(User *u_head, Post *p_head);