#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int gcd(int n, int d)
{
    int remainder;
    while (d != 0)
    {
        remainder = n % d;
        n = d;
        d = remainder;
    }
    return n;
}

void number_pythagorean_triples(int t , std::vector<std::vector<int>>& data)
{
    for (int m = 2; m < int(std::sqrt(t / 2)); m++)
    {
        for (int n = 1; n < m; n++)
        {
            if (gcd(m, n) == 1 && (m - n) % 2)
            {
                for (int i = 1 , k = 2 * m * (m + n); k < t; k += 2 * m * (m + n) , i++)
                {
                    int a = i * m * m - i * n * n;
                    int b = i * 2 * m * n;
                    data.push_back({ a , b , k });
                }
            }
        }
    }
}

int main()
{
    const int total = 1500000;

    std::vector<std::vector<int>> data;
    data.reserve(total * 2);

    number_pythagorean_triples(total , data);    
    std::sort(data.begin(), data.end(), [](const auto& left, const auto& right) {
        return left[2] < right[2];
    });

    int perims = 0;
    for (int i = 0; i < data.size(); )
    {
        int j = i + 1;
        while (j < data.size() && data[i][2] == data[j][2])
        {
            j++;
        }

        if (j == i + 1)
        {
            i++;
            perims++;
        }
        else
        {
            i = j;
        }
    }

    std::cout << perims << std::endl;
    return 0;
}
