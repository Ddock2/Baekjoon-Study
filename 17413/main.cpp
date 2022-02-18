#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;
void PrintStack();

int main()
{	
	string str;
	int strLen;
	int i;

	getline(cin, str);
	strLen = str.length();
	
	for (i = 0; i < strLen; i++)
	{
		if (str[i] == '<')
		{
			PrintStack();

			for (i = i; i < strLen; i++)
			{
				cout << str[i];
				if (str[i] == '>')
				{
					break;
				}
			}
		}
		else if(str[i] == ' ')
		{
			PrintStack();
			cout << ' ';
		}
		else
		{
			s.push(str[i]);
		}
	}

	PrintStack();

	return 0;
}

void PrintStack()
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
