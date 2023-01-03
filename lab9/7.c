#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct icsp_student icsp_std;
struct icsp_student {
	char* first_name;
	char* last_name;
	char* student_number;
	float mid_term_exam_score;
	float final_exam_score;
	float homework_score;
	struct icsp_student *next;
};

int print_reverse(icsp_std *head)
{
    int return_val = 1;
    if (head->next == NULL)
        return_val = 0;
    else
        print_reverse(head->next);
    printf("%s %s\n%s\n%f %f %f\n", head->first_name, head->last_name, head->student_number, head->mid_term_exam_score, head->final_exam_score, head->homework_score);
    return return_val;
}

int sort_by_id(icsp_std *head)
{
    if (head->next == NULL)
        return 0;
    icsp_std *cur2 = head->next;
    icsp_std *cur = head->next;
    icsp_std *pre = head;
    icsp_std *next = head->next->next;
    //bubble sort
    while (cur2 != NULL)
    {
        while (next != NULL)
        {
            if (atoi(cur->student_number) > atoi(next->student_number))
            {
                pre->next = next;
                cur->next = next->next;
                next->next = cur;
            }
            
        pre = pre->next;
        cur = cur->next;
        next = next->next;
        }
        cur2 = cur->next;
    }
    return 1;
}

int sort_by_name(icsp_std *head)
{
    if (head->next == NULL)
        return 0;
    icsp_std *cur2 = head->next;
    icsp_std *cur = head->next;
    icsp_std *pre = head;
    icsp_std *next = head->next->next;
    //bubble sort
    while (cur2 != NULL)
    {
        while (next != NULL)
        {
            int i = 0;
            for (int i = 0; i < strlen(cur->last_name) && i < strlen(next->last_name); i++)
            {
                if (tolower(cur->last_name[i]) > tolower(next->last_name[i]) || next->last_name[i] == '\0' && cur->last_name[i] != '\0')
                {
                    i = 1;
                    break;
                }    
            }
            if (i)
            {
                pre->next = next;
                cur->next = next->next;
                next->next = cur;
            }
            
        pre = pre->next;
        cur = cur->next;
        next = next->next;
        }
        cur2 = cur->next;
    }
    return 1;
}

int delete_all(icsp_std *head)
{
    if (head == NULL)
        return 0;
    delete_all(head->next);
    free(head->first_name);       
    free(head->last_name);       
    free(head->student_number);
    free(head);
    return 1;
}

int list_length(icsp_std *head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head == head->next;
    }
    return counter;
}