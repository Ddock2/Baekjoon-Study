#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ConvertDecimal(int b, string base);

int main()
{
	string input;
	int b;
	
	cin >> input;
	cin >> b;

	cout << ConvertDecimal(b, input) << endl;

	return 0;
}

int ConvertDecimal(int b, string base)
{
	int convertNum;
	int i;

	int digit;

	convertNum = 0;

	digit = base.length() - 1;

	for (i = 0; i < base.length(); i++)
	{
		if (base[i] >= 'A' && base[i] <= 'Z')
		{
			convertNum += pow(b, digit) * (base[i] - 'A' + 10);
		}
		else
		{
			convertNum += pow(b, digit) * (base[i] - '0');
		}

		digit--;
	}

	return convertNum;
}