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
	scanf("%c", inputBuffer);		// input buffer�� ����ִ� ���๮�ڸ� ����

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
	int sum;	// ��ȣ ������ ���ϰ�, ��ȣ ������ ���� ����
				// �߰��� ������ �Ǹ� �ȵǰ�, �������� 0�̾�� vps

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

		// ��ȣ�� ������ ���� ���� false
		if (sum < 0)
		{
			break;
		}

		// ���ڿ� ��
		if (ps[i] == '\0')
		{
			break;
		}

		i++;
	}

	// ���ڿ� ������ �а�, sum�� 0�� �� true
	if (ps[i] == '\0' && sum == 0)
	{
		result = 1;
	}

	printf("%s\n", result ? "YES" : "NO");
}
