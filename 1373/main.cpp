#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int inputLength;
	int i;

	cin >> input;

	inputLength = input.length();
	i = 0;
	
	switch (inputLength % 3)
	{
	case 1:
		cout << input[i++];
		break;
	case 2:
		cout << (((input[i++] == '0' ? 0 : 1) * 2) + (input[i++] == '0' ? 0 : 1));
		break;
	default :
		break;
	}

	for (; i < inputLength; )
	{
		cout << (((input[i++] == '0' ? 0 : 1) * 4) + ((input[i++] == '0' ? 0 : 1) * 2) + (input[i++] == '0' ? 0 : 1));
	}

	cout << endl;

	return 0;
}
