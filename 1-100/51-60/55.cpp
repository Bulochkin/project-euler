#include <iostream>
#include <set>
#include <string>
#include <InfInt\InfInt.h>

bool regeneratePalindrome(unsigned long long pl)
{
    std::string s1, s2;
    InfInt infStart = pl;
    
    for (int i = 0; i < 50; i++)
    {
        s1 = infStart.toString();
        std::reverse(s1.begin(), s1.end());

        InfInt infNext = s1;
        infStart += infNext;

        s1 = infStart.toString();
        s2 = s1;

        std::reverse(s2.begin(), s2.end());
        if (s1 == s2)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int total = 0;    
    for (int i = 0 ; i < 10000 ; i++)
    {
        if (!regeneratePalindrome(i))
        {
            total++;
        }
    }

    std::cout << total << std::endl;
    return 0;
}
