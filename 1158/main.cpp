#include <iostream>
#include <queue>

using namespace std;

int main()
{	
	int n, k;
	int i;
	queue<int> q;

	cin >> n;
	cin >> k;

	for (i = 1; i <= n; i++)
	{
		q.push(i);
	}

	cout << "<";

	while (1)
	{
		for (i = 1; i < k; i++)
		{
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		q.pop();

		if (q.empty())
		{
			break;
		}
		else
		{
			cout << ", ";
		}
	}

	cout << ">";

	return 0;
}
