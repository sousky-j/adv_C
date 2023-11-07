#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable: 6031)

void make_dictionary(char** B,int line);
my_strcmp(char** B,int i);

void main()
{
    FILE* rfp;
    FILE* wfp;
    char imsi[100] = { NULL, };
    char* A[8] = { NULL, };
    char** B = NULL;
    char dan[20] = { NULL, };
    int len=0, each = 0, tmp = 0, i = 0;
    int ch = 1,line=1;
    int overlap = 0;
    rfp = fopen("C:\\Users\\hojun\\OneDrive\\바탕 화면\\파일 입출력 파일\\words.txt", "r");
    wfp = fopen("C:\\Users\\hojun\\OneDrive\\바탕 화면\\파일 입출력 파일\\dictionary.txt", "w");


    B = (char**)malloc(sizeof(char*) * line);
    B = NULL;
    while (!feof(rfp))
    {
        fgets(imsi, 100, rfp);
        len = strlen(imsi);
        A[i] = (char*)malloc(sizeof(char) * len + 1);
        strcpy(A[i], imsi);

        for (int j = 0; j < len; j++)
        {
            if (ch == 1)
            {
                B = (char**)realloc(B, sizeof(char*) * line);
                ch = 0;
            }

            if (A[i][j] == '\n')
            {
                if (overlap == 1)
                {
                    each--;
                    overlap = 0;
                    continue;
                }
                ch = 1;
                *(B + each) = (char*)malloc(sizeof(char) * tmp + 1);
                strcpy(*(B + each), dan);
                for (int k = 0; k < tmp; k++)
                    dan[k] = '\0';
                each++;
                line++;
                tmp = 0;
                overlap = 0;
                break;
            }

            if (A[i][j] == '|' || A[i][j] == ';' || A[i][j] == ',' || A[i][j] == '\t')
            {
                if (overlap == 1)
                {
                    each--;
                    overlap = 0;
                    continue;
                }

                ch = 1;
                *(B+each) = (char*)malloc(sizeof(char) * tmp + 1);
                strcpy(*(B+each), dan);
                for (int k = 0; k < tmp; k++)
                    dan[k] = '\0';
                each++;
                line++;
                tmp = 0;
                overlap = 1;
            }
            else
            {
                dan[tmp] = A[i][j];
                tmp++;
                overlap=0;
            }
        }
        i++;
        *imsi = NULL;
    }

    for (i = 0; i < each; i++)
        puts(B[i]);

    fclose(rfp);
    fclose(wfp);
}

void make_dictionary(char** B,int line)
{
    int k;
    char tmp[20] = { NULL, };
    for (int i = 0; i < line; i++)
    {
        k = i + 1;
        for (k; k < line; k++)
        {
            my_strcmp(B, i);
            if (strcmp(B[i], B[k]) > 0)
            {
                strcpy(tmp, B[i]);
                strcpy(B[i], B[k]);
                strcpy(B[k], tmp);
            }
        }
    }

}

my_strcmp(char** B,int i)
{
/*    for (i; i < sizeof(B); i++)
    {
        if (B[i][j] > 64 && B[i][j] < 91)
            B[i][j] += 32;
    }
*/
}