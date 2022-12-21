#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
	int x;
	int y;
}
Point;

typedef struct Node
{
	Point Point;
	struct Node *next;
}
Node;

Node *convert(Point *arr[1000], int len)
{
	if (len == 0)
	{
		return NULL;
	}

	Node *head = (Node*) malloc(sizeof(Node));
	head->Point = *arr[0];

	Node *cur = head;

	for (int i = 1; i < len; i++)
	{
		Node *new = (Node*) malloc(sizeof(Node));
		new->Point = *arr[i];

		cur->next = new;
		cur = new;
	}

	return head;
}

void print_distance(Node *head)
{
	Node *cur = head;

	while (cur->next != NULL)
	{
		int x = cur->Point.x - cur->next->Point.x;
		int y = cur->Point.y - cur->next->Point.y;
		float len = sqrt(pow(x, 2) + pow(y, 2) * 1.0);
		
		printf("%f\n", len);

		cur = cur->next;
	}
}

int main(void)
{
	Point *arr[1000];
	int len = 1;
	while (1)
	{
		int x, y;
		scanf("%i %i", &x, &y);
		
		if (x == 82)
		{
			break;
		}

		Point *new = (Point*) malloc(sizeof(Point));
		new->x = x;
		new->y = y;

		arr[len - 1] = new;

		len++;
	}

	Node *head = convert(arr, len);
	print_distance(head);

	return 0;
}
