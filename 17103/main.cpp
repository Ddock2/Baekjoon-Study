#include <iostream>
#include <cstring>
using namespace std;

#define MAX_NUMBER 1000000

int main()
{
	int t, n, r;
	bool prime[MAX_NUMBER + 1];

	memset(prime, 0, sizeof(prime));
	
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= MAX_NUMBER; i++)
	{
		prime[i] = true;
	}

	// 소수 구하기
	for (int i = 2; i * i <= MAX_NUMBER; i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * 2; j <= MAX_NUMBER; j += i)
			{
				prime[j] = false;
			}
		}
	}

	cin >> t;

	while (t--)
	{
		cin >> n;
		r = 0;

		for (int i = 2; i <= n / 2; i++)
		{
			if (prime[i] == true && prime[n - i] == true)
			{
				r++;
			}
		}

		cout << r << endl;
	}

	return 0;
}
