#include <iostream>
#include <vector>

const int factorials[] = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 };

void digits(int num, std::vector<int>& digs)
{
    while (num)
    {
        digs.emplace_back(num % 10);
        num /= 10;
    }
}

void process(int num, std::vector<int>& chain)
{
    std::vector<int> digs;
    digits(num, digs);

    int sum = 0;
    for (auto d : digs)
    {
        sum += factorials[d];
    }

    if (std::find(chain.begin(), chain.end(), sum) == chain.end())
    {
        chain.push_back(sum);
        process(sum, chain);
    }
}

int main()
{
    int total = 0;
    for (int i = 2; i < 1000000; i++)
    {
        std::vector<int> chain;
        process(i, chain);

        if (chain.size() == 60 - 1)
        {
            total++;
        }
    }

    std::cout << total << std::endl;
    return 0;
}
