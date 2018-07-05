#include <iostream>
#include <string>
#include <algorithm>

bool is_prime(int num)
{
    for (int i = 3; i < (int)std::sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string to_perm = "7654321";

    do {
        int num = std::stoi(to_perm);
        if (num % 2)
        {
            if (is_prime(num))
            {
                std::cout << num << std::endl;
                break;
            }
        }
    } while (std::prev_permutation(to_perm.begin(), to_perm.end()));
    return 0;
}
