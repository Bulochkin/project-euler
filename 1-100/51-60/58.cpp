#include <iostream>
#include <vector>
#include <algorithm>

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

    for (int p = 3; p <= n; p ++)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
}

int main()
{
    const int total = 15000;
    std::vector<int> primes;
    
    int i = 0;
    sieve_eratosthene(total, primes);

    int aaa = 5;
    float count = 0;
    for (int shift = 2, start = 1; i < total / 2; i++, shift += 2)
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

        float diff = count / aaa;
        if (diff < 0.1f)
        {
            std::cout << i * 2 + 1<< " | diff = " << diff << std::endl;
            break;
        }

        aaa += 4;
    }

    return 0;
}
