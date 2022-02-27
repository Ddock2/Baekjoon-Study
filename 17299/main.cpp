#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define MAX_NUMBER 1000000


int main()
{	
	int last;
	int i;
	int *numberList;		// input
	int *convertValueList;	// �� ���ڸ��� ����Ƚ�� ���� list
	int *answerList;		// output
	stack<int> tmpIndex;	// ����ū���� ã�� ���� numberList index ����
							// �������� ���� ���� ������ �� ���� ���� �� �����Ƿ�
							// ������ ���� ����ū������ ���������� ����ū���� �� �� ����
	
	numberList = new int[MAX_NUMBER];
	convertValueList = new int[MAX_NUMBER];
	answerList = new int[MAX_NUMBER];

	cin >> last;

	for (i = 0; i < last; i++)
	{
		cin >> numberList[i];
		convertValueList[numberList[i]]++;
	}
	
	for (i = 0; i < last; i++)
	{
		answerList[i] = -1;

		if (tmpIndex.empty())
		{
			tmpIndex.push(i);
		}
		else
		{
			while (1)
			{
				if (!tmpIndex.empty() && convertValueList[numberList[tmpIndex.top()]] < convertValueList[numberList[i]])
				{
					answerList[tmpIndex.top()] = numberList[i];
					tmpIndex.pop();
					continue;
				}

				tmpIndex.push(i);
				break;
			}
		}
	}
	
	// print result
	cout << answerList[0];

	for (i = 1; i < last; i++)
	{
		cout << " " << answerList[i];
	}

	return 0;
}
