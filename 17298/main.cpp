#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{	
	int last;
	int i;
	vector<int> numberList;		// input
	vector<int> answerList;		// output
	stack<int> tmpIndex;		// 오큰수를 찾지 못한 numberList index 모음
								// 마지막에 쌓인 수가 전보다 더 높은 수일 수 없으므로
								// 마지막 수의 오큰수여야 이전값들의 오큰수가 될 수 있음

	// input
	cin >> last;

	numberList.reserve(last);
	answerList.reserve(last);

	for(i = 0; i < last; i++)
	{
		cin >> numberList[i];
	}

	
	// set answerList (오큰수 찾기)
	for(i = 0; i < last; i++)
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
				if (!tmpIndex.empty() && numberList[tmpIndex.top()] < numberList[i])
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


// 시간초과
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//int main()
//{	
//	int sequenceSize;
//	int number;
//	int currentNumber;	// 오큰수를 구하려는 수
//	int nge;			// 오큰수
//	queue<int> q;
//	int i;
//	int remain;
//
//	cin >> sequenceSize;
//
//	for(i = 0; i < sequenceSize; i++)
//	{
//		cin >> number;
//		q.push(number);
//	}
//
//	while(q.size())
//	{
//		if (q.size() != sequenceSize) cout << ' ';
//
//		currentNumber = q.front();
//		q.pop();
//		nge = -1;
//
//		remain = q.size();
//
//		for (i = 0; i < remain; i++)
//		{
//			if (nge == -1 && currentNumber < q.front())
//				nge = q.front();
//			q.push(q.front());
//			q.pop();
//		}
//		
//		cout << nge;
//	}
//
//	return 0;
//}
