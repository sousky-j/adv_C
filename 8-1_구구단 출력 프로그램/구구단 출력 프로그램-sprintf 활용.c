#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a;
    printf("출력하고 싶은 단 수를 입력: ");
    scanf("%d", &a);

    char file_name[1000];
    sprintf(file_name, "%d_dan.txt", a);

    FILE* wfp = fopen(file_name, "w");
    if (wfp == NULL) {
        perror("파일 열기 실패");
    }

    for (int i = 1; i <= 9; i++) {
        fprintf(wfp, "%d X %d = %d", a, i, a * i);
        if (i != 9) fprintf(wfp,"\n");
    }

    fclose(wfp);
}