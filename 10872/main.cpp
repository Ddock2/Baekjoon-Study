#include <iostream>

using namespace std;

int main() {
	int input;
	int output;

	cin >> input;
	output = 1;

	for (int i = 1; i <= input; i++)
	{
		output *= i;
	}

	cout << output << endl;

	return 0;
}