#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning (disable: 6031)

void main()
{
	char* p[2];
	char imsi[100];
	int i, size;

	printf("문자열 입력: ");
	gets(imsi);
	size = strlen(imsi);
	for (i = 0; i < 2; i++)
	{
		p[i] = (char*)malloc((sizeof(char) * size) + 1);
		strcpy(p[i], imsi);
	}
	for (int j = 0; j < size; j++)
	{
		if (p[0][j] >= 97 && p[0][j] <= 122)
			p[0][j] -= 32;
		if (p[1][j] >= 65 && p[1][j] <= 90)
			p[1][j] += 32;
	}

	puts(p[0]);
	puts(p[1]);

	free(p);
}