#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    std::vector<int> squares;
    squares.reserve(500);
    for (int i = 1; i <= 500; i++)
    {
        squares.push_back((int)std::pow(i, 2));
    }

    std::vector<int> perims;
    perims.reserve(500);
    for (int i = 0; i < squares.size() - 2; i++)
    {
        for (int j = i + 1; j < squares.size() - 1; j++)
        {
            if (std::binary_search(squares.begin() + j + 1, squares.end(), squares[i] + squares[j]))
            {
                auto p = std::sqrt(squares[i]) + std::sqrt(squares[j]) + std::sqrt(squares[i] + squares[j]);
                if (p <= 1000)
                {
                    perims.push_back(int(p));
                }
            }
        }
    }

    int max_element = 0, max_count = 1;
    for (int i = 0; i < perims.size(); i++)
    {
        int count = 1;
        for (int j = i + 1; j < perims.size(); j++)
        {
            if (perims[i] == perims[j])
            {
                count++;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            max_element = perims[i];
        }
    }

    std::cout << max_element << " -> " << max_count << " times " <<std::endl;
    return 0;
}
