#include <iostream>
#include <string>
#include <InfInt/InfInt.h>

int main()
{
    int total = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; ; j++, total++)
        {
            if ((int)(j * std::log10(i) + 1) < j)
            {
                break;
            }
        }
    }

    std::cout << total << std::endl;
    return 0;
}

//InfInt InfPow(InfInt& i1, int& i2)
//{
//    InfInt r = i1;
//    for (int i = 1; i < i2; i++)
//    {
//        r *= i1;
//    }
//    return r;
//}

//int main()
//{
//    InfInt total = 0;
//    const int _BORDRER_ = 25;
//
//    for(InfInt i = 1; i < 10; i++)
//    {
//        for (int j = 1; j < _BORDRER_; j++)
//        {
//            std::string pow = InfPow(i, j).toString();
//            if (pow.length() == j)
//            {
//                total++;
//                std::cout << i << " ^ " << j << "\t= " << pow << std::endl;
//            }
//            else if (pow.length() > j)
//            {
//                break;
//            }
//        }
//    }
//
//    std::cout << "total = " << total << std::endl;
//    return 0;
//}
