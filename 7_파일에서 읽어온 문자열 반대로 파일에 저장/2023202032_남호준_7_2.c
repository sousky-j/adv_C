#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void main()
{
	FILE *rfp;
	FILE *wfp;
	char read[20];
	char *write[4];
	int i, j, r;
	rfp = fopen("C:\\Users\\in.txt", "r");
	wfp = fopen("C:\\Users\\output2.txt", "w");

	for (i = 0; i < 4; i++)
	{
		fscanf(rfp, "%s", read);
		r = strlen(read);
		write[i] = (char *)malloc(sizeof(char) * r + 1);
		for (j = 0; j < r; j++)
			write[i][r - j - 1] = read[j];
		write[i][r] = '\0';
	}

	for (i = 0; i < 4; i++)
	{
		printf("%d: %s\n", i + 1, write[i]);
		fputs(write[i], wfp);
		fputs("\n", wfp);
	}

	for (i = 0; i < 4; i++)
		free(write[i]);
	fclose(rfp);
	fclose(wfp);
}