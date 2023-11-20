#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void main()
{
	char **p;
	char imsi[100] = { 0, };
	int i, j, hap = 0;
	int cnt, size, len = 0;
	printf("입력할 문자열 수: ");
	scanf("%d", &cnt);

	p = (char**)malloc(sizeof(char*) * cnt);

	for (i = 0; i < cnt; i++)
	{
		printf("%d 번째 문자열: ", i + 1);
		scanf("%s", imsi);
		size = strlen(imsi);
		if (size > len)
			len = size;
		p[i] = (char*)malloc(sizeof(char) * (size + 1));
		strcpy(p[i], imsi);
	}
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < cnt; j++)
		{
			if (i < strlen(p[j]))
				printf("%c", p[j][i]);
		}
	}
	for (i = 0; i < cnt; i++)
		free(p[i]);
	free(p);
}