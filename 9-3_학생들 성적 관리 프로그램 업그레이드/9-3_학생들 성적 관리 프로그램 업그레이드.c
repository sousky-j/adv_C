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
	printf("학생 몇명임: ");
	scanf("%d", &person);

	struct student* p= (struct student*)malloc(sizeof(struct student) * person);

	j.kor_avg = 0;
	j.eng_avg = 0;
	for (int i = 0; i < person; i++)
	{
		printf("이름 입력: ");
		scanf("%s", (p+i)->name);
		printf("국어 점수 입력:");
		scanf("%d", &(p + i)->kor);
		printf("영어 점수 입력:");
		scanf("%d", &(p + i)->eng);

		p[i].stu_avg = ((p + i)->kor + (p + i)->eng) / 2;
		j.kor_avg += p[i].kor / person;
		j.eng_avg += p[i].eng / person;

		printf("이름: %s\t국어: %d\t영어: %d\n", (p + i)->name, (p + i)->kor, (p + i)->eng);
		fprintf(wfp, "%s의 평균 점수: %.2f\n", (p + i)->name, (p + i)->stu_avg);
	}
	j.tot_avg = (j.kor_avg + j.eng_avg) / 2;
	fprintf(wfp, "국어 과목의 평균 점수: %.2f\n", j.kor_avg);
	fprintf(wfp, "영어 과목의 평균 점수: %.2f\n", j.eng_avg);
	fprintf(wfp, "총 평균 점수: %.2f", j.tot_avg);

	fclose(wfp);
}