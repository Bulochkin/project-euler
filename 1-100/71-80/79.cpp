#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>

int main()
{
    std::ifstream ifs("p079_keylog.txt");
    std::map<int, std::set<int>> data;

    while (ifs.good())
    {
        std::string nums;
        std::getline(ifs, nums);

        if (!nums.empty())
        {
            int num = std::stoi(nums);

            int n1 = num / 100;
            int n2 = (num / 10) % 10;
            int n3 = num % (num / 10);

            data[n1].emplace(n2);
            data[n1].emplace(n3);
            data[n2].emplace(n3);
        }
    }

    std::multiset<size_t> sizes;
    for (auto& item : data)
    {
        sizes.emplace(item.second.size());
    }

    std::set<size_t> sizesUnique(sizes.begin() , sizes.end());
    if (sizes.size() != sizesUnique.size())
    {
        std::cout << "--- PROBLEM ---" << std::endl;
        return -1;
    }

    for (auto it = sizesUnique.rbegin(); it != sizesUnique.rend(); it++)
    {
        for (auto& item : data)
        {
            if (item.second.size() == *it)
            {
                std::cout << item.first;

                if (item.second.size() == *(sizesUnique.begin()))
                {
                    for (auto num : item.second)
                    {
                        std::cout << num;
                    }
                }

                break;
            }
        }
    }

    std::cout << std::endl;
    return 0;
}
