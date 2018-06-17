#include <iostream>
#include <bitset>
#include <cmath>
#include <string>

bool is_palindrom_dec(unsigned long num)
{
    std::string s1 = std::to_string(num);
    std::string s2 = s1;

    std::reverse(s2.begin(), s2.end());
    return s1 == s2;
}

void sum_palindrom_bits(const std::string& str_bts, unsigned long& sum)
{
    std::bitset<20> bts(str_bts);
    unsigned long dec = bts.to_ulong();

    if (dec < 999999 && is_palindrom_dec(dec))
    {
        sum += dec;
    }
}

int main()
{
    unsigned long sum = 1;

    for (int i = 1; i < 1000; i++ )
    {
        int temp = i;
        std::string left, right;
        while (temp != 0)
        {
            right += std::to_string(temp % 2);
            temp /= 2;
        }

        left = right;
        std::reverse(left.begin(), left.end());

        std::string s1 = left + right;
        sum_palindrom_bits(s1, sum);

        std::string s2 = left + "0" + right;
        sum_palindrom_bits(s2, sum);

        std::string s3 = left + "1" + right;
        sum_palindrom_bits(s3, sum);
    }

    std::cout << sum << std::endl;
    return 0;
}
