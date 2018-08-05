#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::vector<int>> rows;
    std::ifstream ifs("p067_triangle.txt");

    while (ifs.good())
    {
        std::string nums, one;
        std::getline(ifs, nums, '\n');

        std::vector<int> toPush;
        std::istringstream is(nums);

        while (std::getline(is, one, ' ')) 
        {
            toPush.push_back(std::stoi(one));
        }

        if (toPush.size())
        {
            rows.emplace_back(std::move(toPush));
        }
    }

    for (auto i = rows.size() - 1; i != 0; i--)
    {
        for (auto j = 0; j < rows[i].size() - 1; j++)
        {
            rows[i - 1][j] += std::max(rows[i][j], rows[i][j + 1]);
        }
    }

    std::cout << rows[0][0] << std::endl;
    return 0;
}
