#include <iostream>
#include <vector>
#include <algorithm>

void sieve_eratosthene(const long long n, std::vector<long long>& primes)
{
    std::vector<bool> prime(n + 1);
    std::fill(prime.begin(), prime.end(), 1);

    for (long long p = 2; p*p <= n; p++)
    {
        if (prime[p] == true)	// If prime[p] is not changed, then it is a prime
        {
            for (long long i = p * 2; i <= n; i += p)	// Update all multiples of p
                prime[i] = false;
        }
    }

    for (long long p = 3; p <= n; p ++)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
}

int main()
{
    const long long total = 900000000;
    std::vector<long long> primes;
    
    float count = 0;
    sieve_eratosthene(total, primes);
    for (long long i = 0, shift = 2, start = 1; i < total; i++, shift += 2)
    {
        start += shift;
        if (std::binary_search(primes.begin(), primes.end(), start))
        {
            count++;
        }
    
        start += shift;
        if (std::binary_search(primes.begin(), primes.end(), start))
        {
            count++;
        }

        start += shift;
        if (std::binary_search(primes.begin(), primes.end(), start))
        {
            count++;
        }

        start += shift;    
        if (std::binary_search(primes.begin(), primes.end(), start))
        {
            count++;
        }

        float diff = count / ((i + 1) * 4 + 1);
        if (diff < 0.1f)
        {
            std::cout << std::sqrt(start) << " | diff = " << diff << std::endl;
            return 0;
        }
    }

    return 0;
}
