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
		printf("��� ȣ��: "); scanf("%d", &cl);
		printf("���� �ο�: "); scanf("%d", &pp);
		reservation_hotel(pp, &cl, &log, a);
		if (log == 0) printf("���� �����մϴ�\n�����Ͻ� ���� �����ϰڽ��ϴ�\n%dȣ %d��\n", cl, pp);
		else if (log == 1)	printf("�ο��� �ʰ�(�Ǵ� ����)�Ǿ����ϴ�\n ������ ����մϴ�\n");
		else if (log == 2)	printf("�̹� ����� �����Դϴ�\n ������ ����մϴ�\n");
		else if (log == 3)	printf("�ش� ������ �������� �ʽ��ϴ�\n������ ����մϴ�\n");
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