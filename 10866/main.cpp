#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{	
	int n;
	string command;
	int number;
	deque<int> d;

	cin >> n;

	while (n--)
	{
		cin >> command;

		if (command.compare("push_front") == 0)
		{
			cin >> number;
			d.push_front(number);
		}
		else if (command.compare("push_back") == 0)
		{
			cin >> number;
			d.push_back(number);
		}
		else if (command.compare("pop_front") == 0)
		{
			if (!d.empty())
			{
				cout << d.front() << endl;
				d.pop_front();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (command.compare("pop_back") == 0)
		{
			if (!d.empty())
			{
				cout << d.back() << endl;
				d.pop_back();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (command.compare("size") == 0)
		{
			cout << d.size() << endl;
		}
		else if (command.compare("empty") == 0)
		{
				cout << d.empty() << endl;
		}
		else if (command.compare("front") == 0)
		{
			if (!d.empty())
			{
				cout << d.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (command.compare("back") == 0)
		{
			if (!d.empty())
			{
				cout << d.back() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}

	return 0;
}
