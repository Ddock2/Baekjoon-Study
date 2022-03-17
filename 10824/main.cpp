#include <iostream>
#include <string>

using namespace std;

int main()
{	
	int num1;
	int num2;
	int num3;
	int num4;

	string tmpStr1;
	string tmpStr2;
	long long result;

	cin >> num1;
	cin >> num2;
	cin >> num3;
	cin >> num4;

	tmpStr1 = to_string(num1) + to_string(num2);
	tmpStr2 = to_string(num3) + to_string(num4);

	result = stoll(tmpStr1) + stoll(tmpStr2);

	cout << result << endl;

	return 0;
}
