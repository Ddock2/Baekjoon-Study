#include <iostream>
#include <string>
#include <stack>

using namespace std;

string ConvertNumber(int b, int baseNum);

int main()
{
	int inputNum;
	int b;
	
	cin >> inputNum;
	cin >> b;

	cout << ConvertNumber(b, inputNum) << endl;

	return 0;
}

string ConvertNumber(int b, int baseNum)
{
	string convertNum;
	stack<int> tmp;

	while (baseNum / b != 0)
	{
		tmp.push(baseNum % b);
		baseNum /= b;
	}
	
	tmp.push(baseNum);

	while (!tmp.empty())
	{
		if (tmp.top() < 10)
		{
			convertNum += (char)(48 + tmp.top());
		}
		else
		{
			convertNum += (char)(55 + tmp.top());
		}

		tmp.pop();
	}

	return convertNum;
}