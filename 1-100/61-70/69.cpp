#include <iostream>

int phi(int n)
{
    float result = (float)n;

   // Consider all prime factors of n and for every prime
   // factor p, multiply result with (1 - 1/p)
    for (int p = 2; p * p <= n; ++p) 
    {
        // Check if p is a prime factor.
        if (n % p == 0) 
        {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result *= (1.0f - (1.0f / (float)p));
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result *= (1.0f - (1.0f / (float)n));

    return (int)std::round(result);
}

int main()
{
    float max = 0.;
    for (int n = 2; n <= 1000000; n++)
    {
        int p = phi(n);
        float np = (float)n / (float)p;

        if (np > max)
        {
            max = np;
            std::cout << n << "\t|\t" << max << std::endl;
        }
    }

    return 0;
}
