#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

constexpr long long n = 2000000 - 1;
static bool prime[n + 1];

void SieveOfEratosthenes()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	memset(prime, true, sizeof(prime));
	for (long long p = 2; p*p <= n; p++)
	{
		if (prime[p] == true)	// If prime[p] is not changed, then it is a prime
		{
			for (long long i = p * 2; i <= n; i += p)	// Update all multiples of p
				prime[i] = false;
		}
	}

	long long totalSum = 0;
	for (long long p = 2; p <= n; p++)
	{
		if (prime[p])
		{
			totalSum += p;
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	std::cout << "time = " << fp_ms.count() << std::endl;
	std::cout << "result = " << totalSum << std::endl;
}

// Driver Program to test above function
int main()
{
	SieveOfEratosthenes();
	return 0;
}
