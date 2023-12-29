#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable : 6031)

void swap2(int *a2, int *b2);
void swap1(int a1, int b1);
void main()
{
	int a, b;
	a = 10, b = 20;
	printf("Before swap, A: %d, B: %d \n\n", a, b);
	swap1(a, b);
	printf("After value swap(in main), A: %d, B: %d\n\n\n", a, b);
	swap2(&a, &b);
	printf("Reference value swap(in main), A: %d, B: %d\n", a, b);
}

void swap1(int a1, int b1)
{
	int tmp;
	tmp = a1;
	a1 = b1;
	b1 = tmp;
	printf("After value swap(in function), A: %d, B: %d\n", a1, b1);
}

void swap2(int *a2, int *b2)
{
	int tmp;
	tmp = *a2;
	*a2 = *b2;
	*b2 = tmp;
	printf("After value swap(in function), A: %d, B: %d\n", *a2, *b2);
}