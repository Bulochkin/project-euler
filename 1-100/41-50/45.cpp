#include <iostream>
#include <limits>

bool is_pentagonal(long long num)
{
    double x = (std::sqrt(1.0 + 24 * num) + 1) / 6;
    return (x - floor(x)) < std::numeric_limits<double>::epsilon();
}

int main()
{
    for (auto i = 144; ; i++)
    {
        long long hex = i * (2 * i - 1);
        if (is_pentagonal(hex))
        {
            std::cout << hex << std::endl;
            break;
        }
    }
    return 0;
}
