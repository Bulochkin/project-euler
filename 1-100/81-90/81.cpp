#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int main()
{
    std::vector<std::vector<int>> rows;
    std::ifstream ifs("p081_matrix.txt");

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

    std::vector<std::vector<int>> triangle;

    for (int j = 0; j < rows.size() - 1; j++)
    {
        std::vector<int> toPush;
        for (int k = j, m = 0; k >= 0; k--, m++)
        {
            toPush.push_back(rows[k][m]);
        }
        triangle.emplace_back(std::move(toPush));
    }

    for (int j = 0 , p = 0; j < rows.size(); j++ , p++)
    {
        std::vector<int> toPush;
        for (int i = 0; i < p; i++)
        {
            toPush.push_back(9999);
        }

        for (int k = (int)rows.size() - 1 , m = j; k >= j; k-- , m++)
        {
            toPush.push_back(rows[k][m]);
        }

        for (int i = 0; i < p; i++)
        {
            toPush.push_back(9999);
        }
        triangle.emplace_back(std::move(toPush));
    }

    for (auto i = triangle.size() - 1; i != 0; i--)
    {
        for (auto j = 0; j < triangle[i].size() - 1; j++)
        {
            triangle[i - 1][j] += std::min(triangle[i][j], triangle[i][j + 1]);
        }
    }

    std::cout << triangle[0][0] << std::endl;
    return 0;
}
