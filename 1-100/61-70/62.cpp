#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <InfInt/InfInt.h>

#define PERMUTATIONS 5
#define CUBES_BORDER 9000

int main()
{
    std::vector<std::pair<std::string, InfInt>> cubes;
    cubes.reserve(CUBES_BORDER);

    for (InfInt i = 5; i != CUBES_BORDER; i++)
    {
        std::string str = (i * i * i).toString();
        std::sort(str.begin(), str.end());
        cubes.emplace_back(str, i);
    }

    std::sort(cubes.begin(), cubes.end());

    for (size_t i = 0; i < cubes.size(); i++)
    {
        int total = 1;
        for (size_t j = i + 1; j < cubes.size() && cubes[i].first == cubes[j].first; j++, total++);
        
        if (total == PERMUTATIONS)
        {
            for (size_t k = i; k < i + PERMUTATIONS; k++)
            {
                std::cout << cubes[k].second << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
