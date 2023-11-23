#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning (disable: 6031)

struct book
{
	int id;//도서 ID
	int odd;//남은 권 수
	char name[50];//도서 제목
};
struct book b[21];//도서관

struct borrow
{
	int id;
	char name[50];
};

int initial_booklist();
void manage_booklist(struct borrow* p, struct book b[21], int id, int* bilin);
int admin_check(char* argv1, char* argv2);
void print_booklist();

void main(int argc, char* argv[])
{
	int tran;//서비스 모드 전환 입력변수
	int id;//id 입력
	int bil = 0;//빌린 권수
	struct borrow* p;//대여 도서
	p = (struct borrow*)malloc(sizeof(struct borrow));// realloc 위한 malloc
	if (initial_booklist() != 0) return;	//도서관 도서 초기화

	if (admin_check(argv[1],argv[2]) == 1)
	{
		printf("관리자 모드에 진입합니다.\n");
		printf("현재 보유 도서의 재고 현황을 출력합니다.\n");
		printf("========== Book list ==========\n");
		for (int i = 0; i < 21; i++)
			printf("%2d : %35s %d\n", b[i].id, b[i].name, b[i].odd);
		printf("===============================\n");
		printf("서비스 모드로 전환은 1 (또는 종료: 나머지 수): ");
		scanf("%d", &tran);
		if (tran != 1) return;
	}
	
	while (1)
	{
		print_booklist();
		scanf("%d", &id);
		if (id == 0)	break;
		else if (id < 1 || id > 21) { printf("보유하지 않은 도서입니다. 돌아갑니다.\n\n"); continue; }
		p = (struct borrow*)realloc(p, sizeof(struct borrow) * (bil + 1));
		manage_booklist(p, b, id, &bil);

		printf("=========== Borrowed Book List ===========\n");
		for (int i = 0; i < bil; i++)
			printf("%d : %s\n", p[i].id, p[i].name);
		printf("===========================================\n");
	}
	free(p);
}

int initial_booklist()
{
	FILE* rfp = fopen("book.txt", "r");
	if (rfp == NULL)
	{
		printf("파일 호출 실패");
		return 1;
	}
	for (int i = 0; i < 21; i++)
	{
		fgets(b[i].name, 50, rfp);
		b[i].name[strlen(b[i].name) - 1] = '\0';
		b[i].id = i + 1;
		b[i].odd = 3;
	}
	fclose(rfp);
	return 0;
}

void manage_booklist(struct borrow* p, struct book b[21], int id, int* bil)
{	
	id--;
	if (b[id].odd == 0)
		printf("현재 재고가 없습니다. 돌아갑니다.\n");
	else
	{
		*bil += 1;
		p = (struct borrow*)realloc(p, sizeof(struct borrow) * (*bil));
		b[id].odd -= 1;
		p[*bil - 1].id = id + 1;
		strcpy(p[*bil - 1].name, b[id].name);
		printf("Borrow a Book.\n");
	}
}

int admin_check(char* argv1, char* argv2)
{
	char trash[20] = { '\0'};
	char id[20] = { '\0'};
	char pw[20] = { '\0'};
	FILE* rfp = fopen("admin_auth.txt", "r");
	if (rfp == NULL)
	{
		printf("파일 호출 실패");
		return 0;
	}
	fscanf(rfp,"%s  %s", trash, id);
	fscanf(rfp,"%s %s", trash, pw);
	fclose(rfp);
	if ((strcmp(argv1, id) == 0) && (strcmp(argv2, pw) == 0)) return 1;
	else return 0;
}

void print_booklist()
{
	printf("========== Book list ==========\n");
	for (int i = 0; i < 21; i++)
		printf("%d : %s\n", b[i].id, b[i].name);
	printf("===============================\n");
	printf("Type the book id to borrow(0 to end) : ");
}