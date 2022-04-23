#include <iostream>

using namespace std;

#define MAX_NUMBER 1000000

int main() {
	bool *prime;
	int input;
	int n1, n2;

	prime = new bool[MAX_NUMBER + 1];

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

	while (true)
	{
		cin >> input;

		if (input == 0) break;

		n1 = 3;
		n2 = input - 3;

		while (n1 <= n2)
		{
			if (prime[n1] && prime[n2])
			{
				if (n1 + n2 == input)
				{
					break;
				}
			}

			n1 += 2;
			n2 -= 2;
		}

		if (n1 <= n2)
		{
			cout << input << " = " << n1 << " + " << n2 << endl;
		}
		else
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}
			
	}

	return 0;
}