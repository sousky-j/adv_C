#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning (disable: 6031)
#pragma warning (disable: 6011)

struct node {//링크드 리스트 구조체
	char name[20];//학생 이름 배열
	char sub[20];//과목 이름 배열
	int data;//점수 변수
	struct node* down;//열 포인터 (세로축 next 포인터)
	struct node* next;//행 포인터 (가로축 next 포인터)
};
struct node* head;//head 포인터 생성

struct node* create_node(char* name, char* sub, int data);
void print_list();

void main()
{
	char finame[20];//파일 입력 학생 이름 배열
	char fisub[20];//파일 입력 과목 이름 배열
	int fidata;//파일 입력 점수 변수
	char waste[20];//첫 줄 버리기 위한 char형 배열
	int line = 0;//과목 개수
	
	///////////////////////////////////////////////
	FILE* rfp = fopen("score.txt", "r");//파일 호출
	if (rfp == NULL)//파일 호출 실패시 프로그램 종료 조건문
	{
		printf("파일 호출 실패\n");
		return;
	}
	fscanf(rfp, "%s\t%s\t%s", waste, waste, waste);//첫 줄의 name	subject	score 버리는 용도
	///////////////////////////////////////////////



	////////////////파일에서 입력받아 2차원 링크드 리스를 생성하는 알고리즘////////
	while (1)
	{
		if (feof(rfp) != 0)
			break;
		fscanf(rfp, "%s\t%s\t%d", finame, fisub, &fidata);
		struct node* new_node = create_node(finame, fisub, fidata);
		if (head == NULL)
		{
			head = new_node;
			line++;
		}
		else
		{
			struct node* tmp = head;//탐색자: new_node가 들어가야 할 위치를 탐색함
			int flag = 0;//노드가 연결되면 탐색을 정지하는 flag
			while (1)
			{
				if (strcmp(new_node->sub, tmp->sub) == 0) break;//tmp가 같은 과목이 찾으면 내려가기를 멈춤
				if (tmp->down == NULL)//이름을 찾는데 같은 이름이 없으면 열에 추가함
				{
					tmp->down = new_node;
					flag++;
					line++;
					break;
				}
				else//같은 이름 없으면 내려감
					tmp = tmp->down;
			}
			while (1)
			{
				if (flag == 1) break;//이미 new_node가 연결되었다면 이 loop를 돌지 않음
				if (tmp->next == NULL)//리스트의 끝에 도달하면 new_node를 삽입
				{
					tmp->next = new_node;
					break;
				}
				else//
					tmp = tmp->next;
			}
		}
	}
	/////////////////////////////////////




	/////////////////각 열별 행 크기 구하는 알고리즘///////////////////
	int* list_size = (int*)calloc(line, sizeof(int));//각 열별 행의 크기를 담는 배열
	for (int i = 0; i < line; i++)
	{
		struct node* cur = head;//탐색자: list_size의 각 열별 행의 크기를 가져오기 위해 사용
		for (int j = 0; j < i; j++)
			cur = cur->down;
		while (cur != NULL)
		{
			cur = cur->next;
			list_size[i]++;
		}
		printf("%d\n", list_size[i]);
	}
	/////////////////////////////////////////////////////////////////


	
	/////////////정렬 알고리즘///////////////////
	for (int i = 0; i < line; i++)
	{
		struct node* tmp = head;//탐색자와 바뀔 노드
		struct node* cur = NULL;//tmp의 이전 노드
		struct node* sear = head;//탐색자: 앞으로 올 노드를 탐색
		for (int p = 0; p < i; p++)
		{
			tmp = tmp->next;
		}
		if (tmp != head)
		{
			cur = head;
		}
		for (int j = i + 1; j < line; j++)
		{

		}
	}
	///////////////////////////////////////////


	print_list();


	fclose(rfp);
}

struct node* create_node(char* name, char* sub, int data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	strcpy(new_node->name, name);
	strcpy(new_node->sub, sub);
	new_node->next = NULL;
	new_node->down = NULL;
	return new_node;
}

void print_list()
{
	struct node* tmp = head;
	int l = 0;
	while(1)
	{
		tmp = head;
		for (int j = 0; j < l; j++)
			tmp = tmp->down;

		if (tmp == NULL) break;

		while (1)
		{
			if (tmp == NULL) break;
			printf("%-12s\t%-12s\t%3d\n", tmp->sub, tmp->name, tmp->data);
			tmp = tmp->next;
		}
		l++;
	}
}