#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{	
	int numberList[26];
	int number;
	string line;
	string convertLine;
	int i;

	stack<double> s;
	double tmp;

	// input
	cin >> number;
	cin >> line;
	for (i = 0; i < number; i++)
	{
		cin >> numberList[i];
	}

	// °è»ê
	for (i = 0; i < line.length(); i++)
	{
		if ('A' <= line[i] && line[i] <= 'Z')
		{
			s.push(numberList[line[i] - 'A']);
		}
		else
		{
			tmp = s.top();
			s.pop();

			switch (line[i])
			{
				case '+':
					tmp = s.top() + tmp;
					break;
				case '-':
					tmp = s.top() - tmp;
					break;
				case '*':
					tmp = s.top() * tmp;
					break;
				case '/':
					tmp = s.top() / tmp;
					break;
			}

			s.pop();
			s.push(tmp);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top() << endl;

	return 0;
}
