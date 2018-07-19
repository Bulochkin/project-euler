#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

    for (long long p = 3; p <= n; p++)
    {
        if (prime[p] && (p % 5 != 0))
        {
            primes.push_back(p);
        }
    }
}

bool is_pair(const std::vector<long long> primes, long long i1, long long i2)
{
    std::string&& s1 = std::to_string(i1);
    std::string&& s2 = std::to_string(i2);

    return  std::binary_search(primes.begin() , primes.end() , std::stoll(s1 + s2)) &&
            std::binary_search(primes.begin() , primes.end() , std::stoll(s2 + s1));
}

int main()
{
    const int border = 2000;
    const int total = 1000000;

    std::vector<long long> primes;
    sieve_eratosthene(total, primes);

    for (auto it1 = primes.begin() ; *it1 < border ; it1++)
    {
        std::vector<long long> pairs;
        for (auto it2 = it1; *it2 < border ; it2++)
        {
            if (pairs.empty())
            {
                for (auto it3 = it2; *it3 < border ; it3++)
                {
                    if (is_pair(primes, *it2, *it3))
                    {
                        pairs.push_back(*it2);
                        pairs.push_back(*it3);
                        break;
                    }
                }
            }
            else
            {
                if (std::find(pairs.begin(), pairs.end(), *it2) != pairs.end())
                {
                    continue;
                }

                bool is_ok = true;
                for (auto cand : pairs)
                {
                    if (!is_pair(primes, cand, *it2))
                    {
                        is_ok = false;
                        break;
                    }
                }

                if (is_ok)
                {
                    pairs.push_back(*it2);
                    if (pairs.size() == 4)
                    {
                        for (auto p : pairs)
                        {
                            std::cout << p << " ";
                        }
                        std::cout << std::endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
