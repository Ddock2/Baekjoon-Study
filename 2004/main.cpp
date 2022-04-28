#include <iostream>

using namespace std;

// nCm = n! / ((n-m)! * m!)

// ¼ÒÀÎ¼ö Áß 2¿Í 5 Á¶ÇÕÀÇ ¼ö°¡ µÞÀÚ¸® 0 °¹¼ö

// [n! 2 °¹¼ö] - [(n-m)! 2 °¹¼ö] - [m! 2 °¹¼ö]
// [n! 5 °¹¼ö] - [(n-m)! 5 °¹¼ö] - [m! 5 °¹¼ö]

// À§ °á°ú µÑ Áß ÀÛÀº ¼ö

long long CountPrimeFromFactorial(int primeNumber, long long factorialNumber);

int main() {
	long long n, m;
	long long twoResult;
	long long fiveResult;
	long long output;

	long long nFacPrimeTwo;		// n! ¼ÒÀÎ¼ö 2°¹¼ö
	long long n_mFacPrimeTwo;	// (n-m)! ¼ÒÀÎ¼ö 2°¹¼ö 
	long long mFacPrimeTwo;		// m! ¼ÒÀÎ¼ö 2°¹¼ö

	long long nFacPrimeFive;		// n! ¼ÒÀÎ¼ö 5°¹¼ö
	long long n_mFacPrimeFive;		// (n-m)! ¼ÒÀÎ¼ö 5°¹¼ö 
	long long mFacPrimeFive;		// m! ¼ÒÀÎ¼ö 5°¹¼ö

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
