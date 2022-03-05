#include <iostream>
#include <string>

using namespace std;

int main()
{	
	string input;

	int charNumList['z' - 'a' + 1] = {0};
	int i;
	
	cin >> input;

	for (i = 0; i < input.length(); i++)
	{
		charNumList[input[i] - 'a']++;
	}

	for (i = 0; i <= 'z' - 'a'; i++)
	{
		cout << charNumList[i] << ' ';
	}

	return 0;
}
