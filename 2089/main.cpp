#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	stack<int> result;

	cin >> n;

	if (n == 0)
	{
		cout << "0";
	}
	else
	{
		while (n != 0)
		{
			if (n % -2 == 0)
			{
				result.push(0);
				n /= -2;
			}
			else
			{
				result.push(1);
				n = (n - 1) / -2;
			}
		}
	}

	while (!result.empty())
	{
		cout << result.top();
		result.pop();
	}

	cout << endl;
	return 0;
}
