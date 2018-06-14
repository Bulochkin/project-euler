#include <iostream>

int main()
{
    int up = 1, down = 1;
    for (int i = 11; i < 100; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            if (i % 10 == j / 10)
            {
                float d1 = (float)i / (float)j;
                float d2 = (float)(i / 10) / (float)(j % 10);

                //  std::numeric_limits<double>::epsilon()
                if (d1 == d2)
                {
                    up *= i;
                    down *= j;
                }
            }
        }
    }

    if (down % up == 0)
    {
        std::cout << down / up << std::endl;
    }
    else
    {
        // ToDo - implement
    }
    return 0;
}
