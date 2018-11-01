#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

int sum_of_divisors(int num)
{
    int sum = 1;
    int sqr = (int)std::sqrt(num);
    for (int i = 2; i < sqr; i++)
    {
        if (num % i == 0)
        {
            sum += i;
            sum += (num / i);
        }
    }

    if (sqr * sqr == num && num != 1)
    {
        sum += sqr;
    }

    return sum;
}

int main()
{
    std::vector<int> chainGlobal;
    for (int i = 3; i < 1000000; i++)
    {
        std::vector<int> chain = { i };
        int sum = sum_of_divisors(i);

        while (chain[0] != sum)
        {
            if (sum >= 1000000 || std::find(chain.begin(), chain.end(), sum) != chain.end())
            {
                chain.clear();
                break;
            }

            chain.emplace_back(sum);
            sum = sum_of_divisors(sum);
        }

        if (chain.size() > chainGlobal.size())
        {
            chainGlobal = chain;
            for (auto num : chainGlobal)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl << std::endl;
        }
    }

    std::sort(chainGlobal.begin(), chainGlobal.end());
    std::cout << chainGlobal[0] << std::endl;

    return 0;
}
