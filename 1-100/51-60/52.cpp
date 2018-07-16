#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    const int total = 1000000;
    for (unsigned long i = 1; i < total; i++)
    {
        auto s1 = std::to_string(i * 1);
        std::sort(s1.begin(), s1.end());

        auto s2 = std::to_string(i * 2);
        std::sort(s2.begin(), s2.end());

        auto s3 = std::to_string(i * 3);
        std::sort(s3.begin(), s3.end());

        auto s4 = std::to_string(i * 4);
        std::sort(s4.begin(), s4.end());

        auto s5 = std::to_string(i * 5);
        std::sort(s5.begin(), s5.end());

        auto s6 = std::to_string(i * 6);
        std::sort(s6.begin(), s6.end());

        if (s1 == s2 && s1 == s3 && s1 == s4 && s1 == s5 && s1 == s6)
        {
            std::cout << i << std::endl;
            break;
        }
    }
    return 0;
}
