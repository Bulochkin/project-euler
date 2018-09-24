#include <iostream>
#include <vector>

#include "InfInt\InfInt.h"
#define TOTAL_CONVERGENTS 100

int main()
{
    std::vector<InfInt> koeffs(TOTAL_CONVERGENTS);

    koeffs[0] = 2;
    for (int i = 1, k = 1; i < TOTAL_CONVERGENTS; i += 3, k++)
    {
        koeffs[i] = koeffs[i + 2] = 1;
        koeffs[i + 1] = 2 * k;
    }

    InfInt tail_up = 1;
    InfInt tail_down = *koeffs.crbegin();
    
    for (auto it = koeffs.crbegin() + 1; it != koeffs.crend(); it++)
    {
        auto up = *it * tail_down + tail_up;
        tail_up = tail_down;
        tail_down = up;
    }

    std::cout << "up - " << tail_down << std::endl;
    std::cout << "down - " << tail_up << std::endl;

    int summ = 0;
    for (size_t i = 0; i < tail_down.numberOfDigits(); i++)
    {
        summ += tail_down.digitAt(i);
    }

    std::cout << std::endl << "sum - " << summ << std::endl;
    return 0;
}
