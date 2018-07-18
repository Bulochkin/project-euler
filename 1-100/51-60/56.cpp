#include <iostream>
#include <string>
#include <InfInt\InfInt.h>

int main()
{
    int max = 0;
    for (int i = 90; i < 100; i++)
    {
        for (int j = 90; j < 100; j++)
        {
            InfInt t = i;
            for (int k = 1; k != j; k++)
            {
                t *= i;
            }

            int sum = 0;
            std::string s = t.toString();
            for (auto c : s)
            {
                sum += (c - 48);
            }

            if (sum > max)
            {
                max = sum;
            }
        }
    }

    std::cout << max << std::endl;
    return 0;
}
