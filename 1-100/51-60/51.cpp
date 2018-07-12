#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

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

    for (int p = 3; p <= n; p += 2)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
}

void make_digits(int prime, std::vector<int>& digits)
{
    digits.push_back(prime % 10);
    while (prime /= 10)
    {
        digits.push_back(prime % 10);
    }
}

bool is_mega_prime(std::vector<int>& digs, std::vector<int>& perms, std::vector<int>& primes)
{
    static const std::vector<int> nums = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
    do
    {
        int total = 0;
        std::set<int> new_primes;
        for (auto num : nums)
        {
            auto temp_digs = digs;
            for (int i = 0; i < perms.size(); i++)
            {
                if (perms[i] == 1)
                {
                    temp_digs[i] = num;
                }
            }

            if (temp_digs[temp_digs.size() - 1] == 0)
            {
                continue;
            }

            int new_prime = 0;
            for (int i = 0; i < temp_digs.size(); i++)
            {
                new_prime += temp_digs[i] * (int)std::pow(10, i);
            }

            if (std::binary_search(primes.begin(), primes.end(), new_prime))
            {
                new_primes.emplace(new_prime);
                total++;
            }
        }

        if (total == 8)
        {
            for (auto it = digs.rbegin() ; it != digs.rend() ; it++)
            {
                std::cout << *it;
            }

            std::cout << std::endl << "--------------------" << std::endl;

            for (auto num : new_primes)
            {
                std::cout << num << std::endl;
            }

            std::cout << "--------------------" << std::endl;
            return true;
        }

    } while (std::next_permutation(std::begin(perms), std::end(perms)));

   return false;
}

int main()
{
    std::vector<int> primes;
    sieve_eratosthene(999999, primes);

    for (auto prime : primes)
    {
        std::vector<int> digits;
        make_digits(prime, digits); //  reversed , 103 - > 301

        for (int i = 0; i < digits.size() - 1; i++)
        {
            std::vector<int> perms;
            for (int j = 0; j <= i; j++)
            {
                perms.push_back(1);
            }

            while (perms.size() != digits.size())
            {
                perms.push_back(0);
            }

            std::sort(perms.begin(), perms.end());
            if (is_mega_prime(digits, perms, primes))
            {
                return 0;
            }
        }
    }

    return 0;
}
