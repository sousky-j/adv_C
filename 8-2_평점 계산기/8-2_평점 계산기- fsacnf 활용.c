﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void main()
{
	char waste[20];											  // 첫 줄 버리는 용도
	float std_score[9] = {4.5, 4, 3.5, 3, 2.5, 2, 1.5, 1, 0}; // 성적별 점수 ex) "A+"==4.5
	float total_jumsoo = 0;									  // 각 과목별 점수의 총합
	int total_hakjum = 0;									  // 총 이수 학점
	char sub_name[7][20];									  // 과목 이름 저장
	int hakjum[7];											  // 이수 학점
	char sungjuk[7][10];									  // 문자 성적 ex) A+,B,F
	float score[7];											  // 문자 성적에 대응하는 숫자 성적
	float jumsoo[7];										  // 점수=학점 X 성적

	FILE *rfp = fopen("grade.txt", "r");
	fscanf(rfp, "%s\t\t%s\t%s\n", waste, waste, waste);
	for (int i = 0; i < 7; i++)
	{
		fscanf(rfp, "%s\t%d\t%s", sub_name[i], hakjum + i, sungjuk[i]);

		if (strcmp(sungjuk[i], "A+") == 0)
			score[i] = std_score[0];
		else if (strcmp(sungjuk[i], "A") == 0)
			score[i] = std_score[1];
		else if (strcmp(sungjuk[i], "B+") == 0)
			score[i] = std_score[2];
		else if (strcmp(sungjuk[i], "B0") == 0)
			score[i] = std_score[3];
		else if (strcmp(sungjuk[i], "C+") == 0)
			score[i] = std_score[4];
		else if (strcmp(sungjuk[i], "C0") == 0)
			score[i] = std_score[5];
		else if (strcmp(sungjuk[i], "D+") == 0)
			score[i] = std_score[6];
		else if (strcmp(sungjuk[i], "D0") == 0)
			score[i] = std_score[7];
		else if (strcmp(sungjuk[i], "F") == 0)
			score[i] = std_score[8];

		jumsoo[i] = hakjum[i] * score[i];
		total_hakjum += hakjum[i];
		total_jumsoo += jumsoo[i];
		printf("%s 과목의 점수: %.2f\n", sub_name[i], jumsoo[i]);
	}
	printf("총 평점: %.2f", total_jumsoo / total_hakjum);

	fclose(rfp);
}