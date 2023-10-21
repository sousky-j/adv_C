#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning (disable: 6031)

void main()
{
	char imsi[50];
	char* a[3];
	FILE* wfp;
	int i, j;
	int r=0;
	wfp = fopen("C:\\Users\\hojun\\OneDrive\\바탕 화면\\새 폴더\\output1.txt", "w");

	for (i = 0; i < 3; i++)
	{
		printf("%d 번째 문자열: ", i + 1);
		gets(imsi);
		r = strlen(imsi);
		a[i] = (char*)malloc(sizeof(char) * r + 1);
		for (j = 0; j < r; j++)
			a[i][r - j - 1] = imsi[j];
		a[i][r] = '\0';
	}
	for (i = 0; i < 3; i++)
	{
		printf("%d : %s\n", i + 1, a[i]);
		fputs(a[i],wfp);
		fputs("\n", wfp);
	}

	for(i=0;i<3;i++)
	free(a[i]);
	fclose(wfp);
}