#include <iostream>
#include <vector>
#include <algorithm>

void sieve_eratosthene_goldbach(const int n)
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
        if (!prime[p])
        {
            bool is_Goldbach = false;
            for (int n = 3; n < p; n+= 2)
            {
                if (prime[n])
                {
                    int cmp1 = (p - n) / 2;
                    int cmp2 = (int)std::sqrt(cmp1);

                    if (cmp2 * cmp2 == cmp1)
                    {
                        is_Goldbach = true;
                        break;
                    }
                }
            }

            if (!is_Goldbach)
            {
                std::cout << p << std::endl;
                break;
            }
        }
    }
}

int main()
{
    const int size = 10000;
    sieve_eratosthene_goldbach(size);

    return 0;
}
