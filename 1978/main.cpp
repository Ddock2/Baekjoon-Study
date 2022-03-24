#include <iostream>

using namespace std;

bool IsPrimeNumber(int n);

int main()
{	
	int number;
	int tmp;
	int result;

	result = 0;

	cin >> number;

	while (number--)
	{
		cin >> tmp;

		if (IsPrimeNumber(tmp))
		{
			result++;
		}
	}

	cout << result << endl;

	return 0;
}

bool IsPrimeNumber(int n)
{
	int tmp;

	if (n < 2)
	{
		return false;
	}

	tmp = n - 1;

	while (tmp > 1)
	{
		if (n % tmp-- == 0)
		{
			return false;
		}
	}

	return true;
}
