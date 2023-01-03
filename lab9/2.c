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

icsp_std create()
{
	icsp_stu *new_stu = (icsp_stu *) malloc(sizeof(icsp_stu));
	new_stu->first_name = NULL;
	new_stu->last_name = NULL;
	new_stu->student_number = NULL;
	new_stu->mide_term_exam_score = -1;
	new_stu->final_exam_score = -1;
	new_stu->homework_score= -1;
	new_stu->next = NULL;

	return new_stu;
}

int is_end(icsp_std *stu)
{
	if (stu->next == NULL)
		return 1;
	else
		return 0;
}

