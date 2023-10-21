#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

void x_axis(int* y);
void y_axis(int* x);
void xy_axis(int* x, int* y);
void print_matrix(int x, int y);
void main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	print_matrix(x, y);
	x_axis(&y);
	print_matrix(x, y);
	y_axis(&x);
	print_matrix(x, y);
	xy_axis(&x, &y);
	print_matrix(x, y);
}
void x_axis(int* y) {*y *= -1;}
void y_axis(int* x) {*x *= -1;}
void xy_axis(int* x, int* y) {*y *= -1; *x *= -1;}

void print_matrix(int x, int y)
{
	switch (x) {case -2: x = 0; break;
	case -1: x = 1; break;
	case 1: x = 2;	break;
	case 2:	x = 3;	break;
	default: break;}

	switch (y) {case -2: y = 3; break;
	case -1: y = 2; break;
	case 1: y = 1;	break;
	case 2:	y = 0;	break;
	default:break;}
					  
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == x && i == y)
				printf("X");
			else
				printf("O");
		}
		printf("\n");
	}
	printf("\n");
}