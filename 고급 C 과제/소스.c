#define _CRT_SECURE_NO_WARNINGS // scanf 처리
#include <stdio.h>				//표준 입출력 헤더파일
#include <string.h>				//문자열 헤더파일
#include <malloc.h>				//동적 할당 헤더파일
#pragma warning(disable : 6031) // scanf 경고 문구 제거
#pragma warning(disable : 6011) // 역참조 경고 문구 제거

struct node
{					   // 링크드 리스트 구조체
	char name[20];	   // 학생 이름 저장 배열
	char sub[20];	   // 과목 이름 저장 배열
	int data;		   // 점수 저장 변수
	struct node *next; // next 포인터
};

struct node *head;		 // head 포인터 생성
struct node *tmp = NULL; // 노드를 가리킴, 각 절차에서 여러 용도로 사용
struct node *pre = NULL; // tmp와 함께 노드를 가리킴, 각 절차에서 여러 용도로 사용
struct node *cur = NULL; // tmp,pre와 함께 노드를 가리킴, 각 절차에서 여러 용도로 사용

struct node *create_node(char *name, char *sub, int data); // 노드 생성 함수
void sort_sub();										   // 파일에서 입력 및 과목별 기준 정렬 함수
void sort_stu();										   // 학생별 기준 정렬 함수
void print_list(int a);									   // 링크드 리스트 출력 함수
void memory_manager();									   // 메모리 할당 해제 함수
void main()												   // 메인 함수
{
	sort_sub();		  // 파일에서 데이터 읽어오기 및 과목별 기준 정렬 함수 호출
	print_list(1);	  // 과목별 기준 리스트 출력 호출
	sort_stu();		  // 학생별 기준 정렬 함수 호출
	print_list(0);	  // 학생별 기준 리스트 출력 함수 호출
	memory_manager(); // 메모리 해제 함수 호출
}

struct node *create_node(char *name, char *sub, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node)); // 노드 한칸 메모리 할당
	new_node->data = data;												// 점수를 노드 데이터에 초기화
	strcpy(new_node->name, name);										// 학생 이름을 노드 데이터에 copy
	strcpy(new_node->sub, sub);											// 과목 이름을 노드 데이터에 copy
	new_node->next = NULL;												// next 포인터를 초기화
	return new_node;													// 생성한 노드 반환
}
void sort_sub()
{
	char finame[20]; // 파일 입력 학생 이름 배열
	char fisub[20];	 // 파일 입력 과목 이름 배열
	int fidata;		 // 파일 입력 점수 변수
	char waste[20];	 // 첫 줄 버리기 위한 char형 배열

	FILE *rfp = fopen("score.txt", "r"); // 파일 호출
	if (rfp == NULL)					 // 파일 호출 실패시 프로그램 종료 조건문
	{
		printf("파일 호출 실패\n"); // 안내 문구 출력
		return;						// 함수 종료
	}
	fscanf(rfp, "%s\t%s\t%s", waste, waste, waste); // 파일의 첫 줄에 있는  name	subject	score 버리는 용도

	while (1)
	{
		if (feof(rfp) != 0)
			break;													// 파일 끝에 도달하면 loop 탈출
		fscanf(rfp, "%s\t%s\t%d", finame, fisub, &fidata);			// 파일에서 과목이름, 학생이름, 점수 순으로 입력을 받아옴
		struct node *new_node = create_node(finame, fisub, fidata); // 연결할 노드 생성
		if (head == NULL)
			head = new_node; // 첫 노드를 head와 연결
		else
		{
			tmp = head; // tmp가 첫 노드를 가리킴
			pre = NULL; // tmp 이전 노드
			while (1)
			{
				if (tmp == NULL) // 첫 노드 연결 조건문
				{
					tmp = new_node; // head가 연결할 노드를 가리킴
					break;			// 연결할 노드 연결 시 loop 탈출
				}

				if (strcmp(new_node->sub, tmp->sub) < 0) // 연결할 노드가 비교 노드보다 앞에 위치할 때
				{
					new_node->next = tmp; // 연결할 노드의 다음 노드를 비교 노드로 설정
					if (tmp == head)
						head = new_node; // 비교 노드가 head면 head 포인터가 연결할 노드를 가리킴
					else
						pre->next = new_node; // 비교 노드가 head가 아니면 비교 노드의 이전 노드가 연결할 노드를 가리킴
					break;					  // 연결할 노드 연결 시 loop 탈출
				}
				else if (strcmp(new_node->sub, tmp->sub) == 0) // 연결할 노드와 비교 노드가 같은 과목일 때
				{
					while (1)
					{
						if (tmp == NULL) // 연결할 노드가 마지막에 올 때
						{
							pre->next = new_node; // 비교 노드의 이전 노드의 다음 노드에 연결할 노드 연결
							break;				  // 연결할 노드 연결 시 loop 탈출
						}
						if (strcmp(new_node->sub, tmp->sub) != 0) // 같은 과목 노드 이동 중 다른 과목으로 넘어갔을 때
						{
							new_node->next = tmp;
							pre->next = new_node;
							break; // 연결할 노드 연결 시 loop 탈출
						}
						if (strcmp(new_node->name, tmp->name) < 0) // 연결할 노드가 비교 노드의 전에 올 때
						{
							if (tmp == head)
							{
								new_node->next = tmp;
								head = new_node;
								break; // 연결할 노드 연결 시 loop 탈출
							}
							else
							{
								new_node->next = tmp;
								pre->next = new_node;
								break; // 연결할 노드 연결 시 loop 탈출
							}
						}
						else // 연결할 노드가 비교 노드보다 뒤일 때
						{
							if (pre != NULL)
								pre = pre->next; // tmp 이전 노드의 노드 이동
							else if (pre == NULL)
								pre = head;	 // pre를 tmp보다 한칸 뒤에 오게 함
							tmp = tmp->next; // 다음 노드로 이동
						}
					}
					break; // 연결할 노드 연결 시 loop 탈출
				}
				else if (strcmp(new_node->sub, tmp->sub) > 0) // 연결할 노드가 비교 노드의 뒤에 위치할 때
				{
					if (tmp->next == NULL) // 비교 노드의 다음 노드가 없을 때
					{
						tmp->next = new_node; // 비교 노드의 다음 노드를 연결할 노드로 설정
						break;				  // 연결할 노드 연결 시 loop 탈출
					}
					else
					{
						if (pre != NULL)
							pre = pre->next; // tmp 이전 노드의 노드 이동
						else if (pre == NULL)
							pre = head;	 // pre를 tmp보다 한칸 뒤에 오게 함
						tmp = tmp->next; // 다음 노드로 이동
					}
				}
			}
		}
	}

	fclose(rfp); // 파일 포인터 메모리 해제
}
void sort_stu()
{
	int flag = 0; // bubble sort 완료 시 loop 탈출 위한 변수
	pre = NULL;	  // cur의 이전 노드

	while (1) // 버블 정렬 밖 loop문
	{
		flag = 0;	// 0으로 초기화
		cur = head; // 비교 노드를 첫 노드로 설정

		while (1) // 버블 정렬 안 loop문
		{
			if (cur->next == NULL)
				break;									// 비교 노드가 마지막에 도달하면 loop 탈출
			if (strcmp(cur->name, cur->next->name) > 0) // 비교 노드,비교 노드의 다음 노드가 바뀔 때
			{
				//=======스왑 알고리즘======//
				tmp = cur->next;	   // tmp가 비교 노드의 다음 노드를 가리킴
				cur->next = tmp->next; // 비교 노드가 비교 노드의 다음의 다음 노드를 가리킴
				tmp->next = cur;	   // 비교 노드의 다음 노드가 비교 노드를 가리킴
				//=========================//
				if (pre != NULL)
					pre->next = tmp; // 이전 노드가 있으면 비교 노드의 이전 노드를 현재 비교 노드로 설정
				else
					head = tmp; // 이전 노드가 없으면 head 포인터가 스왑 이후 앞으로 옮겨진 노드를 가리킴

				pre = tmp; // 이전 노드를 비교 노드의 전으로 설정
				flag++;	   // 스왑 발생으로 인해 flag 증가
			}
			else
			{
				pre = cur;		 // 비교 노드의 이전 노드를 비교 노드의 위치로 옮김
				cur = cur->next; // 다음 노드로 이동
			}
		}
		pre = NULL; // 이전 노드 포인터 초기화
		if (flag == 0)
			break; // 정렬이 끝나면 loop 탈출
	}
}
void print_list(int a)
{
	tmp = head;				 // tmp가 처음 노드를 가리킴
	char check[20] = {'\0'}; // 학생이나 과목별 section이 바뀔 때를 검사하는 용도
	float total = 0;		 // 평균 계산을 위한 전체 변량의 합
	int gasu = 0;			 // 변량의 개수

	if (a == 1) // 과목별 기준 출력
	{
		FILE *wfp = fopen("record.txt", "w");
		printf("==============과목별 학생 점수 출력===============\n");		  // 과목별 출력임을 표현
		fprintf(wfp, "==============과목별 학생 점수 출력===============\n"); // 과목별 출력임을 표현
		strcpy(check, tmp->sub);											  // section이 바뀜을 검사하기 위해 처음 노드의 과목 이름을 check에 copy
		while (1)															  // 리스트 출력 loop 문
		{
			if (tmp == NULL) // 마지막 section의 평균 출력에서 발생하는 예외 처리
			{
				printf("\n%s의 평균 점수: %.2f\n\n", check, total / gasu);		 // 과목 이름, 평균 출력
				fprintf(wfp, "\n%s의 평균 점수: %.2f\n\n", check, total / gasu); // 과목 이름, 평균 파일 출력
				break;															 // 마지막 출력 후 loop 탈출
			}
			else
			{
				if (strcmp(check, tmp->sub) == 0) // 같은 section일때
				{
					total += (float)tmp->data; // 변량에 더함
					gasu++;					   // 변량 개수 증가
				}
				else // 다른 section일 때
				{
					printf("\n%s의 평균 점수: %.2f\n\n", check, total / gasu);		 // 평균 출력
					fprintf(wfp, "\n%s의 평균 점수: %.2f\n\n", check, total / gasu); // 평균 파일 출력
					strcpy(check, tmp->sub);										 // 다음 section 과목을 copy
					total = (float)tmp->data;										 // 전체 총합을 다음 section값의 첫 값으로 초기화
					gasu = 1;														 // 변량 개수를 1로 초기화
				}
				printf("%-12s\t%-12s\t%-3d\n", tmp->sub, tmp->name, tmp->data);		  // 과목 이름, 학생 이름, 점수를 출력
				fprintf(wfp, "%-12s\t%-12s\t%-3d\n", tmp->sub, tmp->name, tmp->data); // 과목 이름, 학생 이름, 점수를 파일에 출력
				tmp = tmp->next;													  // 다음 노드로 이동
			}
		}
		printf("\n================================================\n\n\n");		  // 출력 나눔 표시
		fprintf(wfp, "\n================================================\n\n\n"); // 출력 나눔 표시
		fclose(wfp);
	}
	else if (a == 0) // 학생별 기준 출력
	{
		FILE *wfp = fopen("record.txt", "a");
		printf("============학생별 과목 점수 출력===============\n");		// 학생별 출력임을 표현
		fprintf(wfp, "============학생별 과목 점수 출력===============\n"); // 학생별 출력임을 표현(파일)
		strcpy(check, tmp->name);											// section이 바뀜을 검사하기 위해 처음 노드의 학생 이름을 check에 copy
		float ototal = 0;													// 60 초과 평균을 계산하기 위한 전체 변량의 합
		int ogasu = 0;														// 60 초과 평균의 변량의 개수
		while (1)															// 리스트 출력 loop 문
		{
			if (tmp == NULL) // 마지막 section의 평균 출력에서 발생하는 예외 처리
			{
				printf("\n%s의 평균 점수: %.2f\n\n", check, total / gasu);		 // 학생 이름, 평균 출력
				fprintf(wfp, "\n%s의 평균 점수: %.2f\n\n", check, total / gasu); // 학생 이름, 평균 파일 출력(파일)
				if (ototal != 0)
				{
					printf("60점 이하 점수들을 제외한 학생의 평균 점수: %.2f\n\n", ototal / ogasu);		  // 60초과 평균 출력
					fprintf(wfp, "60점 이하 점수들을 제외한 학생의 평균 점수: %.2f\n\n", ototal / ogasu); // 60초과 평균 출력(파일)
				}
				else
				{
					printf("이 학생은 60점이 넘는 점수가 없네요! 분발하세요! \n\n");	   // 60이하의 점수만 존재할 시 예외처리
					fprintf(wfp, "이 학생은 60점이 넘는 점수가 없네요! 분발하세요! \n\n"); // 60이하의 점수만 존재할 시 예외처리(파일)
				}
				break; // 마지막 출력 후 loop 탈출
			}
			else
			{
				if (strcmp(check, tmp->name) == 0) // 같은 section일때
				{
					total += (float)tmp->data; // 변량에 더함
					gasu++;					   // 변량 개수 증가
					if (tmp->data > 60)		   // 60 초과 점수일 때
					{
						ototal += (float)tmp->data; // 60 초과 점수를 전체 변량에 더함
						ogasu++;					// 60초과 변량 개수 증가
					}
				}
				else // 다른 section일 때
				{
					printf("\n%s의 평균 점수: %.2f\n\n", check, total / gasu);		 // 평균 출력
					fprintf(wfp, "\n%s의 평균 점수: %.2f\n\n", check, total / gasu); // 평균 출력
					if (ototal != 0)
					{
						printf("60점 이하 점수들을 제외한 학생의 평균 점수: %.2f\n\n\n", ototal / ogasu);		// 60 초과 평균 출력
						fprintf(wfp, "60점 이하 점수들을 제외한 학생의 평균 점수: %.2f\n\n\n", ototal / ogasu); // 60 초과 평균 출력
					}
					else
					{
						printf("이 학생은 60점이 넘는 점수가 없네요! 분발하세요!\n\n\n");		// 60 이하의 점수만 존재할 시 예외처리
						fprintf(wfp, "이 학생은 60점이 넘는 점수가 없네요! 분발하세요!\n\n\n"); // 60 이하의 점수만 존재할 시 예외처리
					}
					strcpy(check, tmp->name); // 다음 section 학생 이름을 copy
					total = (float)tmp->data; // 다음 section의 첫 값으로 초기화
					gasu = 1;				  // 변량 개수를 1로 초기화
					if (tmp->data > 60)		  // 다음 section의 첫 값이 60초과일 때
					{
						ototal = (float)tmp->data; // 전체 변량을 다음 노드의 첫 값으로 초기화
						ogasu = 1;				   // 변량 개수를 1로 초기화
					}
					else // 60 이하일 떄
					{
						ototal = 0; // 전체 변량을 0으로 초기화
						ogasu = 0;	// 변량 개수를 0으로 초기화
					}
				}
				printf("%-12s\t%-12s\t%-3d\n", tmp->name, tmp->sub, tmp->data);		  // 학생 이름, 과목 이름, 점수를 출력
				fprintf(wfp, "%-12s\t%-12s\t%-3d\n", tmp->name, tmp->sub, tmp->data); // 학생 이름, 과목 이름, 점수를 파일 출력
				tmp = tmp->next;													  // 다음 노드로 이동
			}
		}
		printf("\n================================================\n\n\n");		  // 출력 나눔 표시
		fprintf(wfp, "\n================================================\n\n\n"); // 출력 나눔 표시
		fclose(wfp);
	}
}
void memory_manager()
{
	pre = head;			// 해제할 노드를 가리킴
	tmp = pre->next;	// 해제할 노드의 next 가리킴, 이동할 포인터
	while (pre != NULL) // 마지막 노드를 지나면 loop를 탈출함
	{
		free(pre); // 노드 메모리 할당 해제
		pre = tmp; // 해제한 포인터를 다음 노드를 가리키게 함
		if (tmp == NULL)
			break;		 // pre가 마지막 노드를 해제한 후, tmp가 NULL이면 loop를 탈출함
		tmp = tmp->next; // tmp가 다음 노드를 가리킴
	}
}