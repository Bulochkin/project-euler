#include <iostream>
#include <vector>
#include <algorithm>

void digits(int num, std::vector<int>& digs)
{
    if (num == 0)
        return;

    digs.push_back(num % 10);
    digits(num / 10, digs);
}

int main()
{
    long sum = 0;
    std::vector<int> digs;
    for (long i = 2; i < 1000000; i++)
    {
        digs.clear();
        digits(i, digs);

        auto sum_cmp = 0;
        for (auto d : digs)
        {
            sum_cmp += (int)std::pow(d, 5);
        }

        if (sum_cmp == i)
        {
            sum += sum_cmp;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
