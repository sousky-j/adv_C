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
	int r, k=0;

	printf("1 번째 문자열: ");
	gets(imsi);
	size = strlen(imsi);
	p[0] = (char*)malloc((sizeof(char) * size) + 1);
	k = (sizeof(char) * size) + 1;
	p[2] = (char*)malloc(k);
	strcpy(p[0], imsi);
	strcpy(p[2], imsi);

	printf("2 번째 문자열: ");
	gets(imsi);
	size = strlen(imsi);
	p[1] = (char*)malloc((sizeof(char) * size) + 1);
	k+= (sizeof(char) * size);
	strcpy(p[1], imsi);
	printf("%d\n", k);
	p[2] = (char*)realloc(p[2], 1 * k);
	strcat(p[2], imsi);


	for (i = 0; i <3; i++)
	{
		printf("%d: ", i + 1);
		printf("%s\n", p[i]);
	}

	for (i = 0; i < 3; i++)
		free(p[i]);
}