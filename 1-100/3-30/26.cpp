#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

constexpr int n = 1000;
static bool prime[n + 1];

void sieve_eratosthene(const int n, std::vector<int>& primes)
{
	memset(prime, true, sizeof(prime));
	for (int p = 2; p*p <= n; p++)
	{
		if (prime[p] == true)	// If prime[p] is not changed, then it is a prime
		{
			for (int i = p * 2; i <= n; i += p)	// Update all multiples of p
				prime[i] = false;
		}
	}

	for (int p = 7; p <= n; p++)
	{
		if (prime[p])
		{
			primes.push_back(p);
		}
	}
}

constexpr int precision = 2000;

int main()
{
	std::vector<int> primes;
	std::multimap<size_t, int> maxs;

	int max = 0;
	sieve_eratosthene(n, primes);
	for (auto prime : primes)
	{
		auto start = 10;
		std::string divs;
		for (auto i = 1; i < precision; i++)
		{
			auto full = start / prime;
			auto rest = start % prime;

			divs += (full + '0');
			start = (rest == prime) ? start * 10 : rest * 10;
		}

		size_t to_push = 0;
		std::string reccure;
		std::reverse(divs.begin(), divs.end());
		for (auto i = 0; i < divs.length() / 2; i++)
		{
			reccure += divs[i];

			auto off = reccure.length();
			auto pos = divs.find(reccure, off);
			while (pos == off)
			{
				off += reccure.length();
				pos = divs.find(reccure, off);
			}

			auto sub = divs.substr(off);
			if (sub.length() && reccure.find(sub))
			{
				continue;
			}

			to_push = reccure.length();
			break;
		}

		maxs.emplace(to_push, prime);
	}

	std::cout << maxs.rbegin()->second << std::endl;
	return 0;
}
