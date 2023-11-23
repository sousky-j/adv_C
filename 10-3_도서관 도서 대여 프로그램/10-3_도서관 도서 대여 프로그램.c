#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
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

void initial_booklist(struct book b[21]);
void manage_booklist(struct borrow* p, struct book b[21], int id, int* bilin);

void main()
{
	int id;//id 입력
	int bil=0;//빌린 권수
	int* bilin = &bil;
	struct borrow* p;//대여 도서
	p = (struct borrow*)malloc(sizeof(struct borrow) * bil);// realloc 위한 malloc
	initial_booklist(b);//도서관 도서 초기화

	while (1)
	{
		printf("========== Book list ==========\n");
		for (int i = 0; i < 21; i++)
			printf("%d : %s\n", b[i].id, b[i].name);
		printf("===============================\n");
		printf("Type the book id to borrow(0 to end) : ");
		scanf("%d", &id);
		if (id == 0)	break;
		else if (id < 1 || id > 21) {	printf("보유하지 않은 도서입니다. 돌아갑니다.\n\n"); continue;	}
		p = (struct borrow*)realloc(p, sizeof(struct borrow) * (bil + 1));
		manage_booklist(p, b, id, bilin);

		printf("=========== Borrowed Book List ===========\n");
		for (int i = 0; i < bil; i++)
			printf("%d : %s\n", p[i].id, p[i].name);
		printf("===========================================\n");
	}
	free(p);
}

void manage_booklist(struct borrow* p, struct book b[21], int id, int* bilin)
{
	id--;
	if (b[id].odd == 0)
		printf("The Book is out of stock.\n");
	else
	{
		*bilin += 1;
		p = (struct borrow*)realloc(p, sizeof(struct borrow) * (*bilin));
		b[id].odd -= 1;
		p[*bilin-1].id = id+1;
		strcpy(p[*bilin-1].name, b[id].name);
		printf("Borrow a Book.\n");
	}
}

void initial_booklist(struct book b[21])
{
	FILE* rfp = fopen("book.txt", "r");
	for (int i = 0; i < 21; i++)
	{
		fgets(b[i].name, 50, rfp);
		b[i].name[strlen(b[i].name) - 1] = '\0';
		b[i].id = i + 1;
		b[i].odd = 3;
	}
	fclose(rfp);
}