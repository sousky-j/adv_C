#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 6031)

void main()
{
	int a, b, len = 0;
	char* arr;
	printf("변환 수 입력:");
	scanf("%d", &a);
	if (a == 1000)
	{
		printf("1000=1000=M, 1");
		return;
	}
	b = a / 100;

	arr = (char*)malloc(sizeof(char));
	arr[0] = '\0';
	if (b <= 3)
	{
		for (int i = 0; i < b; i++)
		{
			len += 1;
			arr = (char*)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'C';
		}
		arr[len] = '\0';
	}
	else if (b >= 5 && b <= 8)
	{
		++len;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'D';
		for (int i = 0; i < b - 5; i++)
		{
			len += 1;
			arr = (char*)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'C';
		}
	}
	else if (b == 9)
	{
		len += 1;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'C';
		++len;
		arr[len - 1] = 'M';
	}
	else
	{
		len += 1;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
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
			arr = (char*)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'X';
		}
		arr[len] = '\0';
	}
	else if (b >= 5 && b <= 8)
	{
		++len;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'L';
		for (int i = 0; i < b - 5; i++)
		{
			len += 1;
			arr = (char*)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'X';
		}
	}
	else if (b == 9)
	{
		len += 1;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'X';
		++len;
		arr[len - 1] = 'C';
	}
	else
	{
		len += 1;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
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
			arr = (char*)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'I';
		}
		arr[len] = '\0';
	}
	else if (b >= 5 && b <= 8)
	{
		++len;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'V';
		for (int i = 0; i < b - 5; i++)
		{
			++len;
			arr = (char*)realloc(arr, sizeof(char) * (len + 1));
			arr[len - 1] = 'I';
		}
	}
	else if (b == 9)
	{
		len += 1;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'I';
		++len;
		arr[len - 1] = 'X';
	}
	else
	{
		len += 1;
		arr = (char*)realloc(arr, sizeof(char) * (len + 1));
		arr[len - 1] = 'I';
		++len;
		arr[len - 1] = 'V';
	}
	int zari[3] = { (a - a % 100), (a % 100 - a % 10) , b };
	printf("%d=", a);
	for (int i = 0; i < 3; i++)
	{
		if (!zari[i])
			continue;
		char c = i < 2 ? '+' : '=';
		printf("%d%c", zari[i], c);
	}
	for (int i = 0; i < len; i++)
		printf("%c", arr[i]);
	printf(", %d", len);
	free(arr);
}