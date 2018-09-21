#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

#include "InfInt\InfInt.h"

void goRoot(InfInt& up, InfInt& down, int loop, std::vector<int>& nums)
{
    if (loop == 100)
    {
        return;
    }

    int index = 0;
    InfInt down2 = down * 20 + 1;
    for (; index < 9; index++, down2++)
    {
        if (down2 * (index + 1) > up)
        {
            break;
        }
    }

    down2--;
    down2 *= index;

    up -= down2;
    up *= 100;

    down *= 10;
    down += index;

    nums[loop] = index;
    goRoot(up, down, ++loop, nums);
}

int runRoot(int num, int sqr)
{
    InfInt up = num * 100;
    InfInt down = sqr;

    static std::vector<int> nums(100);
    goRoot(up, down, 0, nums);

    return sqr + std::accumulate(nums.begin(), nums.end() - 1, 0);
}

int main()
{
    const int total = 100;
    std::vector<int> root(total);

    int sums = 0;
    for (int i = 2; i <= total; i++)
    {
        int sqr = (int)std::sqrt(i);
        int mul = sqr * sqr;

        if (mul != i)
        {
            sums += runRoot(i - mul, sqr);
        }
    }

    std::cout << sums << std::endl;
    return 0;
}
