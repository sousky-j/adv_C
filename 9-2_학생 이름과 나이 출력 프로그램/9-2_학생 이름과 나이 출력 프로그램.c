#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable : 6031)

void main()
{
	int person;
	struct student
	{
		char name[10];
		int nai;
	};

	struct student* p;
	printf("�Է��� �л� ��: ");
	scanf("%d", &person);
	p = (struct student*)malloc(sizeof(struct student) * person);
	for (int i = 0; i < person; i++)
	{
		printf("�̸��� ���� �Է�: ");
		scanf("%s %d", (p + i)->name, &(p + i)->nai);
	}
	printf("--�л� ���--\n");
	for (int i = 0; i < person; i++)
	{
		printf("�̸�:%s,����:%d\n", (p + i)->name, (p + i)->nai);
	}

	free(p);
}