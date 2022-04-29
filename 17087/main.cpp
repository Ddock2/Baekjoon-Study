#include <iostream>
#include <vector>

using namespace std;

int GetGCD(int a, int b);

int main()
{
	int n;									// 동생 수
	long long startPosition;				// 시작위치
	vector<long long> relativePositions;	// 동생들 상대적 위치

	int i;
	long long tmp;
	long long result;
	
	cin >> n >> startPosition;

	relativePositions.reserve(n);

	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		tmp = (tmp <= startPosition) ? startPosition - tmp : tmp - startPosition;
		relativePositions.push_back(tmp);
	}

	result = relativePositions[0];

	for (i = 0; i < n; i++)
	{
		result = GetGCD(result, relativePositions[i]);
	}

	cout << result << endl;

	return 0;
}

int GetGCD(int a, int b)
{
	int small, big;
	int remainder;
	int result;

	if (a >= b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}

	remainder = big % small;

	if (remainder == 0)
	{
		result = small;
	}
	else
	{
		result = GetGCD(small, remainder);
	}

	return result;
}
