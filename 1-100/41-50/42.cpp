#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main()
{
    const std::set<int> triangles = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190 };

    std::ifstream ifs("p042_words.txt");
    if (!ifs.is_open())
    {
        return -1;
    }

    int total = 0;
    std::string word;
    while (ifs.good())
    {
        int sum = 0;
        std::getline(ifs, word, ',');
        for (auto i = 1; i < word.length() - 1; i++)
        {
            sum += (word[i] - 64);
        }

        if (triangles.find(sum) != triangles.end())
        {
            total++;
        }
    }

    ifs.close();
    std::cout << total << std::endl;

    return 0;
}