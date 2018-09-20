#include <iostream>
#include <vector>
#include "InfInt\InfInt.h"

const int _SIZE = 60000;
std::vector<InfInt> _DATA(_SIZE);

int main() 
{
    _DATA[0] = 1;

    for (int a = 1; a < _SIZE; a++)
    {
        for (int b = -2 * (int)std::sqrt(a); b <= 2 * sqrt(a); b++) 
        {   
            // do recursion with all possible pentagonal number

            if ((b * (b * 3 - 1)) / 2 > a || b == 0) 
            {
                continue;
            }

            if (b % 2 != 0)
            {
                _DATA[a] += _DATA[a - (b * (3 * b - 1)) / 2];
            }

            else
            {
                _DATA[a] -= _DATA[a - (b * (3 * b - 1)) / 2];
            }
        }

        if (_DATA[a] % 1000000 == 0)
        {
            std::cout << a << std::endl;
            std::cout << _DATA[a] << std::endl;
            break;
        }
    }

    std::cout << "__FINISHED___" << std::endl;
}
