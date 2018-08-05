#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

int phi(int n)
{
    float result = (float)n;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result *= (1.0f - (1.0f / (float)p));
        }
    }

    if (n > 1)
        result *= (1.0f - (1.0f / (float)n));

    return (int)std::round(result);
}

int main()
{
    int num;
    float min = std::numeric_limits<float>::max();
    for (int i = 2; i < 10000000; i++)
    {
        int p = phi(i);

        std::string s1 = std::to_string(p);
        std::string s2 = std::to_string(i);

        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        if (s1 == s2)
        {
            float np = (float)i / (float)p;
            if (np < min)
            {
                min = np;
                num = i;
            }
        }
    }

    std::cout << num << " | " << min << std::endl;
    return 0;
}
