#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning (disable: 6031)

void main()
{
	char* p[3];
	char imsi[100];
	int i, size;
	int r;
	for (i = 0; i < 3; i++)
	{
		printf("%d 번째 문자열: ", i + 1);
		gets(imsi);
		size = strlen(imsi);

		p[i] = (char*)malloc((sizeof(char) * size) + 1);

		strcpy(p[i], imsi);
	}

	printf("\n ㅡ 입력과 반대로 출력(포인터) ㅡ\n");
	for (i = 2; i >= 0; i--)
	{
		printf("%d: ", i + 1);
		r = strlen(p[i]);
		for (r; r >= 0; r--)
			printf("%c", p[i][r-1]);
		printf("\n");
	}

	for (i = 0; i < 3; i++)
		free(p[i]);
}