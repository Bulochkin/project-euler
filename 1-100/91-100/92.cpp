#include <iostream>
#include <set>
#include <cmath>

int run_sum(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += (int)(std::pow(num % 10, 2));
        num /= 10;
    }

    if (sum != 1 && sum != 89)
    {
        return run_sum(sum);
    }

    return sum;
}

int main()
{
    int total = 0;
    for (int i = 1; i < 10000000; i++)
    {
        int sum = run_sum(i);
        if (sum == 89)
        {
            total++;
        }
    }

    std::cout << total << std::endl;
    return 0;
}
