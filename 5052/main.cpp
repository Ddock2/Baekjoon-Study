#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_STRING_SIZE 11

void LoadOneTestCase(int listNumber, char testCaseNumberList[][MAX_NUMBER_STRING_SIZE]);
void CheckConsistencyOfList(int listNumber, char testCaseNumberList[][MAX_NUMBER_STRING_SIZE]);
int compare(const void * a, const void * b);

int main()
{
	int t;
	int n;

	char testCaseNumberList[10000][MAX_NUMBER_STRING_SIZE];

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);

		LoadOneTestCase(n, testCaseNumberList);
		qsort(testCaseNumberList, n, MAX_NUMBER_STRING_SIZE * sizeof(char), compare);

		CheckConsistencyOfList(n, testCaseNumberList);
	}

	return 0;
}

void LoadOneTestCase(int listNumber, char testCaseNumberList[][MAX_NUMBER_STRING_SIZE])
{
	int i;

	for (i = 0; i < listNumber; i++)
	{
		memset(testCaseNumberList + i, 0, MAX_NUMBER_STRING_SIZE);
		scanf("%s", testCaseNumberList + i);
	}
}

void CheckConsistencyOfList(int listNumber, char testCaseNumberList[][MAX_NUMBER_STRING_SIZE])
{
	int i;

	for (i = 1; i < listNumber; i++)
	{
		if (!strncmp(testCaseNumberList[i - 1], testCaseNumberList[i], strlen(testCaseNumberList[i - 1])))
		{
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");
}

int compare(const void * a, const void * b)
{
	return strcmp((char *)a, (char *)b);
}
