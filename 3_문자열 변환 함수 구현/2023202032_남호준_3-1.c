#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 6031)

int my_strcmp(char a1[8],char a2[8]);
void my_strcat(char a1[8], char a2[8], char a3[15]);
void  my_strcpy(char a1[8], char b[8]);
void main()
{
	char a1[8];
	char a2[8];
	char a3[15];
	char b[8];
	scanf("%s", a1);
	scanf("%s", a2);
	printf("\n\n%d\n", my_strcmp(a1, a2));
	my_strcat(a1, a2, a3);
	printf("%s\n", a3);
	my_strcpy(a1, b);
	printf("%s", b);
}

int my_strcmp(char a1[8], char a2[8])
{
	int k = strcmp(a1, a2);
	return k;
}

void my_strcat(char a1[8], char a2[8], char a3[15])
{
	a3[0] = '\0';
	strcat(a3, a1);
	strcat(a3, a2);
}

void  my_strcpy(char a1[8], char b[8])
{
	strcpy(b, a1);
}