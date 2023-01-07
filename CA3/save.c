#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers.h"

int save_post(Post *head)
{
    //save post name like
    FILE *post_output = fopen(POST_OUTPUT, "w");
    if (post_output == NULL)
    {
        printf("can't open post file.\nTry again.\n");
        return NO_MEMORY;
    }
    
    Post *cur = head;
    while (cur != NULL)
    {
        fprintf(post_output, "%s %s %i\n", cur->txt, cur->user_name, cur->like);
        cur = cur->next;
    }
    fclose(post_output);
    return SUCCESSFUL;
}


int save_user(User *head, Post *p_head)
{
    //save user name like
    FILE *user_output = fopen(USER_OUTPUT, "w");
    if (user_output == NULL)
    {
        printf("can't open user file.\nTry again.\n");
        return NO_MEMORY;
    }
    
    User *cur = head;
    while (cur != NULL)
    {
        int number_of_post = post_counter(p_head, cur->user_id);
        fprintf(user_output, "%s %s %i\n", cur->name, cur->password, number_of_post);
        cur = cur->next;
    }
    fclose(user_output);
    return SUCCESSFUL;
}

//this function export user and post to txt file
//if successful return SUCCESSFUL
int export_file (User *u_head, Post *p_head)
{
    int flag = save_user(u_head, p_head);
    if (flag != SUCCESSFUL)
    {
        return flag;
    }

    flag = save_post(p_head);
    if (flag != SUCCESSFUL)
    {
        return flag;
    }
    return SUCCESSFUL;
}