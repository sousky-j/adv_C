#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int file_produce(int a);
void main()
{
    int a;
    printf("����ϰ� ���� �� ���� �Է�: ");
    scanf("%d", &a);
    int i;
    i=file_produce(a);
}
int file_produce(int a)
{
    FILE* wfp = NULL;
    switch (a){
    case 1: wfp = fopen("1_dan.txt", "w");break;
    case 2: wfp = fopen("2_dan.txt", "w");break;
    case 3: wfp = fopen("3_dan.txt", "w");break;
    case 4: wfp = fopen("4_dan.txt", "w");break;
    case 5: wfp = fopen("5_dan.txt", "w");break;
    case 6: wfp = fopen("6_dan.txt", "w");break;
    case 7: wfp = fopen("7_dan.txt", "w");break;
    case 8: wfp = fopen("8_dan.txt", "w");break;
    case 9: wfp = fopen("9_dan.txt", "w");break;
    default: printf("1~9 ������ ���ڸ� �Է��ϼ���.");break;
    }
    if (wfp == NULL) {
        perror("���� ���� ����");
        return 1;
    }
    for (int i = 1; i <= 9; i++) {
        fprintf(wfp, "%d X %d = %d", a, i, a * i);
        if (i != 9) fprintf(wfp, "\n");
    }

    fclose(wfp);
    return 0;
}