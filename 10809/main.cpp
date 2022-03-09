#include <iostream>
#include <string>

using namespace std;

int main()
{	
	string input;

	int charNumList['z' - 'a' + 1] = {-1, };
	int i;
	
	cin >> input;

	for (i = 0; i <= 'z' - 'a'; i++)
	{
		charNumList[i] = -1;
	}

	for (i = 0; i < input.length(); i++)
	{
		if (charNumList[input[i] - 'a'] == -1)
		{
			charNumList[input[i] - 'a'] = i;
		}
	}

	for (i = 0; i <= 'z' - 'a'; i++)
	{
		cout << charNumList[i] << ' ';
	}

	return 0;
}
