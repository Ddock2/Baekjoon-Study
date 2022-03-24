#include <iostream>

using namespace std;

int main()
{	
	int num1, num2;
	int result1;	// 최대공약수
	int result2;	// 최소공배수

	int small;
	int big;

	cin >> num1 >> num2;

	small = num1 <= num2 ? num1 : num2;
	big = num1 >= num2 ? num1 : num2;

	result1 = small;

	// 최대공약수
	while (result1 > 1)
	{
		if (small % result1 == 0)
		{
			if (big % result1 == 0)
			{
				break;
			}
		}

		result1--;
	}

	// 최소공배수
	result2 = num1 * num2 / result1;


	cout << result1 << endl << result2 << endl;
	return 0;
}
