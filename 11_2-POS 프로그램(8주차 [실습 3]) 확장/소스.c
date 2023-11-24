#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

struct menu
{
	int id;//order���� ����, �޴�����Ʈ���� ���̵�
	char name[50];
	float price;
};

struct cafe
{
	struct menu* drink, * dessert;
	struct menu* order_dri, * order_des;
};
struct cafe ca;

void Initial_menulist();
void drink_count();
void dessert_count();
void print_receipt();

void main()
{
	ca.drink = (struct menu*)malloc(sizeof(struct menu) * 5);
	ca.dessert = (struct menu*)malloc(sizeof(struct menu) * 5);
	ca.order_dri = (struct menu*)malloc(sizeof(struct menu) * 5);
	ca.order_des = (struct menu*)malloc(sizeof(struct menu) * 5);
	Initial_menulist();

	while (1)
	{
		printf("1. ���� �ֹ��ϱ�\n2. ����Ʈ �ֹ��ϱ�\n0. ����\t\t::\t");
		int ch;
		scanf("%d", &ch);
		if (ch == 1) drink_count();
		else if (ch == 2) dessert_count();
		else if (ch == 0) break;
		else { printf("�ֹ� �޴��� �߸� �Է��Ͽ����ϴ�.\n"); continue; }
	}

}

void Initial_menulist()
{
	FILE* rfp1 = fopen("drink.txt", "r");
	FILE* rfp2 = fopen("dessert.txt", "r");

	for (int i = 0; i < 5; i++)
	{
		ca.drink->id = i + 1;
		ca.dessert->id = i + 1;
		fscanf(rfp1, "%s %f", ca.drink->name, &ca.drink->price);
		fscanf(rfp2, "%s %f", ca.dessert->name, &ca.dessert->price);
		strcpy(ca.order_des->name, ca.dessert->name);
		strcpy(ca.order_dri->name, ca.drink->name);
	}
	fclose(rfp1);
	fclose(rfp2);
}

void drink_count()
{
	int menu;
	printf("�ֹ��Ͻ� ���Ḧ �����ϼ���\n\n\n");
	printf("drink menues\n");
	for (int i = 0; i < 5; i++)
		printf("[%d] %20s %.2f\n", ca.drink->id, ca.drink->name, ca.drink->price);
	scanf("%d", &menu);
	ca.order_dri[menu].id++;
}

void dessert_count()
{

}