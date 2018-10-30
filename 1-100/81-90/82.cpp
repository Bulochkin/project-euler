#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#define N 80

int main()
{
    std::vector<std::vector<int>> rows;
    std::ifstream ifs("p082_matrix.txt");

    while (ifs.good())
    {
        std::string nums, one;
        std::getline(ifs, nums, '\n');

        std::vector<int> toPush;
        std::istringstream is(nums);

        while (std::getline(is, one, ','))
        {
            toPush.push_back(std::stoi(one));
        }

        if (toPush.size())
        {
            rows.emplace_back(std::move(toPush));
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!i && j)
            {
                rows[i][j] += rows[i][j - 1];
            }
            else if (!j && i)
            {
                rows[i][j] += rows[i - 1][j];
            }
            else if (i && j)
            {
                if (rows[i - 1][j] < rows[i][j - 1])
                {
                    rows[i][j] += rows[i - 1][j];
                }
                else
                {
                    rows[i][j] += rows[i][j - 1];
                }
            }
        }
    }

    return 0;
}
