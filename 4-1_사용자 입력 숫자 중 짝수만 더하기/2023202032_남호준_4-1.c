#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#pragma warning (disable: 6031)

void main()
{
	int* p;
	int i, hap = 0;
	int cnt;

	printf("입력할 개수: ");
	scanf("%d", &cnt);

	p = (int*)malloc(sizeof(int) * cnt);

	for (i = 0; i < cnt; i++)
	{
		printf("%d 번째 숫자: ", i + 1);
		scanf("%d", p + i);

		if(*(p+i)%2==0)
		hap += *(p + i);
	}

	printf("입력 숫자 짝수합: %d", hap);

	free(p);
}