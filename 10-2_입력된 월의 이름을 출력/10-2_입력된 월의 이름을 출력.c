#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

void main()
{
	enum month { January = 1, February, March, April, May, June, July, August, September, October, November, December };

	int a;
	printf("�� �Է�: ");
	scanf("%d", &a);
	enum month mm = a;
	switch (mm)
	{
	case 1:		printf("%d���� January�Դϴ�.", mm);		break;
	case 2:		printf("%d���� February�Դϴ�.", mm);	break;
	case 3:		printf("%d���� March�Դϴ�.", mm);		break;
	case 4:		printf("%d���� April�Դϴ�.", mm);		break;
	case 5:		printf("%d���� May�Դϴ�.", mm);			break;
	case 6:		printf("%d���� June�Դϴ�.", mm);		break;
	case 7:		printf("%d���� July�Դϴ�.", mm);		break;
	case 8:		printf("%d���� August�Դϴ�.", mm);		break;
	case 9:		printf("%d���� September�Դϴ�.", mm);	break;
	case 10:	printf("%d���� October�Դϴ�.", mm);		break;
	case 11:	printf("%d���� November�Դϴ�.", mm);	break;
	case 12:	printf("%d���� December�Դϴ�.", mm);	break;
	default: printf("�߸��� �� ���� �Է��Ͽ����ϴ�.");		break;
	}
}