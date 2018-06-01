#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

constexpr int n = 1000000;
static bool prime[n + 1];

void SieveOfEratosthenes()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	memset(prime, true, sizeof(prime));
	for (int p = 2; p*p <= n; p++)
	{
		
		if (prime[p] == true)	// If prime[p] is not changed, then it is a prime
		{
			for (int i = p * 2; i <= n; i += p)	// Update all multiples of p
				prime[i] = false;
		}
	}

	int currentIndex = 0;
	for (int p = 2; p <= n; p++)
	{
		if (prime[p])
		{
			currentIndex++;
			if (currentIndex == 10001)
			{
				std::cout << currentIndex << " | " << p << std::endl;
			}
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	std::cout << "time = " << fp_ms.count() << std::endl;
}

// Driver Program to test above function
int main()
{
	SieveOfEratosthenes();
	return 0;
}
