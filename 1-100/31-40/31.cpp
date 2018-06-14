#include <iostream>

int main()
{
    int total = 0;
    for (int p200 = 0; p200 < 201; p200 += 200)
    {
        for (int p100 = 0; p100 < 201; p100 += 100)
        {
            for (int p50 = 0; p50 < 201; p50 += 50)
            {
                for (int p20 = 0; p20 < 201; p20 += 20)
                {
                    for (int p10 = 0; p10 < 201; p10 += 10)
                    {
                        for (int p5 = 0; p5 < 201; p5 += 5)
                        {
                            for (int p2 = 0; p2 < 201; p2 += 2)
                            {
                                if (p200 + p100 + p50 + p20 + p10 + p5 + p2 <= 200)
                                {
                                    total++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << total << std::endl;
    return 0;
}

/*

#include <iostream>
using namespace std;

int coins[8] = { 200, 100, 50, 20, 10, 5,2,1 };

int findposs(int money, int maxcoin)
{
    int sum = 0;
    if (maxcoin == 7) return 1;
    for (int i = maxcoin; i<8; i++)
    {
        if (money - coins[i] == 0)
            sum += 1;
    
        if (money - coins[i] > 0)
            sum += findposs(money - coins[i], i);
    }
    return sum;
}

int main()
{
    cout << findposs(200, 0) << endl;
}

*/
