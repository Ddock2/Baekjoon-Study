#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER	100000

class Stack
{
private:
	int values[MAX_NUMBER];
	int valuesNumber;			// 스택에 들어있는 정수 개수

public:
	void Init()
	{
		memset(values, 0, sizeof(values));
		valuesNumber = 0;
	}

	void Push(int number)
	{
		values[valuesNumber++] = number;
	}

	int Pop()
	{
		if (valuesNumber == 0)
		{
			return -1;
		}
		else
		{
			return values[--valuesNumber];
		}
	}

	int GetStackNumber()
	{
		return valuesNumber;
	}

	int GetLastValue()
	{
		return values[valuesNumber - 1];
	}
};

class StackManager
{
private :
	Stack stack;
	char commandList[2 * MAX_NUMBER];	// push, pop 사용 log
	int commandListNumber;				// push, pop 사용 횟수

public :
	void Init()
	{
		stack.Init();
		memset(commandList, 0, sizeof(commandList));
		commandListNumber = 0;
	}

	void Push(int number)
	{
		commandList[commandListNumber++] = '+';
		stack.Push(number);
	}

	int Pop()
	{
		commandList[commandListNumber++] = '-';
		return stack.Pop();
	}

	int GetStackNumber()
	{
		return stack.GetStackNumber();
	}

	int GetLastValue()
	{
		return stack.GetLastValue();
	}

	void PrintCommandList()
	{
		int i;
		for (i = 0; i < commandListNumber; i++)
		{
			printf("%c\n", commandList[i]);
		}
	}
};

int lastNumber;
int numberList[MAX_NUMBER];				// 입력된 수열

StackManager stackManager;

void Init();
int MakeStackCommandList();

int main()
{	
	Init();

	if (MakeStackCommandList() == 0)
	{
		stackManager.PrintCommandList();
	}
	else
	{
		printf("NO\n");
	}


	return 0;
}

void Init()
{
	int i;

	memset(numberList, 0, sizeof(numberList));
	stackManager.Init();

	// intput
	scanf("%d", &lastNumber);
	for (i = 0; i < lastNumber; i++)
	{
		scanf("%d", numberList + i);
	}
}

int MakeStackCommandList()
{
	int findIndex;
	int number;

	findIndex = 0;

	for (number = 1; number <= lastNumber; number++)
	{
		stackManager.Push(number);

		while (stackManager.GetLastValue() == numberList[findIndex])
		{
			stackManager.Pop();
			findIndex++;
			if (findIndex == lastNumber)
			{
				break;
			}
		}
	}

	if (stackManager.GetStackNumber() != 0)
	{
		return -1;
	}

	return 0;
}
