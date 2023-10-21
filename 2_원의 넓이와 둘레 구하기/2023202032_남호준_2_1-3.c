#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

double pi = 3.141592;

void len(int r1, double *l);
void squ(int r2, double *s);

void main()
{
	int a;
	double lenth, squre;
	scanf("%d", &a);
	squ(a, &squre);
	printf("s=%.6f\n", squre);
	len(a, &lenth);
	printf("l=%.6f", lenth);
}

void len(int r1, double* l)
{
	*l = 2 * pi * r1;
}

void squ(int r2, double *s)
{
	*s = pi * r2 * r2;
}