#include <stdio.h>
#include <stdlib.h>

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

int remove(int id, icsp_std *head)
{
	icsp_std *cur = head;
	icsp_std *pre = head;
	while (cur != NULL){
		if (cur->student_number == id)
        {
            pre->next = cur->next;
            free(cur->first_name);       
            free(cur->last_name);       
            free(cur->student_number);
            free(cur);       
			return 1;
        }
        pre = cur;
        cur = cur->next;
    }
	return 0;
}

