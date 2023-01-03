int posting(User *logged, Post **head);
int search_post(Post *head, Post **target, char *username, int post_id, int mod);
int like(Post *head, User *logged);
int time_line(Post *head);
int delete_post(Post **head, User *logged);
int search_liked_user(int *head, int like, int id, int **cur);