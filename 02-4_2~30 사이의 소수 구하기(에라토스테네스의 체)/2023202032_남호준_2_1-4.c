#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

void era(int a[29]);
void main()
{
	int a[29];
	for (int i = 0; i < 29; i++)
		a[i] = i + 2;
	era(a);
	for (int i = 0; i < 29; i++)
	{
		printf("%d ", a[i]);
		if (i % 10 == 0)
			printf("\n");
	}
}
void era(int a[29])
{
	for (int i = 2; i < 31; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				a[i - 2] = 0;
		}
	}
}