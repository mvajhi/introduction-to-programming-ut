#include <stdio.h>
#include <stdlib.h>

#define ZERO 0
#define ONE 1
#define true 1
#define false 0

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

int add_to_i(icsp_std* head_of_list, icsp_std* new_std, int i) {
	if (head_of_list == NULL)
		return ZERO;
	icsp_std* current_std = head_of_list->next;
	if (current_std == NULL && i == ZERO) {
		head_of_list->next = new_std;
		new_std->next = NULL;
		return ONE;
	}
	else if(current_std == NULL && i != ZERO){
		return ZERO;
	}
	int counter = ZERO;
	while (true){
		if (counter == i) {
			new_std->next = current_std->next;
			current_std->next = new_std;
			return ONE;
		}
		counter++;
		if (current_std->next == NULL && counter == i) {
			current_std->next = new_std;
			new_std->next = NULL;
			return ONE;
		}
		if (current_std->next == NULL && counter < i) {
			return ZERO;
		}
		current_std = current_std->next;
	}
}
