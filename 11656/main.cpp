#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{	
	string input;
	int inputLenght;
	string tmp[1000];
	int i;

	cin >> input;
	inputLenght = input.length();

	for (i = 0; i < inputLenght; i++)
	{
		tmp[i] = input.substr(i, inputLenght - i);
	}

	sort(tmp, tmp + inputLenght);

	for (i = 0; i < inputLenght; i++)
	{
		cout << tmp[i] << endl;
	}

	return 0;
}
