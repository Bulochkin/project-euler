#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>

void pandigital(int prod, int digs[], std::set<int>& alls)
{
    if (prod > 1234 && prod < 9876)
    {
        int temp = prod;
        std::set<int> divs;
        while (temp != 0)
        {
            divs.emplace(temp % 10);
            temp /= 10;
        }

        if (divs.find(digs[5]) != divs.end() && divs.find(digs[6]) != divs.end() &&
            divs.find(digs[7]) != divs.end() && divs.find(digs[8]) != divs.end() && divs.size() == 4)
        {
            alls.emplace(prod);
        }
    }
}

int main()
{
    std::set<int> alls;
    int digs[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    do
    {
        int prod1 = digs[0] * (digs[1] * 1000 + digs[2] * 100 + digs[3] * 10 + digs[4]);
        pandigital(prod1, digs, alls);  //  1 , 4 , 4

        int prod2 = (digs[0] * 10 + digs[1]) * (digs[2] * 100 + digs[3] * 10 + digs[4]);
        pandigital(prod2, digs, alls);  //  2 , 3 , 4

    } while (std::next_permutation(std::begin(digs), std::end(digs)));

    std::cout << std::accumulate(alls.begin(), alls.end(), 0) << std::endl;
    return 0;
}
