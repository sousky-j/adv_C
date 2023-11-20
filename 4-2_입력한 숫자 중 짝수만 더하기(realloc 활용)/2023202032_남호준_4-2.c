#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#pragma warning (disable: 6031)

void main()
{
	int* p;
	int i, hap = 0, cnt = 0;
	int data;

	p = (int*)malloc(sizeof(int) * 1);
	printf("1번째 숫자: ");
	scanf("%d", p);
	cnt++;

	for (i = 2; ; i++)
	{
		if (p == 0)
			break;

		printf("%dth number:", i);
		scanf("%d", &data);

		if (data != 0)
			p = (int*)realloc(p, sizeof(int) * i);
		else
			break;
		p[i - 1] = data;
		cnt++;
	}
	for (i = 0; i < cnt; i++)
	{
		if((p[i]%2)==0)
			hap += p[i];
	}
	printf("total : %d", hap);
	free(p);
}