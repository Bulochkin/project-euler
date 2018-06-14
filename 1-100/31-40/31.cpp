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
                                for (int p1 = 0; p1 < 201; p1 += 1)
                                {
                                    if (p200 + p100 + p50 + p20 + p10 + p5 + p2 + p1 == 200)
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
    }


    std::cout << total << std::endl;
    return 0;
}