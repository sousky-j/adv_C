#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

void swap1(int a1[2]);
void swap2(int* a2, int* a3);

void main()
{
	int a[2] = { 0 };

	scanf("%d %d", &a[0], &a[1]);
	printf("Before swap: %d %d\n", a[0], a[1]);
	swap1(a);
	printf("swap by index: %d %d\n\n\n", a[0], a[1]);

	scanf("%d %d", &a[0], &a[1]);
	printf("Before swap: %d %d\n", a[0], a[1]);
	swap2(&a[0], &a[1]);
	printf("swap by pointer: %d %d\n\n\n", a[0], a[1]);
}

void swap1(int a1[2])
{
	int tmp;
	tmp = a1[0];
	a1[0] = a1[1];
	a1[1] = tmp;
}

void swap2(int* a2, int* a3)
{
	int tmp;
	tmp = *a2;
	*a2 = *a3;
	*a3 = tmp;
}