#include <iostream>

long farey(int n)
{
    long total = 0;
    constexpr double d13 = 1.0 / 3.0, d12 = 1.0 / 2.0;

    double x, y = 0;
    double x1 = 0, y1 = 1, x2 = 1, y2 = n;
    while (y != 1.0) 
    {
        // Using recurrence relation to find the next term 
        x = floor((y1 + n) / y2) * x2 - x1;
        y = floor((y1 + n) / y2) * y2 - y1;

        auto div = x / y;
        if (div > d13 && div < d12)
        {
            total++;
        }

        // Update x1, y1, x2 and y2 for next iteration 
        x1 = x2, x2 = x, y1 = y2, y2 = y;
    }

    return total;
}

// Driver program 
int main()
{
    std::cout << farey(12000) << std::endl;
    return 0;
}
