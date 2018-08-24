#include <iostream>
#include <vector>

#define FRACTIONS_BORDER 15

struct fraction
{
    int up;
    int down;
};

void go(int num, fraction fr, std::vector<fraction>& seqs)
{
    for (auto& it = seqs.begin(); it != seqs.end(); it++)
    {
        if (it->up == fr.up)
        {
            //  ToDo - process fr.down
            return;
        }
    }

    seqs.push_back(fr);

    int base = ((int)std::sqrt(num) + fr.up) / fr.down;
    int up = base * fr.down - fr.up;
    int down = num - up * up;

    if (down % fr.down != 0)
    {
        std::cout << "!!!!!!!!!!" << std::endl;
    }

    down /= fr.down;

    fraction fr2 = { up , down };
    go(num, fr2, seqs);
}

int main()
{
    std::vector<fraction> all;
    for (int i = 14; i <= FRACTIONS_BORDER; i++)
    {
        int sqr = (int)std::sqrt(i);
        if (sqr * sqr == i)
        {
            continue;
        }

        fraction fr = { sqr, i - sqr * sqr };
        go(i, fr, all);
    }

    return 0;
}
