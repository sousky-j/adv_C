#define _CRT_SECURE_NO_WARNINGS // scanf ó��
#include <stdio.h>				//ǥ�� ����� �������
#include <string.h>				//���ڿ� �������
#include <malloc.h>				//���� �Ҵ� �������
#pragma warning(disable : 6031) // scanf ��� ���� ����
#pragma warning(disable : 6011) // ������ ��� ���� ����

struct node
{					   // ��ũ�� ����Ʈ ����ü
	char name[20];	   // �л� �̸� ���� �迭
	char sub[20];	   // ���� �̸� ���� �迭
	int data;		   // ���� ���� ����
	struct node *next; // next ������
};

struct node *head;		 // head ������ ����
struct node *tmp = NULL; // ��带 ����Ŵ, �� �������� ���� �뵵�� ���
struct node *pre = NULL; // tmp�� �Բ� ��带 ����Ŵ, �� �������� ���� �뵵�� ���
struct node *cur = NULL; // tmp,pre�� �Բ� ��带 ����Ŵ, �� �������� ���� �뵵�� ���

struct node *create_node(char *name, char *sub, int data); // ��� ���� �Լ�
void sort_sub();										   // ���Ͽ��� �Է� �� ���� ���� ���� �Լ�
void sort_stu();										   // �л��� ���� ���� �Լ�
void print_list(int a);									   // ��ũ�� ����Ʈ ��� �Լ�
void memory_manager();									   // �޸� �Ҵ� ���� �Լ�
void main()												   // ���� �Լ�
{
	sort_sub();		  // ���Ͽ��� ������ �о���� �� ���� ���� ���� �Լ� ȣ��
	print_list(1);	  // ���� ���� ����Ʈ ��� ȣ��
	sort_stu();		  // �л��� ���� ���� �Լ� ȣ��
	print_list(0);	  // �л��� ���� ����Ʈ ��� �Լ� ȣ��
	memory_manager(); // �޸� ���� �Լ� ȣ��
}

struct node *create_node(char *name, char *sub, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node)); // ��� ��ĭ �޸� �Ҵ�
	new_node->data = data;												// ������ ��� �����Ϳ� �ʱ�ȭ
	strcpy(new_node->name, name);										// �л� �̸��� ��� �����Ϳ� copy
	strcpy(new_node->sub, sub);											// ���� �̸��� ��� �����Ϳ� copy
	new_node->next = NULL;												// next �����͸� �ʱ�ȭ
	return new_node;													// ������ ��� ��ȯ
}
void sort_sub()
{
	char finame[20]; // ���� �Է� �л� �̸� �迭
	char fisub[20];	 // ���� �Է� ���� �̸� �迭
	int fidata;		 // ���� �Է� ���� ����
	char waste[20];	 // ù �� ������ ���� char�� �迭

	FILE *rfp = fopen("score.txt", "r"); // ���� ȣ��
	if (rfp == NULL)					 // ���� ȣ�� ���н� ���α׷� ���� ���ǹ�
	{
		printf("���� ȣ�� ����\n"); // �ȳ� ���� ���
		return;						// �Լ� ����
	}
	fscanf(rfp, "%s\t%s\t%s", waste, waste, waste); // ������ ù �ٿ� �ִ�  name	subject	score ������ �뵵

	while (1)
	{
		if (feof(rfp) != 0)
			break;													// ���� ���� �����ϸ� loop Ż��
		fscanf(rfp, "%s\t%s\t%d", finame, fisub, &fidata);			// ���Ͽ��� �����̸�, �л��̸�, ���� ������ �Է��� �޾ƿ�
		struct node *new_node = create_node(finame, fisub, fidata); // ������ ��� ����
		if (head == NULL)
			head = new_node; // ù ��带 head�� ����
		else
		{
			tmp = head; // tmp�� ù ��带 ����Ŵ
			pre = NULL; // tmp ���� ���
			while (1)
			{
				if (tmp == NULL) // ù ��� ���� ���ǹ�
				{
					tmp = new_node; // head�� ������ ��带 ����Ŵ
					break;			// ������ ��� ���� �� loop Ż��
				}

				if (strcmp(new_node->sub, tmp->sub) < 0) // ������ ��尡 �� ��庸�� �տ� ��ġ�� ��
				{
					new_node->next = tmp; // ������ ����� ���� ��带 �� ���� ����
					if (tmp == head)
						head = new_node; // �� ��尡 head�� head �����Ͱ� ������ ��带 ����Ŵ
					else
						pre->next = new_node; // �� ��尡 head�� �ƴϸ� �� ����� ���� ��尡 ������ ��带 ����Ŵ
					break;					  // ������ ��� ���� �� loop Ż��
				}
				else if (strcmp(new_node->sub, tmp->sub) == 0) // ������ ���� �� ��尡 ���� ������ ��
				{
					while (1)
					{
						if (tmp == NULL) // ������ ��尡 �������� �� ��
						{
							pre->next = new_node; // �� ����� ���� ����� ���� ��忡 ������ ��� ����
							break;				  // ������ ��� ���� �� loop Ż��
						}
						if (strcmp(new_node->sub, tmp->sub) != 0) // ���� ���� ��� �̵� �� �ٸ� �������� �Ѿ�� ��
						{
							new_node->next = tmp;
							pre->next = new_node;
							break; // ������ ��� ���� �� loop Ż��
						}
						if (strcmp(new_node->name, tmp->name) < 0) // ������ ��尡 �� ����� ���� �� ��
						{
							if (tmp == head)
							{
								new_node->next = tmp;
								head = new_node;
								break; // ������ ��� ���� �� loop Ż��
							}
							else
							{
								new_node->next = tmp;
								pre->next = new_node;
								break; // ������ ��� ���� �� loop Ż��
							}
						}
						else // ������ ��尡 �� ��庸�� ���� ��
						{
							if (pre != NULL)
								pre = pre->next; // tmp ���� ����� ��� �̵�
							else if (pre == NULL)
								pre = head;	 // pre�� tmp���� ��ĭ �ڿ� ���� ��
							tmp = tmp->next; // ���� ���� �̵�
						}
					}
					break; // ������ ��� ���� �� loop Ż��
				}
				else if (strcmp(new_node->sub, tmp->sub) > 0) // ������ ��尡 �� ����� �ڿ� ��ġ�� ��
				{
					if (tmp->next == NULL) // �� ����� ���� ��尡 ���� ��
					{
						tmp->next = new_node; // �� ����� ���� ��带 ������ ���� ����
						break;				  // ������ ��� ���� �� loop Ż��
					}
					else
					{
						if (pre != NULL)
							pre = pre->next; // tmp ���� ����� ��� �̵�
						else if (pre == NULL)
							pre = head;	 // pre�� tmp���� ��ĭ �ڿ� ���� ��
						tmp = tmp->next; // ���� ���� �̵�
					}
				}
			}
		}
	}

	fclose(rfp); // ���� ������ �޸� ����
}
void sort_stu()
{
	int flag = 0; // bubble sort �Ϸ� �� loop Ż�� ���� ����
	pre = NULL;	  // cur�� ���� ���

	while (1) // ���� ���� �� loop��
	{
		flag = 0;	// 0���� �ʱ�ȭ
		cur = head; // �� ��带 ù ���� ����

		while (1) // ���� ���� �� loop��
		{
			if (cur->next == NULL)
				break;									// �� ��尡 �������� �����ϸ� loop Ż��
			if (strcmp(cur->name, cur->next->name) > 0) // �� ���,�� ����� ���� ��尡 �ٲ� ��
			{
				//=======���� �˰���======//
				tmp = cur->next;	   // tmp�� �� ����� ���� ��带 ����Ŵ
				cur->next = tmp->next; // �� ��尡 �� ����� ������ ���� ��带 ����Ŵ
				tmp->next = cur;	   // �� ����� ���� ��尡 �� ��带 ����Ŵ
				//=========================//
				if (pre != NULL)
					pre->next = tmp; // ���� ��尡 ������ �� ����� ���� ��带 ���� �� ���� ����
				else
					head = tmp; // ���� ��尡 ������ head �����Ͱ� ���� ���� ������ �Ű��� ��带 ����Ŵ

				pre = tmp; // ���� ��带 �� ����� ������ ����
				flag++;	   // ���� �߻����� ���� flag ����
			}
			else
			{
				pre = cur;		 // �� ����� ���� ��带 �� ����� ��ġ�� �ű�
				cur = cur->next; // ���� ���� �̵�
			}
		}
		pre = NULL; // ���� ��� ������ �ʱ�ȭ
		if (flag == 0)
			break; // ������ ������ loop Ż��
	}
}
void print_list(int a)
{
	tmp = head;				 // tmp�� ó�� ��带 ����Ŵ
	char check[20] = {'\0'}; // �л��̳� ���� section�� �ٲ� ���� �˻��ϴ� �뵵
	float total = 0;		 // ��� ����� ���� ��ü ������ ��
	int gasu = 0;			 // ������ ����

	if (a == 1) // ���� ���� ���
	{
		FILE *wfp = fopen("record.txt", "w");
		printf("==============���� �л� ���� ���===============\n");		  // ���� ������� ǥ��
		fprintf(wfp, "==============���� �л� ���� ���===============\n"); // ���� ������� ǥ��
		strcpy(check, tmp->sub);											  // section�� �ٲ��� �˻��ϱ� ���� ó�� ����� ���� �̸��� check�� copy
		while (1)															  // ����Ʈ ��� loop ��
		{
			if (tmp == NULL) // ������ section�� ��� ��¿��� �߻��ϴ� ���� ó��
			{
				printf("\n%s�� ��� ����: %.2f\n\n", check, total / gasu);		 // ���� �̸�, ��� ���
				fprintf(wfp, "\n%s�� ��� ����: %.2f\n\n", check, total / gasu); // ���� �̸�, ��� ���� ���
				break;															 // ������ ��� �� loop Ż��
			}
			else
			{
				if (strcmp(check, tmp->sub) == 0) // ���� section�϶�
				{
					total += (float)tmp->data; // ������ ����
					gasu++;					   // ���� ���� ����
				}
				else // �ٸ� section�� ��
				{
					printf("\n%s�� ��� ����: %.2f\n\n", check, total / gasu);		 // ��� ���
					fprintf(wfp, "\n%s�� ��� ����: %.2f\n\n", check, total / gasu); // ��� ���� ���
					strcpy(check, tmp->sub);										 // ���� section ������ copy
					total = (float)tmp->data;										 // ��ü ������ ���� section���� ù ������ �ʱ�ȭ
					gasu = 1;														 // ���� ������ 1�� �ʱ�ȭ
				}
				printf("%-12s\t%-12s\t%-3d\n", tmp->sub, tmp->name, tmp->data);		  // ���� �̸�, �л� �̸�, ������ ���
				fprintf(wfp, "%-12s\t%-12s\t%-3d\n", tmp->sub, tmp->name, tmp->data); // ���� �̸�, �л� �̸�, ������ ���Ͽ� ���
				tmp = tmp->next;													  // ���� ���� �̵�
			}
		}
		printf("\n================================================\n\n\n");		  // ��� ���� ǥ��
		fprintf(wfp, "\n================================================\n\n\n"); // ��� ���� ǥ��
		fclose(wfp);
	}
	else if (a == 0) // �л��� ���� ���
	{
		FILE *wfp = fopen("record.txt", "a");
		printf("============�л��� ���� ���� ���===============\n");		// �л��� ������� ǥ��
		fprintf(wfp, "============�л��� ���� ���� ���===============\n"); // �л��� ������� ǥ��(����)
		strcpy(check, tmp->name);											// section�� �ٲ��� �˻��ϱ� ���� ó�� ����� �л� �̸��� check�� copy
		float ototal = 0;													// 60 �ʰ� ����� ����ϱ� ���� ��ü ������ ��
		int ogasu = 0;														// 60 �ʰ� ����� ������ ����
		while (1)															// ����Ʈ ��� loop ��
		{
			if (tmp == NULL) // ������ section�� ��� ��¿��� �߻��ϴ� ���� ó��
			{
				printf("\n%s�� ��� ����: %.2f\n\n", check, total / gasu);		 // �л� �̸�, ��� ���
				fprintf(wfp, "\n%s�� ��� ����: %.2f\n\n", check, total / gasu); // �л� �̸�, ��� ���� ���(����)
				if (ototal != 0)
				{
					printf("60�� ���� �������� ������ �л��� ��� ����: %.2f\n\n", ototal / ogasu);		  // 60�ʰ� ��� ���
					fprintf(wfp, "60�� ���� �������� ������ �л��� ��� ����: %.2f\n\n", ototal / ogasu); // 60�ʰ� ��� ���(����)
				}
				else
				{
					printf("�� �л��� 60���� �Ѵ� ������ ���׿�! �й��ϼ���! \n\n");	   // 60������ ������ ������ �� ����ó��
					fprintf(wfp, "�� �л��� 60���� �Ѵ� ������ ���׿�! �й��ϼ���! \n\n"); // 60������ ������ ������ �� ����ó��(����)
				}
				break; // ������ ��� �� loop Ż��
			}
			else
			{
				if (strcmp(check, tmp->name) == 0) // ���� section�϶�
				{
					total += (float)tmp->data; // ������ ����
					gasu++;					   // ���� ���� ����
					if (tmp->data > 60)		   // 60 �ʰ� ������ ��
					{
						ototal += (float)tmp->data; // 60 �ʰ� ������ ��ü ������ ����
						ogasu++;					// 60�ʰ� ���� ���� ����
					}
				}
				else // �ٸ� section�� ��
				{
					printf("\n%s�� ��� ����: %.2f\n\n", check, total / gasu);		 // ��� ���
					fprintf(wfp, "\n%s�� ��� ����: %.2f\n\n", check, total / gasu); // ��� ���
					if (ototal != 0)
					{
						printf("60�� ���� �������� ������ �л��� ��� ����: %.2f\n\n\n", ototal / ogasu);		// 60 �ʰ� ��� ���
						fprintf(wfp, "60�� ���� �������� ������ �л��� ��� ����: %.2f\n\n\n", ototal / ogasu); // 60 �ʰ� ��� ���
					}
					else
					{
						printf("�� �л��� 60���� �Ѵ� ������ ���׿�! �й��ϼ���!\n\n\n");		// 60 ������ ������ ������ �� ����ó��
						fprintf(wfp, "�� �л��� 60���� �Ѵ� ������ ���׿�! �й��ϼ���!\n\n\n"); // 60 ������ ������ ������ �� ����ó��
					}
					strcpy(check, tmp->name); // ���� section �л� �̸��� copy
					total = (float)tmp->data; // ���� section�� ù ������ �ʱ�ȭ
					gasu = 1;				  // ���� ������ 1�� �ʱ�ȭ
					if (tmp->data > 60)		  // ���� section�� ù ���� 60�ʰ��� ��
					{
						ototal = (float)tmp->data; // ��ü ������ ���� ����� ù ������ �ʱ�ȭ
						ogasu = 1;				   // ���� ������ 1�� �ʱ�ȭ
					}
					else // 60 ������ ��
					{
						ototal = 0; // ��ü ������ 0���� �ʱ�ȭ
						ogasu = 0;	// ���� ������ 0���� �ʱ�ȭ
					}
				}
				printf("%-12s\t%-12s\t%-3d\n", tmp->name, tmp->sub, tmp->data);		  // �л� �̸�, ���� �̸�, ������ ���
				fprintf(wfp, "%-12s\t%-12s\t%-3d\n", tmp->name, tmp->sub, tmp->data); // �л� �̸�, ���� �̸�, ������ ���� ���
				tmp = tmp->next;													  // ���� ���� �̵�
			}
		}
		printf("\n================================================\n\n\n");		  // ��� ���� ǥ��
		fprintf(wfp, "\n================================================\n\n\n"); // ��� ���� ǥ��
		fclose(wfp);
	}
}
void memory_manager()
{
	pre = head;			// ������ ��带 ����Ŵ
	tmp = pre->next;	// ������ ����� next ����Ŵ, �̵��� ������
	while (pre != NULL) // ������ ��带 ������ loop�� Ż����
	{
		free(pre); // ��� �޸� �Ҵ� ����
		pre = tmp; // ������ �����͸� ���� ��带 ����Ű�� ��
		if (tmp == NULL)
			break;		 // pre�� ������ ��带 ������ ��, tmp�� NULL�̸� loop�� Ż����
		tmp = tmp->next; // tmp�� ���� ��带 ����Ŵ
	}
}