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

icsp_std *create()
{
	icsp_std *new_std = (icsp_std *) malloc(sizeof(icsp_std));
	new_std->first_name = NULL;
	new_std->last_name = NULL;
	new_std->student_number = NULL;
	new_std->mid_term_exam_score = -1;
	new_std->final_exam_score = -1;
	new_std->homework_score= -1;
	new_std->next = NULL;

	return new_std;
}

int is_end(icsp_std *stu)
{
	if (stu->next == NULL)
		return 1;
	else
		return 0;
}

