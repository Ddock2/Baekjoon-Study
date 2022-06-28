#include <iostream>
#include <string>

using namespace std;


int main()
{
	int input;
	int devideNum;

	devideNum = 2;
	
	cin >> input;

	while (input >= devideNum)
	{
		if (input % devideNum == 0)
		{
			input /= devideNum;
			cout << devideNum << endl;
		}
		else
		{
			devideNum++;
		}
	}
	
	return 0;
}
