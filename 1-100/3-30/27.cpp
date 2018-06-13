#include <iostream>
#include <vector>
#include <tuple>

void sieve_eratosthene(const int n, std::vector<int>& primes)
{
	std::vector<bool> prime(n + 1);
	std::fill(prime.begin(), prime.end(), 1);

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

int main()
{
	constexpr int n1 = 1000;
	std::vector<int> primes1000;

	sieve_eratosthene(n1, primes1000);

	std::tuple<int, int, int> tmax(0, 0, 0);
	for (auto a = -63; a <= 63; a++)
	{
		for (auto b : primes1000)
		{
			int max = 0;
			for (auto i = 0; ; i++, max++)
			{
				auto n = i * i + a * i + b;
				auto pos = std::find(primes1000.begin(), primes1000.end(), i * i + a * i + b);
				if (pos == primes1000.end())
				{
					break;
				}
			}
			if (max > std::get<0>(tmax))
			{
				tmax = std::make_tuple(max, a, b);
			}
		}
	}

	std::cout << "max = " << std::get<0>(tmax) << " a = " << std::get<1>(tmax) << " b = " << std::get<2>(tmax) << std::endl;
	std::cout << "res = " << std::get<1>(tmax) * std::get<2>(tmax) << std::endl;

	return 0;
}
