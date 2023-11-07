#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable: 6031)

void make_dictionary(char** B, int line);
my_strcmp(char** B, int i);
void main()
{
    FILE* rfp;
    FILE* wfp;
    char imsi[100];
    char* A[8] = { NULL, };
    char* B[40] = { NULL, };
    char dan[20];
    int len, each = 0, tmp = 0;
    int overlap = 0;
    rfp = fopen("C:\\Users\\hojun\\OneDrive\\바탕 화면\\파일 입출력 파일\\words.txt", "r");
    wfp = fopen("C:\\Users\\hojun\OneDrive\\바탕 화면\\파일 입출력 파일\\dictionary.txt", "w");

    for (int i = 0; i < 8; i++)
    {
        fgets(imsi, 100, rfp);
        len = strlen(imsi);
        A[i] = (char*)malloc(sizeof(char) * len + 1);
        strcpy(A[i], imsi);

        for (int j = 0; j < len; j++)
        {
            if (A[i][j] == '\n' )
                break;
            if (A[i][j] == '|' || A[i][j] == ';' || A[i][j] == ',' || A[i][j] == '\t')
            {
                if (overlap == 1)
                {
                    each--;
                    overlap = 0;
                    continue;
                }
                B[each] = (char*)malloc(sizeof(char) * tmp + 1);
                strcpy(B[each], dan);
                for (int k = 0; k < tmp; k++)
                    dan[k] = '\0';
                each++;
                tmp = 0;
                overlap = 1;
            }
            else
            {
                dan[tmp] = A[i][j];
                tmp++;
                overlap = 0;
            }
        }
    }

    for (int i = 0; i < each; i++)
        puts(B[i]);

    fclose(rfp);
    fclose(wfp);
}