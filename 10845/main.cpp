#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{	
	int remainCommandNumber;
	string command;
	int number;
	queue<int> q;

	// 명령어 수 입력
	cin >> remainCommandNumber;

	while (remainCommandNumber--)
	{
		cin >> command;

		if (command.compare("push") == 0)
		{
			cin >> number;
			q.push(number);
		}
		else if (command.compare("pop") == 0)
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (command.compare("size") == 0)
		{
			cout << q.size() << endl;
		}
		else if (command.compare("empty") == 0)
		{
			cout << q.empty() << endl;
		}
		else if (command.compare("front") == 0)
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.front() << endl;
			}
		}
		else if (command.compare("back") == 0)
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.back() << endl;
			}
		}
	}

	return 0;
}
