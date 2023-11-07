#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void main()
{
	int a;
	printf("����� �� ���� �Է��ϼ���: ");
	scanf("%d", &a);
	FILE *wfp = fopen("7_dan.txt", "w");
	for (int i = 1; i <= 9; i++)
		fprintf(wfp, "%d X %d = %d\n", a, i, a * i);

	fclose(wfp);
}