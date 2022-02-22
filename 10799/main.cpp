#include <iostream>
#include <string>

using namespace std;

int main()
{	
	int result;				// ÃÑ Á¶°¢ ¼ö
	int ironStickNumber;	// ½×¿©ÀÖ´Â ¼è¸·´ë±â ¼ö
	string input;

	result = 0;
	ironStickNumber = 0;

	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			ironStickNumber++;
		}
		else
		{
			ironStickNumber--;

			if (input[i - 1] == '(')
			{
				result += ironStickNumber;
			}
			else
			{
				result++;
			}
		}
	}

	cout << result << endl;

	return 0;
}
