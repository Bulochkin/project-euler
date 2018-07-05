#include <iostream>
#include <algorithm>
#include <string>

bool check(const std::string& num, int off, int div)
{
    std::string sub = num.substr(off, 3);
    return std::stoi(sub) % div == 0;
}

int main()
{
    long long total = 0;
    std::string to_perm = "0123456789";

    do {
        bool is_ok = 
            check(to_perm, 7, 17) && check(to_perm, 6, 13) && check(to_perm, 5, 11) &&
            check(to_perm, 4, 7) && check(to_perm, 3, 5) && check(to_perm, 2, 3) && check(to_perm, 1, 2);

        if (is_ok)
        {
            total += std::stoll(to_perm);
            std::cout << to_perm << std::endl;
        }

    } while (std::next_permutation(to_perm.begin(), to_perm.end()));
    

    std::cout << std::endl << total << std::endl;
    return 0;
}