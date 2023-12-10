#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#pragma warning(disable: 6031)

struct node {
	int data;

	struct node* next;
};

struct node* head;
struct node* tmp;
struct node* create_node(int input);

void main()
{
	head = NULL;
	int input=1;
	while(1)
	{
		if (input == 0) break;
		printf("ют╥б: ");
		scanf("%d", &input);
		struct node* new_node = create_node(input);
		if (head == NULL)
			head = new_node;
		else
		{
			tmp = head;
			while (1)
			{
				if (tmp == NULL)
				{
					tmp = new_node;
					break;
				}
				else
					tmp = tmp->next;
			}
		}
	}
	tmp = head;
	while (1)
	{
		if (tmp == NULL) break;
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

struct node* create_node(int input)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = input;
	new_node->next = NULL;

	return new_node;
}