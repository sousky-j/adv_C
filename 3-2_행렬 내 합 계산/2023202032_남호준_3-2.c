#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 6031)

void calcul_matrix(int a[4][8]);

void main()
{
	int a[4][8];
	for (int i = 0; i < 8; i++)
		scanf("%d", &a[0][i]);

	calcul_matrix(a);

	printf("%d", a[3][0]);
}

void calcul_matrix(int a[4][8])
{
	for (int i = 0; i < 4; i++)
		*(*(a + 1) + 2 * i) = *(*(a + 0) + 2 * i) + *(*(a + 0) + (2 * i + 1));

	for (int i = 0; i < 2; i++)
		*(*(a + 2) + 4 * i) = *(*(a + 1) + 4 * i) + *(*(a + 1) + (4 * i + 2));

	*(*(a + 3) + 0) = *(*(a + 2) + 0) + *(*(a + 2) + 4);
}