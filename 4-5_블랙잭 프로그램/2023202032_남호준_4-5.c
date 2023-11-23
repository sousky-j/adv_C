#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable: 6031)

void shuffle();//카드 20장 만드는 함수 (malloc, random 사용)
void initialization();//카드를 2장씩 유저-딜러 순으로 분배하는 함수 ex) 유저-딜러-유저-딜러 (malloc 사용)
void status();//현재 카드 상황을 출력하는 함수
void hit();//카드를 1장씩 유저에게 주는 함수 (realloc 사용)
void end();//딜러가 규칙에 따라 16점 이하일 경우 계속 카드를 받고, 17점 이상일 시 더이상 카드를 받지 않게 만드는 함수
void result();//유저의 승리 및 패배를 검토하는 함수 (free를 통한 메모리 해제)

void main()//코드 내 조건문 처리(게임 시작)
{
	int i=0;
	char check[30];
	char start[2][10] = { "start", "end" };
	char* p=0;
	int* a=0;


	while (1) {
		while(1) {printf("Game Start? "); scanf("%s", check);
			if (strcmp(check, start[0]) == 0) break;
			else if (strcmp(check, start[1]) == 0) {i = 1; break;}
			else printf("Error: Wrong Input, Try Again\n");}
		if (i == 1)	break;

		shuffle(p, a);



	}
}

void shuffle(char* p, int* a)
{
	srand(time(NULL));
	int cnt;
	a = (int*)malloc(sizeof(int) * 20);
	for (cnt = 0; cnt < 20; cnt++)
		*(a + cnt) = (rand() % 13) + 1;
	for (cnt = 0; cnt < 20; cnt++)
		printf("%d ", *(a + cnt));
	printf("\n");
}
