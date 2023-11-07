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

	for (i = 0; i < 2; i++)
	{
		printf("%d번째 문자열 입력: ", i + 1);
		scanf("%s", imsi);
		size = strlen(imsi);
		p[i] = (char*)malloc((sizeof(char) * size) + 1);
		strcpy(p[i], imsi);
		for (int j = 0; j < size; j++)
		{
			if (p[i][j] > 64 && p[i][j] < 91)
				p[i][j] += 32;
		}
	}
	my_strcmp(p);

	free(p);
}

void my_strcmp(char* p[2])
{
	if (strcmp(p[1], p[0]) == 0)
		printf("true");
	else
		printf("false");
}