#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

void MakeOutput(int base, int decimalValue, stack<int> *output);

int main()
{
	int futureNum;	// A
	int nowNum;		// B

	int m;

	int tmp;
	int inputDecimal;
	stack<int> output;


	inputDecimal = 0;

	cin >> futureNum >> nowNum;

	cin >> m;

	// convert input to decimal value
	while (m-- > 0)
	{
		cin >> tmp;

		inputDecimal += pow(futureNum, m) * tmp;
	}

	// convert decimal to output value
	MakeOutput(nowNum, inputDecimal, &output);
	
	// print output
	while (!output.empty())
	{
		cout << output.top() << " ";
		output.pop();
	}

	return 0;
}

void MakeOutput(int base, int decimalValue, stack<int> *output)
{
	if (decimalValue / base == 0)
	{
		output->push(decimalValue);
	}
	else
	{
		output->push(decimalValue % base);
		MakeOutput(base, decimalValue / base, output);
	}
}