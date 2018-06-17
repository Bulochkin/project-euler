#include <iostream>
#include <vector>

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

    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
}

int countdigits(int N)
{
    int count = 0;
    while (N) {
        count++;
        N = N / 10;
    }
    return count;
}

bool cyclic_prime(int N, std::vector<int>& primes)
{
    int num = N;
    int n = countdigits(N);

    bool is_circular = true;
    while (1) 
    {
        int rem = num % 10;
        int div = num / 10;
        num = (int)(pow(10, n - 1)) * rem + div;

        if (std::find(primes.begin(), primes.end(), num) == primes.end())
        {
            is_circular = false;
            break;
        }

        if (num == N)
        {
            break;
        }
    }

    return is_circular;
}

int main()
{
    int circulars = 0;
    const int total = 999999;

    std::vector<int> primes;
    sieve_eratosthene(total, primes);

    for (auto prime : primes)
    {
        if (cyclic_prime(prime, primes))
        {
            circulars++;
        }
    }

    std::cout << circulars << std::endl;
    return 0;
}
