#include <iostream>
#include <string>

using namespace std;

int main()
{	
	string input;
	int plus;
	int i;
	
	getline(cin, input);

	for (i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			plus = (input[i] - 'a' + 13) % 26;
			cout << (char)('a' + plus);
		}
		else if (input[i] >= 'A' && input[i] <= 'Z')
		{
			plus = (input[i] - 'A' + 13) % 26;
			cout << (char)('A' + plus);
		}
		else
		{
			cout << input[i];
		}
	}

	return 0;
}
