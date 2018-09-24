#include <iostream>
#include <vector>

#define FRACTIONS_BORDER 10000

//  https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
//  https://stackoverflow.com/questions/12182701/generating-continued-fractions-for-square-roots

std::vector<unsigned long> sqrtCF(unsigned long D) 
{
    // sqrt(D) may be slightly off for large D.
    // If large D are expected, a correction for R is needed.

    unsigned long R = (unsigned long)floor(sqrt(D));
    std::vector<unsigned long> f;
    
    if (R*R == D) 
    {
        return f;   // Oops, a square
    }

    unsigned long a = R, P = 0, Q = 1;
    do 
    {
        P = a * Q - P;
        Q = (D - P * P) / Q;
        a = (R + P) / Q;
        f.push_back(a);
    } 
    while (Q != 1);

    return f;
}

int main()
{
    int total = 0;
    for (int i = 2; i <= FRACTIONS_BORDER; i++)
    {
        const auto&& root = sqrtCF(i);
        if (root.size() % 2)
        {
            total++;
        }
    }

    std::cout << total << std::endl;
    return 0;
}
