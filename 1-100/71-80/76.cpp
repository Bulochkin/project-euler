#include <iostream>

void process(int sum, int start, int border, int& total)
{
    while (sum < border)
    {
        sum += start;
        process(sum, start + 1, border, total);
    }

    if (sum == border)
    {
        total++;
    }
}

int main()
{
    int total = 0;
    process( 0 , 1 , 5, total);
    return 0;
}
