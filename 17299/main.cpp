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
	int *convertValueList;	// 각 숫자마다 등장횟수 저장 list
	int *answerList;		// output
	stack<int> tmpIndex;	// 오등큰수를 찾지 못한 numberList index 모음
							// 마지막에 쌓인 수가 전보다 더 높은 수일 수 없으므로
							// 마지막 수의 오등큰수여야 이전값들의 오등큰수가 될 수 있음
	
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
