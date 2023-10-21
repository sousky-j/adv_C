#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 6031)

void sort_ascending(char a[100], int r);
void sort_descending(char a[100], int r);
void func_print(char a[100]);

void main()
{
	char a[100];
	int r;
	scanf("%s", a);
	r = strlen(a);
	a[r] = '\0';

	char sun[2][12] = { "오름차순","내림차순" };
	char b[10];
	scanf("%s", &b);

	if (strcmp(b, sun[0]) == 0)
	{
		sort_ascending(a,r);
	}
	else if (strcmp(b, sun[1]) == 0)
	{
		sort_descending(a,r);
	}
	func_print(a);
	
}

void func_print(char a[100])
{
	puts(a);
}
void sort_ascending(char a[100],int r)
{
	for (int i = 0; i < r; i++)
	{
		int tmp = 0;
		for (int j = 0; j < r; j++)
		{
			if (a[j] > a[i])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

	}
}

void sort_descending(char a[100], int r)
{
	for (int i = 0; i < r; i++)
	{
		int tmp = 0;
		for (int j = 0; j < r; j++)
		{
			if (a[j] < a[i])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

	}
}