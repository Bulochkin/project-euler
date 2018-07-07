#include <iostream>
#include <vector>
#include <algorithm>

//void dividers(int num, std::vector<int>& divs)
//{
//    for (int i = 2; i <= num; i++)
//    {
//        if (num % i == 0)
//        {
//            divs.push_back(i);
//
//            while (num % i == 0)
//            {
//                num /= i;
//            }
//        }
//    }
//}
//
//int main()
//{
//    const int total = 1000000;
//    const int to_search = 4;
//
//    int to_insert = 0;
//    std::vector<int> results;
//    for (int i = 2; i < total && to_insert != to_search; i++)
//    {
//        std::vector<int> divs;
//        dividers(i, divs);
//
//        if (divs.size() == to_search)
//        {
//            if (to_insert != 0 && results[to_insert - 1] != i - 1)
//            {
//                results.clear();
//            }
//
//            results.push_back(i);
//            to_insert = (int)results.size();
//        }
//    }
//
//    for (auto num : results)
//    {
//        std::cout << num << std::endl;
//    }
//
//    return 0;
//}


int main()
{
    const int to_find = 4;
    const int total = 1000000;

    std::vector<int> factors(total, 0);
    int sqr = (int)std::sqrt(total);

    for (int index = 2; index < sqr; index++)
    {
        if (factors[index] != 0)
        {
            continue;
        }

        for (int num = index * 2; num < total; num += index)
        {
            factors[num]++;
        }
    }

    int found = 0, index = 2;
    while (index < total && found != to_find)
    {
        if (factors[index++] != to_find)
        {
            found = 0;
            continue;
        }
        found++;
    }

    std::cout << index - 4 << std::endl;
    return 0;
}
