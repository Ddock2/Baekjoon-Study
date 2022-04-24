#include <iostream>

using namespace std;

int main() {
	int input;
	int output;

	int mul5;
	int mul25;
	int mul125;

	cin >> input;

	mul5 = input / 5;
	mul25 = input / 25;
	mul125 = input / 125;

	output = mul5 + mul25 + mul125;

	cout << output << endl;

	return 0;
}