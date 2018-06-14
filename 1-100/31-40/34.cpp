#include <iostream>

int main()
{
    int total = 0;
    constexpr int factorials[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

    for (int i = 3; i < 2540160; i++)
    {
        int sum = 0, temp = i;

        while (temp)
        {
            sum += factorials[temp % 10];
            temp /= 10;
        }

        if (sum == i)
        {
            total += sum;
        }
    }

    std::cout << total << std::endl;
    return 0;
}
