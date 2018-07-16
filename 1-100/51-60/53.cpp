#include <iostream>
#define BORDER 1000000

bool is_greater(int start, int center)
{
    float total = (float)center;
    float sum = 1.0f;

    for (float i = 0; i < total; i++)
    {
        sum *= ((start - i) / (total - i));
    }

    return sum > BORDER;
}

int main()
{
    int start = 23, finish = 101 , center = start / 2;

    int last_total = 0, full_total = 0;
    while (start != finish)
    {
        while (is_greater(start, center)) {
            center--;
        }

        start++;
        center++;

        last_total = start - 2 * center;
        full_total += last_total;
    }

    std::cout << full_total << std::endl;
    return 0;
}
