#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void main()
{
	int a, b, len = 1;
	char *arr;
	printf("변환 수 입력:");
	scanf("%d", &a);

	b = (a - a % 100) / 100;

	arr = (char *)malloc(sizeof(char) * len + 1);
	arr[0] = '\0';
	--len;
	if (b <= 3)
	{
		for (int i = 0; i < b; i++)
		{
			len += 1;
			arr = (char *)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'C';
		}
		arr[len] = '\0';
	}
	else if (b >= 5 && b <= 8)
	{
		++len;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'D';
		for (int i = 0; i < b - 5; i++)
		{
			len += 1;
			arr = (char *)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'C';
		}
	}
	else if (b == 9)
	{
		len += 1;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'C';
		++len;
		arr[len - 1] = 'M';
	}
	else
	{
		len += 1;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'C';
		++len;
		arr[len - 1] = 'D';
	}

	b = (a % 100 - a % 10) / 10;

	if (b <= 3)
	{
		for (int i = 0; i < b; i++)
		{
			len += 1;
			arr = (char *)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'X';
		}
		arr[len] = '\0';
	}
	else if (b >= 5 && b <= 8)
	{
		++len;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'L';
		for (int i = 0; i < b - 5; i++)
		{
			len += 1;
			arr = (char *)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'X';
		}
	}
	else if (b == 9)
	{
		len += 1;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'X';
		++len;
		arr[len - 1] = 'C';
	}
	else
	{
		len += 1;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'X';
		++len;
		arr[len - 1] = 'L';
	}

	b = a % 10;

	if (b <= 3)
	{
		for (int i = 0; i < b; i++)
		{
			len += 1;
			arr = (char *)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'I';
		}
		arr[len] = '\0';
	}
	else if (b >= 5 && b <= 8)
	{
		++len;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'V';
		for (int i = 0; i < b - 5; i++)
		{
			++len;
			arr = (char *)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'I';
		}
	}
	else if (b == 9)
	{
		len += 1;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'I';
		++len;
		arr[len - 1] = 'X';
	}
	else
	{
		len += 1;
		arr = (char *)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'I';
		++len;
		arr[len - 1] = 'V';
	}
	printf("%d=%d+%d+%d=%s, %d", a, (a - a % 100), (a % 100 - a % 10), b, arr, len);
	free(arr);
}