#include <iostream>

using namespace std;

int GetGCD(int a, int b);

int main()
{
	int t;
	int testCaseNumberCount;
	int testCaseNumberList[100];

	int i, j;
	long long output;
	
	cin >> t;

	while (t--)
	{
		output = 0;

		cin >> testCaseNumberCount;
		
		for (i = 0; i < testCaseNumberCount; i++)
		{
			cin >> testCaseNumberList[i];
		}

		for (i = 0; i < testCaseNumberCount; i++)
		{
			for (j = i + 1; j < testCaseNumberCount; j++)
			{
				output += GetGCD(testCaseNumberList[i], testCaseNumberList[j]);
			}
		}

		cout << output << endl;
	}


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
