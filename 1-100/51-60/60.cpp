#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

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

bool is_pair(const std::vector<long long>& primes, long long i1, long long i2)
{
    std::string&& s1 = std::to_string(i1);
    std::string&& s2 = std::to_string(i2);

    return  std::binary_search(primes.begin() , primes.end() , std::stoll(s1 + s2)) &&
            std::binary_search(primes.begin() , primes.end() , std::stoll(s2 + s1));
}

void run_intersections3(const std::vector<long long>& primes, std::vector<std::vector<long long>>& pairs_all)
{
    std::vector<std::vector<long long>> pairs_new;
    for (auto it1 = pairs_all.begin(); it1 != pairs_all.end(); it1++)
    {
        for (auto it2 = it1->begin() + 2; it2 != it1->end(); it2++)
        {
            for (auto it3 = it2 + 1; it3 != it1->end(); it3++)
            {
                for (auto it4 = it3 + 1; it4 != it1->end(); it4++)
                {
                    if (is_pair(primes, *it2, *it3) && is_pair(primes, *it3, *it4) && is_pair(primes, *it2, *it4))
                    {
                        pairs_new.push_back({ it1->operator[](0), it1->operator[](1), *it2, *it3, *it4});
                    }
                }
            }
        }
    }
    pairs_all = std::move(pairs_new);
}

void run_intersections(std::vector<std::vector<long long>>& pairs_all)
{
    std::vector<std::vector<long long>> pairs_new;
    for (auto it1 = pairs_all.begin(); it1 != pairs_all.end(); it1++)
    {
        for (auto it2 = it1 + 1; it2 != pairs_all.end(); it2++)
        {
            std::vector<long long> pairs_one;

            if (std::binary_search(it1->begin(), it1->end(), it2->operator[](0)))
            {
                pairs_one.push_back(it1->operator[](0));
                pairs_one.push_back(it2->operator[](0));

                std::set_intersection(it1->begin() + 1, it1->end(), it2->begin() + 1, it2->end(), std::back_inserter(pairs_one));

                if (pairs_one.size() > 4)
                {
                    pairs_new.push_back(pairs_one);
                }
            }
        }
    }
    pairs_all = std::move(pairs_new);
}

int main()
{
    const int border = 10000;
    const int total = 100000000;

    std::vector<long long> primes;
    primes.reserve(total / 5);

    sieve_eratosthene(total, primes);

    std::vector<std::vector<long long>> pairs_all;
    pairs_all.reserve(border / 5);

    for (auto it1 = primes.begin(); *it1 < border; it1++)
    {
        std::vector<long long> pairs = { *it1 };
        pairs.reserve(border / 100);

        for (auto it2 = it1 + 1; *it2 < border; it2++)
        {
            if (is_pair(primes, *it1, *it2))
            {
                pairs.push_back(*it2);
            }
        }
        pairs_all.push_back(pairs);
    }

    run_intersections(pairs_all);    
    run_intersections3(primes, pairs_all);

    for (auto& combination : pairs_all)
    {
        for (auto d : combination)
        {
            std::cout << d << "\t";
        }
        std::cout << "| sum = " << std::accumulate(combination.begin(), combination.end(), 0LL) << std::endl;
    }

    return 0;
}
