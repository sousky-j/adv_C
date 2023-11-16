#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

void main()
{
	enum month { January = 1, February, March, April, May, June, July, August, September, October, November, December };

	int a;
	printf("월 입력: ");
	scanf("%d", &a);
	enum month mm = a;
	switch (mm)
	{
	case 1:		printf("%d월은 January입니다.", mm);		break;
	case 2:		printf("%d월은 February입니다.", mm);	break;
	case 3:		printf("%d월은 March입니다.", mm);		break;
	case 4:		printf("%d월은 April입니다.", mm);		break;
	case 5:		printf("%d월은 May입니다.", mm);			break;
	case 6:		printf("%d월은 June입니다.", mm);		break;
	case 7:		printf("%d월은 July입니다.", mm);		break;
	case 8:		printf("%d월은 August입니다.", mm);		break;
	case 9:		printf("%d월은 September입니다.", mm);	break;
	case 10:	printf("%d월은 October입니다.", mm);		break;
	case 11:	printf("%d월은 November입니다.", mm);	break;
	case 12:	printf("%d월은 December입니다.", mm);	break;
	default: printf("잘못된 월 수를 입력하였습니다.");		break;
	}
}