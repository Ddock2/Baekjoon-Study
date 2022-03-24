#include <iostream>

using namespace std;

int CalcGCD(int a, int b);
int CalcLCM(int a, int b);

int main()
{	
	int number;
	int num1, num2;
	int tmp;

	cin >> number;

	while (number--)
	{
		cin >> num1 >> num2;

		cout << CalcLCM(num1, num2) << endl;
	}

	return 0;
}

int CalcGCD(int a, int b)
{
	return b ? CalcGCD(b, a % b) : a;
}

int CalcLCM(int a, int b)
{
	return a * b / CalcGCD(a, b);
}
