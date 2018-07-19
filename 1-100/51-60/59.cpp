#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool decrypt_data(const std::vector<char>& data, const std::string& key)
{
    for (int i = 0; i < data.size(); i++)
    {
        char ixor = data[i] ^ key[i % 3];

        if (ixor >= 'A' && ixor <= 'Z')
        {
            continue;
        }

        if (ixor >= 'a' && ixor <= 'z')
        {
            continue;
        }

        if (ixor >= '0' && ixor <= '9')
        {
            continue;
        }

        if (ixor == ' ' || ixor == '!' || ixor == '?' || ixor == '.' || ixor == ';' || ixor == '\'' ||
            ixor == ',' || ixor == '?' || ixor == ')' || ixor == '(' || ixor == '-' || ixor == '"')
        {
            continue;
        }
            
        return false;
    }

    return true;
}

int main()
{
    std::ifstream ifs("p059_cipher.txt");
    if (!ifs.is_open())
    {
        return -1;
    }

    std::string digit;
    std::vector<char> nums;

    while (ifs.good())
    {
        std::getline(ifs, digit, ',');
        nums.push_back(std::stoi(digit));
    }

    ifs.close();

    std::vector<int> perms(26);
    perms[25] = perms[24] = perms[23] = 1;

    bool isFound = false;
    std::string indexes;
    do {
        indexes.clear();
        for (int i = 0; i < perms.size(); i++)
        {
            if (perms[i])
            {
                indexes += (i + 97);
            }
        }
        do 
        {
            if (decrypt_data(nums, indexes))
            {
                isFound = true;
                std::cout << "----" << std::endl << indexes << std::endl << "----" << std::endl;
            }
        } while (!isFound && std::next_permutation(indexes.begin(), indexes.end()));

    } while (!isFound && std::next_permutation(perms.begin(), perms.end()));

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] ^= indexes[i % 3];
        sum += nums[i];
        std::cout << nums[i];
    }

    std::cout << std::endl << "-------" << std::endl << sum << std::endl << "-------" << std::endl;
    return 0;
}
