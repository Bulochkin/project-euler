#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

    primes.push_back(2);
    for (int p = 3; p <= n; p += 2)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
}

int main()
{
    std::vector<int> primes;
    sieve_eratosthene(999999, primes);

    int max_total = 0, max_sum = 0;
    for (int i = 0; primes[i] < 999999 / 22; i++)
    {
        int total = 1;
        int sum = primes[i];
        for (int j = i + 1; primes[j] < 999999 / 22; j++)
        {
            total++;
            sum += primes[j];

            if (sum >= 1000000)
            {
                break;
            }
            
            if (std::binary_search(primes.begin(), primes.end(), sum))
            {
                if (total > max_total)
                {
                    max_sum = sum;
                    max_total = total;
                }
            }
        }
    }

    std::cout << max_sum << std::endl;
    return 0;
}
