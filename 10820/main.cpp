#include <iostream>
#include <string>

using namespace std;

int main()
{	
	string input;

	int lowerNumber;
	int upperNumber;
	int numberNumber;
	int spaceNumber;
	int i;

	while (getline(cin, input))
	{
		lowerNumber = 0;
		upperNumber = 0;
		numberNumber = 0;
		spaceNumber = 0;

		for (i = 0; i < input.length(); i++)
		{
			if ('a' <= input[i] && input[i] <= 'z')
			{
				lowerNumber++;
			}
			else if ('A' <= input[i] && input[i] <= 'Z')
			{
				upperNumber++;
			}
			else if ('0' <= input[i] && input[i] <= '9')
			{
				numberNumber++;
			}
			else if (' ' == input[i])
			{
				spaceNumber++;
			}
		}

		cout << lowerNumber << ' ' << upperNumber << ' ' << numberNumber << ' ' << spaceNumber << endl;
	}

	return 0;
}
