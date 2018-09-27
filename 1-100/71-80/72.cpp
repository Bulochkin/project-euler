#include <iostream>

int phi(int n)
{
    float result = (float)n;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n /= p;
            }

            result *= (1.0f - (1.0f / (float)p));
        }
    }

    if (n > 1)
    {
        result *= (1.0f - (1.0f / (float)n));
    }

    return (int)std::round(result);
}

int main()
{
    unsigned long long total = 0;
    for (int i = 1; i <= 1000000; i++)
    {
        total += phi(i);
    }

    std::cout << total - 1 << std::endl;
    return 0;
}
