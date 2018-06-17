#include <iostream>
#include <vector>
#include <set>

bool truncatable_prime(int prime, const std::set<int>& primes)
{
    if (prime < 10)
    {
        return false;
    }

    int digits = 1;
    int temp = prime;
    while (temp /= 10)
    {
        digits++;
        if (primes.find(temp) == primes.end())
        {
            return false;
        }
    }

    while (digits > 1)
    {
        prime %= (decltype(prime))std::pow(10, --digits);
        if (primes.find(prime) == primes.end())
        {
            return false;
        }
    }

    return true;
}

bool not_468(int n)
{
    while (n > 0)
    {
        int div = n % 10;
        if (div == 4 || div == 6 || div == 8)
            return false;
        n /= 10;
    }
    return true;
}

void sieve_eratosthene(const int n, std::set<int>& primes)
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

    for (int p = 2; p <= n; p++)
    {
        if (prime[p] && not_468(p))
        {
            primes.emplace(p);
        }
    }
}

int main()
{
    std::set<int> primes;
    sieve_eratosthene(1000000, primes);

    int sum = 0;
    for (auto prime : primes)
    {
        if (truncatable_prime(prime, primes))
        {
            sum += prime;
            std::cout << prime << std::endl;
        }
    }

    std::cout << std::endl << sum << std::endl;
    return 0;
}
