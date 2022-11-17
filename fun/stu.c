#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0

#define MAX_NAME_LENGHT 20
#define MAX_COURSE 10

typedef struct course
{
	char name[MAX_NAME_LENGHT];
	int value;
	float grade;
}
course;

typedef struct stu
{
	char name[MAX_NAME_LENGHT];
	float GPA;
	int sum_course_val;
	struct course courses[MAX_COURSE];
	struct stu *next;
}
stu;


int menu();
int add_stu(struct stu *list);

int main(void)
{
	int selection = 0;
	struct stu *list = NULL;

	while(True)
	{
		int selection = menu();

		switch (selection)
		{
			case 1:
				add_stu(list);
				break;
			case 2:
				//remove_stu();
				break;
			case 3:
				//list_stu();
				break;
			case 4:
				//list_probation_stu();
				break;
			case 5:
				//list_exelent_stu();
				break;
			case 0:
				//quit();
				return 0;
		}

	}

	return -1;
}

int menu(void)
{
	printf("\n\n\n");
	printf("1. <<\tEnter a student\t>>\n");
	printf("2. <<\tDelete a student>>\n");
	printf("3. <<\tList students\t>>\n");
	printf("4. <<\tList probation\t>>\n");
	printf("5. <<\tList exelent\t>>\n");
	printf("\n\n0. <<\t    Quit\t>>\n\n");

	int input = 0;
	printf("Please enter your choice :");
	scanf("%i", &input);
	/*TODO Check input*/
	return input;
}

int add_stu(struct stu *list)
{
	struct stu *new_stu = malloc(sizeof(stu));
	int course_number = 0;

	printf("\n\n\n\n\n");
	printf("Enter student name: ");
	scanf("%s", new_stu->name);
	
	printf("Enter number of student course: ");
	scanf("%i", &course_number);

	for (int i = 0; i < course_number; i++)
	{
		printf("\n\tcourse %i:", i + 1);

		printf("\n\t\tname: ");
		scanf("%s", new_stu->courses[i].name);

		printf("\t\tvalue: ");
		scanf("%i", &new_stu->courses[i].value);
		new_stu->sum_course_val += new_stu->courses[i].value;

		printf("\t\tgrade: ");
		scanf("%f", &new_stu->courses[i].grade);
		new_stu->GPA += (new_stu->courses[i].grade / course_number);
	}
}
