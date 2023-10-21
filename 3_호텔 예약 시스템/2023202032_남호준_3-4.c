#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning (disable: 6031)

void reservation_hotel(int pp, int* cl, int* log, int a[2][5]);
int vip_check(int* pp, int* cl, int a[2][5]);
int normal_check(int* pp, int* cl, int a[2][5]);

void main() {
	int pp, cl, log=0;
	int a[2][5] = { 0 };
	a[1][3] = 2;
	a[1][4] = 2;
	for (int i = 0; i < 5; i++) {
		printf("희망 호수: "); scanf("%d", &cl);
		printf("예약 인원: "); scanf("%d", &pp);
		reservation_hotel(pp, &cl, &log, a);
		if (log == 0) printf("예약 가능합니다\n말씀하신 방을 예약하겠습니다\n%d호 %d명\n", cl, pp);
		else if (log == 1)	printf("인원이 초과(또는 오류)되었습니다\n 예약을 취소합니다\n");
		else if (log == 2)	printf("이미 예약된 객실입니다\n 예약을 취소합니다\n");
		else if (log == 3)	printf("해당 객실은 존재하지 않습니다\n예약을 취소합니다\n");
	}
}
void reservation_hotel(int pp, int* cl, int* log, int a[2][5])
{
	int l = pp, p = *cl;
	if (*cl > 300)
		*log = vip_check(&l, &p, a);
	else if (*cl < 299)
		*log = normal_check(&l, &p, a);

	if (*log == 1 || *log == 2 || *log == 3)
		*cl = 0;
}

int vip_check(int* pp, int* cl, int a[2][5])
{
	int k=0;
	*cl -= 301;
	if (*pp > 4 || *pp < 1) k = 1;
	else
	{
		if (a[1][*cl] == 0) { k = 0; a[1][*cl] = 1; }
		else if (a[1][*cl] == 1) k = 2;
		else if (a[1][*cl] == 2) k = 3;
	}
	*cl += 301;
	return k;
}

int normal_check(int* pp, int* cl, int a[2][5])
{
	int k=0;
	*cl -= 201;
	if (*pp > 2 || *pp < 1)
		k = 1;
	else
	{
		if (a[0][*cl] == 0)
		{
			k = 0;
			a[0][*cl] = 1;
		}
		else if (a[0][*cl] == 1)
			k = 2;
	}
	*cl += 201;
	return k;
}