#include <iostream>

int main()
{
    /*

    9       ->      1       -   9
    180     ->      10      -   99
    2700    ->      100     -   999
    36000   ->      1000    -   9999
    450000  ->      10000   -   99999


    d1 = 1

    d10
    [1] from [180] -> 10 -> 1
    d10 = 1

    d100 = 100 - 9 = 91 -> [10-99] / 2 = 45 + 10 = 55
    d100 = 5

    d1000 = 1000 - 180 - 9 = 811 -> [100-999] / 3 = 270 * 3 = 810
    rest = 1 -> 100 + 270 + 1 - 1 = 370 -> first digit
    d1000 = 3

    d10000 = 10000 - 2700 - 180 - 9 = 7111 / 4 = 1777 * 4 = 7108 -> rest 3 -> third digit
    [1000 - 9999]
    1777 + 1000 + 1 - 1 = 2777
    d10000 = 7

    d100000 = 100000 - 36000 - 2700 - 180 - 9 = 61111 / 5 = 12222 * 5 = 61110 -> rest 1 -> first digit
    [10000 - 99999]
    12222 + 10000 + 1 - 1 = 22222
    d100000 = 2

    d1000000 = 1000000 - 450000 - 36000 - 2700 - 180 - 9 = 511111 / 6 = 85185 * 6 = 511110 -> rest 1 -> first digit
    [100000 - 999999]
    85185 + 100000 + 1 - 1 = 185185
    d1000000 = 1

    */

    std::cout << 1 * 1 * 5 * 3 * 7 * 2 * 1 << std::endl;
    return 0;
}
 