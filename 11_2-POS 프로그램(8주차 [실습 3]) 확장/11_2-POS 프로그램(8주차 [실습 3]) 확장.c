#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

struct name_tag
{
	int id;
	char name[20];
	double price;
};
struct receipt
{
	struct name_tag tag;
	char menu[20];
};
struct name_tag dri[5];
struct name_tag eat[5];


int Initial_menulist();
void drink_count(double *total,int *buy, struct receipt** bil);
void dessert_count(double *total,int *buy, struct receipt** bil);
void print_receipt(double total,int buy, struct receipt* bil);

void main()
{
	double total=0.0;//주문 총액
	int id;//주문 메뉴 입력
	int buy=0;//주문 개수
	struct receipt* bil = (struct receipt*)malloc(sizeof(struct receipt));//realloc 위한 malloc
	if (Initial_menulist() == 1) return;//파일 호출 실패시 종료

	while (1) {
		printf("1:음료 주문 2:디저트 주문 0:종료\n");
		scanf("%d", &id);
		if (id == 0) break;
		else if (id == 1) drink_count(&total, &buy, &bil);
		else if (id == 2) dessert_count(&total, &buy, &bil);
		else printf("잘못된 주문 메뉴를 입력하였습니다. 돌아갑니다.\n");
	}

	print_receipt(total, buy, bil);
	for (int i = 0; i < buy; i++)
		printf("%10s:%2d%15s %3.2lf\n", bil[i].menu, bil[i].tag.id, bil[i].tag.name, bil[i].tag.price);
	printf("total : %.2lf", total);
	free(bil);
}

int Initial_menulist()
{
	FILE* rfp2 = fopen("dessert.txt", "r");
	FILE* rfp1 = fopen("drink.txt", "r");
	if (rfp1 == NULL || rfp2 == NULL) {
		printf("파일 호출 실패");
		return 1;
	}
	for (int i = 0; i < 5; i++) {
		dri[i].id = i + 1;
		eat[i].id = i + 1;
		fscanf(rfp1, "%s %lf", dri[i].name, &dri[i].price);
		fscanf(rfp2, "%s %lf", eat[i].name, &eat[i].price);
	}
	fclose(rfp1);
	fclose(rfp2);
	return 0;
}
void drink_count(double *total,int* buy, struct receipt** bil)
{
	int id1;
	printf("===========음료===========\n");
	for (int i = 0; i < 5; i++)
		printf("%2d:%15s %3.2lf\n", dri[i].id, dri[i].name, dri[i].price);
	printf("==========================\n");
	printf("메뉴 id 입력: ");
	scanf("%d", &id1);
	if (id1 >= 1 && id1 <= 5)
	{
		*buy += 1;
		printf("%s를 주문합니다.\n", dri[id1 - 1].name);
		*bil = (struct receipt*)realloc(*bil, sizeof(struct receipt) * (*buy + 1));
		(*bil)[*buy - 1].tag.id = id1;
		strcpy((*bil)[*buy - 1].tag.name, dri[id1 - 1].name);
		(*bil)[*buy - 1].tag.price = dri[id1 - 1].price;
		strcpy((*bil)[*buy - 1].menu,"drink");
		*total += dri[id1 - 1].price;
	}
	else
		printf("메뉴가 없습니다. 돌아갑니다.\n");
}
void dessert_count(double *total,int *buy, struct receipt** bil)
{
	int id1;
	printf("===========디저트===========\n");
	for (int i = 0; i < 5; i++)
		printf("%2d:%15s %3.2lf\n", eat[i].id, eat[i].name, eat[i].price);
	printf("==========================\n");
	printf("메뉴 id 입력: ");
	scanf("%d", &id1);
	if (id1 >= 1 && id1 <= 5)
	{
		*buy += 1;
		printf("%s를 주문합니다.\n", eat[id1 - 1].name);
		*bil = (struct receipt*)realloc(*bil, sizeof(struct receipt) * (*buy));
		(*bil)[*buy - 1].tag.id = id1;
		strcpy((*bil)[*buy - 1].tag.name, eat[id1 - 1].name);
		(*bil)[*buy - 1].tag.price = eat[id1 - 1].price;
		strcpy((*bil)[*buy - 1].menu, "dessert");
		*total += eat[id1 - 1].price;
	}
	else
		printf("메뉴가 없습니다. 돌아갑니다.\n");
}
void print_receipt(double total,int buy, struct receipt* bil)
{
	FILE* wfp = fopen("receipt.txt", "w");
	for (int i = 0; i < buy; i++)
		fprintf(wfp, "%10s:%2d%15s %3.2lf\n", bil[i].menu, bil[i].tag.id, bil[i].tag.name, bil[i].tag.price);
	fprintf(wfp, "\n\t\ttotal:  %.2lf", total);
	fclose(wfp);
}