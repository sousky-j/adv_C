#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 6031)

void sort_ascending(int a[100]);
void sort_descending(int a[100]);

void main()
{
	int a[100];
	for (int i = 0; i < 100; i++)
		a[i] = 100 - i;

	char sun[2][12] = {"오름차순","내림차순"};
	char b[10];
	scanf("%s", &b);

	if (strcmp(b, sun[0]) == 0)
	{
		sort_ascending(a);
	}
	else if (strcmp(b, sun[1]) == 0)
	{
		sort_descending(a);
	}

	for (int i = 0; i < 100; i++)
		printf("%d ", a[i]);
}

void sort_ascending(int a[100])
{
	for (int i = 0; i < 100; i++)
	{
		int tmp = 0;
		for (int j = 0; j < 100; j++)
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

void sort_descending(int a[100])
{
	for (int i = 0; i < 100; i++)
	{
		int tmp = 0;
		for (int j = 0; j < 100; j++)
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