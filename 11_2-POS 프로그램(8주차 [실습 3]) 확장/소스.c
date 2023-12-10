#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

struct menu
{
	int id;//메뉴리스트에선 아이디, order에선 개수
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
		printf("1. 음료 주문하기\n2. 디저트 주문하기\n0. 종료\t\t::\t");
		int ch;
		scanf("%d", &ch);
		if (ch == 1) drink_count();
		else if (ch == 2) dessert_count();
		else if (ch == 0) break;
		else { printf("주문 메뉴를 잘못 입력하였습니다.\n"); continue; }
	}

}

void Initial_menulist()
{
	FILE* rfp1 = fopen("drink.txt", "r");
	FILE* rfp2 = fopen("dessert.txt", "r");

	for (int i = 0; i < 5; i++)
	{
		ca.drink[i].id = i + 1;
		ca.dessert[i].id = i + 1;
		fscanf(rfp1, "%s %f", ca.drink[i].name, &ca.drink[i].price);
		fscanf(rfp2, "%s %f", ca.dessert[i].name, &ca.dessert[i].price);
		strcpy(ca.order_des[i].name, ca.dessert[i].name);
		strcpy(ca.order_dri[i].name, ca.drink[i].name);
		ca.order_dri[i].price = ca.drink[i].price;
		ca.order_des[i].price = ca.dessert[i].price;
	}
	fclose(rfp1);
	fclose(rfp2);
}

void drink_count()
{
	int menu;
	printf("주문하실 음료를 선택하세요\n\n\n");
	printf("drink menues\n");
	for (int i = 0; i < 5; i++)
		printf("[%d] %-20s %.2f\n", ca.drink[i].id, ca.drink[i].name, ca.drink[i].price);
	scanf("%d", &menu);
	if (menu >= 1 && menu <= 5)
	{
		ca.order_dri[menu-1].id++;
		printf("%s를 주문하였습니다.\n\n", ca.drink[menu-1].name);
	}
	else printf("없는 주문 번호입니다. 돌아갑니다\n");
}

void dessert_count()
{
	int menu;
	printf("주문하실 음료를 선택하세요\n\n\n");
	printf("dessert menues\n");
	for (int i = 0; i < 5; i++)
		printf("[%d] %-20s %.2f\n", ca.dessert[i].id, ca.dessert[i].name, ca.dessert[i].price);
	scanf("%d", &menu);
	if (menu >= 1 && menu <= 5)
	{
		ca.order_des[menu - 1].id++;
		printf("%s를 주문하였습니다.\n\n", ca.dessert[menu - 1].name);
	}
	else printf("없는 주문 번호입니다. 돌아갑니다\n");
}

void print_receipt()
{

}