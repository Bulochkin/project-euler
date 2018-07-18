#include <iostream>
#include <InfInt/InfInt.h>

class Fraction
{
private:
    InfInt numerator, denominator;
public:
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    }
    Fraction(InfInt n, InfInt d)
    {
        numerator = n;
        if (d == 0)
        {
            std::cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << std::endl;
            exit(0); // will terminate the program if division by 0 is attempted
        }
        else
        {
            denominator = d;
        }
    }

    Fraction Sum(Fraction otherFraction)
    {
        InfInt n = numerator * otherFraction.denominator + otherFraction.numerator*denominator;
        InfInt d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Difference(Fraction otherFraction)
    {
        InfInt n = numerator * otherFraction.denominator - otherFraction.numerator*denominator;
        InfInt d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Product(Fraction otherFraction)
    {
        InfInt n = numerator * otherFraction.numerator;
        InfInt d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Division(Fraction otherFraction)
    {
        InfInt n = numerator * otherFraction.denominator;
        InfInt d = denominator * otherFraction.numerator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    InfInt gcd(InfInt n, InfInt d) const
    {
        InfInt remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }

    void show() const// Display method
    {
        std::cout << numerator.toString() << "/" << denominator.toString() << std::endl;
    }

    size_t digitsNumerator() const
    {
        return numerator.numberOfDigits();
    }

    size_t digitsDenominator() const
    {
        return denominator.numberOfDigits();
    }
};

int main()
{
    //  [1] = 1 + 1 / 2
    //  [2] = 1 + 1 / (1 + [1])
    //  [3] = 1 + 1 / (1 + [2])
    //  [N] = 1 + 1 / (1 + [p])

    int total = 0;
    Fraction one, current(3, 2);
    for (int i = 2; i <= 1000; i++)
    {
        system("CLS");
        std::cout << i << " | 1000" << std::endl;

        current = one.Sum(one.Division(one.Sum(current)));        
        if (current.digitsNumerator() > current.digitsDenominator())
        {
            total++;
            current.show();
        }
    }
    
    std::cout << "total = " << total << std::endl;
    return 0;
}
/*
a=1; b=1; c=0
for i in range(1,1001):
a=a+b
b=2*a-b
if len(str(b))>len(str(a)):
c+=1
print(c)
*/