#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable : 6031)

void main()
{
	FILE* wfp = fopen("average_strudent.txt", "w");

	struct student
	{
		char name[10];
		int kor;
		int eng;
		float stu_avg;
	};

	struct jum
	{
		float kor_avg;
		float eng_avg;
		float tot_avg;
	}j;

	int person;
	printf("�л� �����: ");
	scanf("%d", &person);

	struct student* p= (struct student*)malloc(sizeof(struct student) * person);

	j.kor_avg = 0;
	j.eng_avg = 0;
	for (int i = 0; i < person; i++)
	{
		printf("�̸� �Է�: ");
		scanf("%s", (p+i)->name);
		printf("���� ���� �Է�:");
		scanf("%d", &(p + i)->kor);
		printf("���� ���� �Է�:");
		scanf("%d", &(p + i)->eng);

		p[i].stu_avg = ((p + i)->kor + (p + i)->eng) / 2;
		j.kor_avg += p[i].kor / person;
		j.eng_avg += p[i].eng / person;

		printf("�̸�: %s\t����: %d\t����: %d\n", (p + i)->name, (p + i)->kor, (p + i)->eng);
		fprintf(wfp, "%s�� ��� ����: %.2f\n", (p + i)->name, (p + i)->stu_avg);
	}
	j.tot_avg = (j.kor_avg + j.eng_avg) / 2;
	fprintf(wfp, "���� ������ ��� ����: %.2f\n", j.kor_avg);
	fprintf(wfp, "���� ������ ��� ����: %.2f\n", j.eng_avg);
	fprintf(wfp, "�� ��� ����: %.2f", j.tot_avg);

	fclose(wfp);
}