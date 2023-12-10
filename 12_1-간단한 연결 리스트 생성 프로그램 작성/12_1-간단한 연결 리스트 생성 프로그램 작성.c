#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning (disable: 6031)
#pragma warning (disable: 6011)

struct node {
	int data;

	struct node* next;
};

struct node* create_node(int data);
void insert_node(struct node** head, int data);
void delete_node(struct node* head, int target);
void print_list(struct node* head);

void main()
{	
	int input;
	struct node* a = NULL;
	for (int i = 0; i < 5; i++)
	{
		insert_node(&a, 2 * i + 1);
	}
	scanf("%d", &input);
	while (input != 0)
	{
		insert_node(&a, input);
		scanf("%d", &input);
	}
	print_list(a);
}

struct node* create_node(int data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;	
	new_node->next = NULL;
	return new_node;
}

void insert_node(struct node** head, int data) {
	struct node* new_node = create_node(data);
	if (*head == NULL) { *head = new_node; }
	else {
		struct node* temp = *head;
		while (temp->next != NULL) { temp = temp->next; }
		temp->next = new_node;
	}
}

void delete_node(struct node* head, int target)
{

	struct node* current = head;
	struct node* prev = NULL;

	if (current != NULL && current->data == target) {
		head = current->next;
		free(current);
		return;
	}
	while (current != NULL && current->data != target) {
		prev = current;
		current = current->next;
	}
	if (current == NULL) {
		printf("삭제할 노드가 없습니다.\n");
		return;
	}
	prev->next = current->next;
	free(current);
}

void print_list(struct node* head) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}