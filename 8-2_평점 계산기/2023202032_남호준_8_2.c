#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void main()
{
	char imsi1[100], imsi2[100], imsi3[100];
	float score[9]; // ����
	char user[7][300];
	float user_jum[7];
	char cclass[7][300] = {0,	};	  // �����
	int grade[7] = {3, 3, 3, 3, 2, 3, 1}; // �̼� ����
	int len;
	float total_score = 0, total_grade = 0;
	FILE *rfp = fopen("grade.txt", "r");
	fscanf(rfp, "%s\t\t%s\t%s", imsi1, imsi2, imsi3);
	for (int i = 0; i < 7; i++)
	{
		fscanf(rfp, "%s\t%d\t%s", cclass[i], grade[i], user[i]);

		if (strcmp(user[i], "A+") == 0)
			user_jum[i] = score[0];
		else if (strcmp(user[i], "A") == 0)
			user_jum[i] = score[1];
		else if (strcmp(user[i], "B+") == 0)
			user_jum[i] = score[2];
		else if (strcmp(user[i], "B0") == 0)
			user_jum[i] = score[3];
		else if (strcmp(user[i], "C+") == 0)
			user_jum[i] = score[4];
		else if (strcmp(user[i], "C0") == 0)
			user_jum[i] = score[5];
		else if (strcmp(user[i], "D+") == 0)
			user_jum[i] = score[6];
		else if (strcmp(user[i], "D0") == 0)
			user_jum[i] = score[7];
		else if (strcmp(user[i], "F") == 0)
			user_jum[i] = score[8];
		total_score += grade[i] * user_jum[i];
		total_grade += grade[i];
		printf("%s�� ����: %0.2f\n", cclass[i], grade[i] * user_jum[i]);
	}
	printf("�� ����: %.2f", (total_score / total_grade));
	fclose(rfp);
}