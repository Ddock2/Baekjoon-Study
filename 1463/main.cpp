#include <iostream>
#include <string>

#define MAX_NUMBER 1000000

using namespace std;
int minCalcList[MAX_NUMBER + 1];

int main()
{
	int input;
	int i;

	cin >> input;

	minCalcList[1] = 0;
	for(i = 2; i <= input; i++)
	{
		minCalcList[i] = minCalcList[i - 1] + 1;

		if (i % 3 == 0)
		{
			minCalcList[i] = minCalcList[i] < minCalcList[i / 3] + 1 ? minCalcList[i] : minCalcList[i / 3] + 1;
		}

		if (i % 2 == 0)
		{
			minCalcList[i] = minCalcList[i] < minCalcList[i / 2] + 1 ? minCalcList[i] : minCalcList[i / 2] + 1;
		}
	}

	cout << minCalcList[input];
	
	return 0;
}
