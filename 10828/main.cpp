#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH	6
#define MAX_COMMAND_NUMBER	10000
#define MAX_STACK_SIZE		10000

enum command
{
	push,		// ���� X�� ���ÿ� �ִ� �����̴�.
	pop,		// ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
	size,		// ���ÿ� ����ִ� ������ ������ ����Ѵ�.
	empty,		// ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	top			// ������ ���� ���� �ִ� ������ ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�
};

class Stack
{
private :
	int values[MAX_STACK_SIZE];
	int valuesNumber;			// ���ÿ� ����ִ� ���� ����

public:
	void Init()
	{
		valuesNumber = 0;
	}

	void Push(int number)
	{
		values[valuesNumber++] = number;
	}

	void Pop()
	{
		if (valuesNumber == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", values[--valuesNumber]);
		}
	}

	void Size()
	{
		printf("%d\n", valuesNumber);
	}

	void Empty()
	{
		if (valuesNumber == 0)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}

	void Top()
	{
		if (valuesNumber == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", values[valuesNumber - 1]);
		}
	}
};

Stack stack;

enum command commandList[MAX_COMMAND_NUMBER];
int commandListNumber;
int pushValueList[MAX_COMMAND_NUMBER];
int pushValueListNumber;

void GetCommands(int commandNumber);
void ExecuteCommands();

int main()
{
	int commandNumber;

	// initialize stack
	stack.Init();

	// input command's number
	scanf("%d", &commandNumber);

	GetCommands(commandNumber);
	
	// execute command
	ExecuteCommands();
	
	return 0;
}

void GetCommands(int commandNumber)
{
	char commandBuffer[MAX_COMMAND_LENGTH];
	int pushValue;

	commandListNumber = 0;
	pushValueListNumber = 0;

	while (commandNumber--)
	{
		memset(commandBuffer, 0, sizeof(commandBuffer));
		scanf("%s", commandBuffer);

		if (!strncmp(commandBuffer, "push", 4))
		{
			memset(commandBuffer, 0, sizeof(commandBuffer));
			scanf("%d", &pushValue);

			commandList[commandListNumber++] = push;
			pushValueList[pushValueListNumber++] = pushValue;
		}
		else if (!strcmp(commandBuffer, "pop"))
		{
			commandList[commandListNumber++] = pop;
		}
		else if (!strcmp(commandBuffer, "size"))
		{
			commandList[commandListNumber++] = size;
		}
		else if (!strcmp(commandBuffer, "empty"))
		{
			commandList[commandListNumber++] = empty;
		}
		else if (!strcmp(commandBuffer, "top"))
		{
			commandList[commandListNumber++] = top;
		}
		else
		{
			//printf("invalid input format : %s\n", commandBuffer);
		}
	}

	return;
}

void ExecuteCommands()
{
	int * pushValue;
	int i;

	pushValue = pushValueList;

	for (i = 0; i < commandListNumber; i++)
	{
		switch (commandList[i])
		{
		case push :
			stack.Push(*pushValue);
			pushValue++;
			break;
		case pop :
			stack.Pop();
			break;
		case size:
			stack.Size();
			break;
		case empty:
			stack.Empty();
			break;
		case top:
			stack.Top();
			break;
		}
	}

	return;
}
