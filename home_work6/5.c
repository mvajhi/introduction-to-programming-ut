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
} Student;

void sorting(Student *unsorted, Student *sorted, int len);
void print_name(Student *input, int len);

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
			if (counter != 0)
			{
				len *= 2;
			}
			input = (Student *)realloc(input, len * sizeof(Student));
		}

		strcpy(input[counter].name, name);
		input[counter].sid = sid;
		input[counter].gpa = gpa;

		counter++;
	}

	Student *sorted = (Student *)malloc(len * sizeof(Student));

	sorting(input, sorted, len);

	print_name(sorted, len);

	return 0;
}

void sorting(Student *unsorted, Student *sorted, int len)
{
	memcpy(sorted, unsorted, len * sizeof(Student));
	for (int i = 0; i < len; i++)
	{
		int highest_gpa_stu_num = i;
		int j;
		for (j = i; j < len; j++)
		{
			if (sorted[highest_gpa_stu_num].gpa < sorted[j].gpa)
			{
				highest_gpa_stu_num = j;
			}
		}

		Student tmp = sorted[highest_gpa_stu_num];
		sorted[highest_gpa_stu_num] = sorted[i];
		sorted[i] = tmp;
	}
}

void print_name(Student *input, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%i. %s\n", i + 1, input[i].name);
	}
}
