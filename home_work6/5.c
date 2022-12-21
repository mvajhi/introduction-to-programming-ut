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

int main(void)
{
	int increase_len = 0;
	int counter = 0;
	scanf("%i", increase_len);

	Student *arr = NULL;

	while (True)
	{
		if (counter % increase_len == 0)
		{
			int len = sizeof(arr);
			arr = (Student) realloc(arr, len + increase_len);
		}
		
		char name[NAME_LEN];
		int sid;
		float gpa;

		scanf("%s %i %f", name, &sid, &gpa);

		if (!strcmp(name, "END"))
		{
			break;
		}

		strcmp(arr[counter].name, name);
		arr[counter].sid = sid;
		arr[counter].gpa = gpa;

		counter++;
	}

	return 0;
}
