#include <iostream>
#include <cmath>
#include <vector>

#include "InfInt\InfInt.h"
#define TOTAL 1000

//  https://www.mccme.ru/free-books/mmmf-lectures/book.13.pdf

std::vector<unsigned long> sqrtCF(unsigned long D)
{
    unsigned long R = (unsigned long)floor(sqrt(D));
    std::vector<unsigned long> f;

    if (R*R == D)
    {
        return f;   // Oops, a square
    }

    unsigned long a = R, P = 0, Q = 1;

    do {
        P = a * Q - P;
        Q = (D - P * P) / Q;
        a = (R + P) / Q;
        f.push_back(a);
    } while (Q != 1);

    return f;
}

int main()
{
    InfInt pnMax = 0, dnMax = 0;
    for (int d = 2; d <= TOTAL; d++)
    {
        const auto&& root = sqrtCF(d);
        const auto sizeFull = root.size();

        if (sizeFull > 0)
        {
            InfInt pn = 0, qn = 0, pn1 = 1, qn1 = 0;
            InfInt pn0 = (int)std::sqrt(d), qn0 = 1;

            auto totalN = (sizeFull - 1) % 2 ? (sizeFull - 1) : (2 * sizeFull - 1);
            for (auto i = 0; i < totalN; i++)
            {
                pn = InfInt(root[i % sizeFull]) * pn0 + pn1;
                qn = InfInt(root[i % sizeFull]) * qn0 + qn1;

                pn1 = pn0;
                qn1 = qn0;

                pn0 = pn;
                qn0 = qn;

                //std::cout << "[" << pn << " , " << qn << "]" << std::endl;
            }

            if (pn > pnMax)
            {
                pnMax = pn;
                dnMax = d;
            }
        }
    }

    std::cout << "D = " << dnMax << " , X = " << pnMax << std::endl;
    return 0;
}
