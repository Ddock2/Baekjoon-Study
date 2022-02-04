#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH	51

void PrintIsVPS(char * ps);

int main()
{
	int testCaseNumber;
	char inputBuffer[MAX_STRING_LENGTH];

	scanf("%d", &testCaseNumber);
	scanf("%c", inputBuffer);		// input buffer에 들어있는 개행문자를 뻬냄

	while (testCaseNumber--)
	{
		memset(inputBuffer, 0, sizeof(inputBuffer));
		scanf("%s", inputBuffer);

		PrintIsVPS(inputBuffer);
	}

	return 0;
}

void PrintIsVPS(char * ps)
{
	int result;
	int i;
	int sum;	// 괄호 열릴때 더하고, 괄호 닫힐때 빼는 변수
				// 중간에 음수가 되면 안되고, 마지막에 0이어야 vps

	result = 0;
	i = 0;

	sum = 0;

	while (1)
	{
		switch (ps[i])
		{
			case '(' :
				sum++;
				break;
			case ')' :
				sum--;
				break;
		}

		// 괄호가 열리기 전에 닫혀 false
		if (sum < 0)
		{
			break;
		}

		// 문자열 끝
		if (ps[i] == '\0')
		{
			break;
		}

		i++;
	}

	// 문자열 끝까지 읽고, sum이 0일 때 true
	if (ps[i] == '\0' && sum == 0)
	{
		result = 1;
	}

	printf("%s\n", result ? "YES" : "NO");
}
