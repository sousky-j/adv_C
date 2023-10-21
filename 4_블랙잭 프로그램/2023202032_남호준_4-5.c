#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable: 6031)

void shuffle(char* p, int* a);
void main()
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