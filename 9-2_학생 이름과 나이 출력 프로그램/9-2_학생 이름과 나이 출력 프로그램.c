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
	printf("입력할 학생 수: ");
	scanf("%d", &person);
	p = (struct student*)malloc(sizeof(struct student) * person);
	for (int i = 0; i < person; i++)
	{
		printf("이름과 나이 입력: ");
		scanf("%s %d", (p + i)->name, &(p + i)->nai);
	}
	printf("--학생 명단--\n");
	for (int i = 0; i < person; i++)
	{
		printf("이름:%s,나이:%d\n", (p + i)->name, (p + i)->nai);
	}

	free(p);
}