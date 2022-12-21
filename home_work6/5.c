#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define True 1
#define False 0

typedef struct Student
{
	char name[NAME_LEN];
	int sid;
	float gpa;
}
Student;

void sorting(Student *unsorted, Student *sorted);
void print_name(Student *input);

int main(void)
{
	int first_len = 0;
	int counter = 0;
	scanf("%i", &first_len);
	int len = first_len;

	Student *input = NULL;

	while (True)
	{
		char name[NAME_LEN];
		int sid;
		float gpa;

		scanf("%s %i %f", name, &sid, &gpa);

		if (sid == 0)
		{
			break;
		}

		if (counter == len || counter == 0)
		{
			input = (Student*) realloc(input, len);
			len *= 2;
		}

		strcmp(input[counter].name, name);
		input[counter].sid = sid;
		input[counter].gpa = gpa;

		counter++;
	}

	Student *sorted = (Student*) malloc(sizeof(input));

	sorting(input, sorted);

	print_name(sorted);

	return 0;
}

void sorting(Student *unsorted, Student *sorted)
{
	memcpy(sorted, unsorted, sizeof(unsorted));
	int len = sizeof(unsorted) / sizeof(Student);
	for (int i = 0; i < len; i++)
	{
		Student highest_gpa_stu = sorted[i];
		int j;
		for (j = i; j < len; j++)
		{
			if (highest_gpa_stu.gpa < sorted[j].gpa)
			{
				highest_gpa_stu = sorted[j];
			}
		}
		
		sorted[j] = unsorted[i];
		sorted[i] = highest_gpa_stu;
	}
}


void print_name(Student *input)
{
	int len = sizeof(input) / sizeof(Student);

	for (int i = 0; i < len; i++)
	{
		printf("%i. %s\n", i + 1, input[i].name);
	}
}
