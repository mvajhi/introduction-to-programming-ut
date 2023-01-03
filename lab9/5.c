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

icsp_std *find(int id, icsp_std *head)
{
	icsp_std *cur = head;
	while (cur != NULL)
	{
		if (cur->student_number == id)
			return cur;
		cur = cur->next;
	}
	printf("NOT FOUND\n");
	return NULL;
}

