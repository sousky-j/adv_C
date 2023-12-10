#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning (disable: 6031)
#pragma warning (disable: 6011)

struct node {//��ũ�� ����Ʈ ����ü
	char name[20];//�л� �̸� �迭
	char sub[20];//���� �̸� �迭
	int data;//���� ����
	struct node* down;//�� ������ (������ next ������)
	struct node* next;//�� ������ (������ next ������)
};
struct node* head;//head ������ ����

struct node* create_node(char* name, char* sub, int data);
void print_list();

void main()
{
	char finame[20];//���� �Է� �л� �̸� �迭
	char fisub[20];//���� �Է� ���� �̸� �迭
	int fidata;//���� �Է� ���� ����
	char waste[20];//ù �� ������ ���� char�� �迭
	int line = 0;//���� ����
	
	///////////////////////////////////////////////
	FILE* rfp = fopen("score.txt", "r");//���� ȣ��
	if (rfp == NULL)//���� ȣ�� ���н� ���α׷� ���� ���ǹ�
	{
		printf("���� ȣ�� ����\n");
		return;
	}
	fscanf(rfp, "%s\t%s\t%s", waste, waste, waste);//ù ���� name	subject	score ������ �뵵
	///////////////////////////////////////////////



	////////////////���Ͽ��� �Է¹޾� 2���� ��ũ�� ������ �����ϴ� �˰���////////
	while (1)
	{
		if (feof(rfp) != 0)
			break;
		fscanf(rfp, "%s\t%s\t%d", finame, fisub, &fidata);
		struct node* new_node = create_node(finame, fisub, fidata);
		if (head == NULL)
		{
			head = new_node;
			line++;
		}
		else
		{
			struct node* tmp = head;//Ž����: new_node�� ���� �� ��ġ�� Ž����
			int flag = 0;//��尡 ����Ǹ� Ž���� �����ϴ� flag
			while (1)
			{
				if (strcmp(new_node->sub, tmp->sub) == 0) break;//tmp�� ���� ������ ã���� �������⸦ ����
				if (tmp->down == NULL)//�̸��� ã�µ� ���� �̸��� ������ ���� �߰���
				{
					tmp->down = new_node;
					flag++;
					line++;
					break;
				}
				else//���� �̸� ������ ������
					tmp = tmp->down;
			}
			while (1)
			{
				if (flag == 1) break;//�̹� new_node�� ����Ǿ��ٸ� �� loop�� ���� ����
				if (tmp->next == NULL)//����Ʈ�� ���� �����ϸ� new_node�� ����
				{
					tmp->next = new_node;
					break;
				}
				else//
					tmp = tmp->next;
			}
		}
	}
	/////////////////////////////////////




	/////////////////�� ���� �� ũ�� ���ϴ� �˰���///////////////////
	int* list_size = (int*)calloc(line, sizeof(int));//�� ���� ���� ũ�⸦ ��� �迭
	for (int i = 0; i < line; i++)
	{
		struct node* cur = head;//Ž����: list_size�� �� ���� ���� ũ�⸦ �������� ���� ���
		for (int j = 0; j < i; j++)
			cur = cur->down;
		while (cur != NULL)
		{
			cur = cur->next;
			list_size[i]++;
		}
		printf("%d\n", list_size[i]);
	}
	/////////////////////////////////////////////////////////////////


	
	/////////////���� �˰���///////////////////
	for (int i = 0; i < line; i++)
	{
		struct node* tmp = head;//Ž���ڿ� �ٲ� ���
		struct node* cur = NULL;//tmp�� ���� ���
		struct node* sear = head;//Ž����: ������ �� ��带 Ž��
		for (int p = 0; p < i; p++)
		{
			tmp = tmp->next;
		}
		if (tmp != head)
		{
			cur = head;
		}
		for (int j = i + 1; j < line; j++)
		{

		}
	}
	///////////////////////////////////////////


	print_list();


	fclose(rfp);
}

struct node* create_node(char* name, char* sub, int data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	strcpy(new_node->name, name);
	strcpy(new_node->sub, sub);
	new_node->next = NULL;
	new_node->down = NULL;
	return new_node;
}

void print_list()
{
	struct node* tmp = head;
	int l = 0;
	while(1)
	{
		tmp = head;
		for (int j = 0; j < l; j++)
			tmp = tmp->down;

		if (tmp == NULL) break;

		while (1)
		{
			if (tmp == NULL) break;
			printf("%-12s\t%-12s\t%3d\n", tmp->sub, tmp->name, tmp->data);
			tmp = tmp->next;
		}
		l++;
	}
}