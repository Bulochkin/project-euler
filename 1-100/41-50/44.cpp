#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    const int total = 3000;
    std::vector<int> pents;

    pents.reserve(total);
    for (auto i = 1; i < total; i++)
    {
        pents.emplace_back(i * (3 * i - 1) / 2);
    }

    for (auto it = pents.rbegin(); it != pents.rend(); it++)
    {
        for (auto jt = it + 1; jt != pents.rend(); jt++)
        {
            auto sum = *it + *jt;
            auto diff = *it - *jt;

            auto pos1 = std::binary_search(pents.begin(), pents.end(), sum);
            auto pos2 = std::binary_search(pents.begin(), pents.end(), diff);

            if (pos1 && pos2)
            {
                std::cout << "First = " << *it << std::endl << "Second = " << *jt << std::endl;
                std::cout << "Sum = " << sum << std::endl << "Diff = " << diff << std::endl << std::endl;
            }
        }
    }
    return 0;
}