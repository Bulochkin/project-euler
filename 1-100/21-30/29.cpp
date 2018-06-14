#include <iostream>
#include <cmath>
#include <set>
#include <vector>

int main()
{
    std::set<double> digits;

    for (auto i = 2; i <= 100; i++)
    {
        for (auto j = 2; j <= 100; j++)
        {
            digits.emplace(std::pow(i, j));
        }
    }

    std::cout << digits.size() << std::endl;
    return 0;
}
