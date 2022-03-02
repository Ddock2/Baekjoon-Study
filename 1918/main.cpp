#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{	
	string input;
	stack<char> tmp;
	int i;

	cin >> input;
	
	for (i = 0; i < input.length(); i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z')
		{
			cout << input[i];
		}
		else
		{
			if (input[i] == '(')
			{
				tmp.push(input[i]);
			}
			else if (input[i] == ')')
			{
				while (!tmp.empty() && tmp.top() != '(')
				{
					cout << tmp.top();
					tmp.pop();
				}
				tmp.pop();
			}
			else if (input[i] == '+' || input[i] == '-')
			{
				while (!tmp.empty() && tmp.top() != '(')
				{
					cout << tmp.top();
					tmp.pop();
				}
				tmp.push(input[i]);
			}
			else if (input[i] == '*' || input[i] == '/')
			{
				while (!tmp.empty() && (tmp.top() == '*' || tmp.top() == '/'))
				{
					cout << tmp.top();
					tmp.pop();
				}
				tmp.push(input[i]);
			}
		}
	}

	while (!tmp.empty())
	{
		cout << tmp.top();
		tmp.pop();
	}

	return 0;
}
