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

	printf("�̸� -->");
	scanf("%s", p.name);
	printf("��ȭ��ȣ �Ǵ� �ֹι�ȣ -->");
	scanf("%s", p.add.number);

	printf("\n--����ü/����ü ȥ�� Ȱ��---\n�̸� ==>%s\n��ȭ��ȣ/�ֹι�ȣ ==> %s\n", p.name, p.add.number);
}