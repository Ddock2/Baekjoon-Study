#include <iostream>

using namespace std;

// nCm = n! / ((n-m)! * m!)

// ���μ� �� 2�� 5 ������ ���� ���ڸ� 0 ����

// [n! 2 ����] - [(n-m)! 2 ����] - [m! 2 ����]
// [n! 5 ����] - [(n-m)! 5 ����] - [m! 5 ����]

// �� ��� �� �� ���� ��

long long CountPrimeFromFactorial(int primeNumber, long long factorialNumber);

int main() {
	long long n, m;
	long long twoResult;
	long long fiveResult;
	long long output;

	long long nFacPrimeTwo;		// n! ���μ� 2����
	long long n_mFacPrimeTwo;	// (n-m)! ���μ� 2���� 
	long long mFacPrimeTwo;		// m! ���μ� 2����

	long long nFacPrimeFive;		// n! ���μ� 5����
	long long n_mFacPrimeFive;		// (n-m)! ���μ� 5���� 
	long long mFacPrimeFive;		// m! ���μ� 5����

	cin >> n >> m;

	nFacPrimeTwo = CountPrimeFromFactorial(2, n);
	n_mFacPrimeTwo = CountPrimeFromFactorial(2, n - m);
	mFacPrimeTwo = CountPrimeFromFactorial(2, m);
	
	nFacPrimeFive = CountPrimeFromFactorial(5, n);
	n_mFacPrimeFive = CountPrimeFromFactorial(5, n-m);
	mFacPrimeFive = CountPrimeFromFactorial(5, m);

	twoResult = nFacPrimeTwo - n_mFacPrimeTwo - mFacPrimeTwo;
	fiveResult = nFacPrimeFive - n_mFacPrimeFive - mFacPrimeFive;

	output = twoResult < fiveResult ? twoResult : fiveResult;

	cout << output << endl;

	return 0;
}

long long CountPrimeFromFactorial(int primeNumber, long long factorialNumber)
{
	long long result;
	long long i;

	result = 0;

	for (i = primeNumber; i <= factorialNumber; i *= primeNumber)
	{
		result += factorialNumber / i;
	}

	return result;
}
