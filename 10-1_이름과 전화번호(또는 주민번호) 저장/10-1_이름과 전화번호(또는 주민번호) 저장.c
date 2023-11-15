#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

void main()
{
	struct people
	{
		char name[7];
		union address
		{
			char number[15];
			char junhwa[13];
		}add;
	}p;

	printf("이름 -->");
	scanf("%s", p.name);
	printf("전화번호 또는 주민번호 -->");
	scanf("%s", p.add.number);

	printf("\n--구조체/공용체 혼합 활용---\n이름 ==>%s\n전화번호/주민번호 ==> %s\n", p.name, p.add.number);
}