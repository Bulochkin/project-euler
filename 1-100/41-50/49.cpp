#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

    for (int p = 1489; p <= n; p+=2)
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
    sieve_eratosthene(9999, primes);

    for (int i = 0; i < primes.size() - 2; i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            int prime_next = primes[j] + primes[j] - primes[i];
            if (std::binary_search(primes.begin(), primes.end(), prime_next))
            {
                std::string s1 = std::to_string(primes[i]);
                std::sort(s1.begin(), s1.end());

                std::string s2 = std::to_string(primes[j]);
                std::sort(s2.begin(), s2.end());

                std::string s3 = std::to_string(prime_next);
                std::sort(s3.begin(), s3.end());

                if (s1 == s2 && s1 == s3)
                {
                    std::cout << primes[i] << primes[j] << prime_next << std::endl;
                }
            }
        }
    }

    return 0;
}
