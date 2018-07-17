#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

long straight(const std::vector<long>& d)
{
    if ((d[0] + 1 == d[1]) && (d[1] + 1 == d[2]) && (d[2] + 1 == d[3]) && (d[3] + 1 == d[4]))
    {
        return 18000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long flash(const std::string& h, const std::vector<long>& d)
{
    if ((h[1] == h[4]) && (h[4] == h[7]) && (h[7] == h[10]) && (h[10] == h[13]))
    {
        return 19000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

bool royal(const std::vector<long>& d)
{
    return (d[0] == 10) && (d[1] == 11) && (d[2] == 12) && (d[3] == 13) && (d[4] == 14);
}

long straight_flash(const std::vector<long>& d, const std::string& h)
{
    if (straight(d) != 0 && flash(h, d) != 0)
    {
        return 22000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long royal_flash(const std::vector<long>& d, const std::string& h)
{
    if (straight_flash(d, h) != 0 && royal(d))
    {
        return 23000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long four_of_a_kind(const std::vector<long>& d)
{
    if (d[0] == d[3])
    {
        return 21000000 + d[3] * 10000 + d[2] * 1000 + d[1] * 100 + d[0] * 10 + d[4];
    }
    else if (d[1] == d[4])
    {
        return 21000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long full_house(const std::vector<long>& d)
{
    if (((d[0] == d[1]) && (d[2] == d[4])) || ((d[0] == d[2]) && (d[3] == d[4])))
    {
        return 20000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long three_of_a_kind(const std::vector<long>& d)
{
    if (d[0] == d[2])
    {
        return 17000000 + d[2] * 10000 + d[1] * 1000 + d[0] * 100 + d[4] * 10 + d[3];
    }
    else if (d[1] == d[3])
    {
        return 17000000 + d[3] * 10000 + d[2] * 1000 + d[1] * 100 + d[4] * 10 + d[0];
    }
    else if (d[2] == d[4])
    {
        return 17000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long two_pairs(const std::vector<long>& d)
{
    if ((d[0] == d[1]) && (d[2] == d[3]))
    {
        return 16000000 + d[3] * 10000 + d[2] * 1000 + d[1] * 100 + d[0] * 10 + d[4];
    }
    else if ((d[0] == d[1]) && (d[3] == d[4]))
    {
        return 16000000 + d[4] * 10000 + d[3] * 1000 + d[1] * 100 + d[0] * 10 + d[2];
    }
    else if ((d[1] == d[2]) && (d[3] == d[4]))
    {
        return 16000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long one_pair(const std::vector<long>& d)
{
    if (d[0] == d[1])
    {
        return 15000000 + d[1] * 10000 + d[0] * 1000 + d[4] * 100 + d[3] * 10 + d[2];
    }
    else if (d[1] == d[2])
    {
        return 15000000 + d[2] * 10000 + d[1] * 1000 + d[4] * 100 + d[3] * 10 + d[0];
    }
    else if (d[2] == d[3])
    {
        return 15000000 + d[3] * 10000 + d[2] * 1000 + d[4] * 100 + d[1] * 10 + d[0];
    }
    else if (d[3] == d[4])
    {
        return 15000000 + d[4] * 10000 + d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
    }
    else
    {
        return 0;
    }
}

long deal_id(const std::string& hand)
{
    std::vector<long> digits;
    for (auto i = 0; i < 15; i += 3)
    {
        if (hand[i] == 'T')
        {
            digits.push_back(10);
        }
        else if (hand[i] == 'J')
        {
            digits.push_back(11);
        }
        else if (hand[i] == 'Q')
        {
            digits.push_back(12);
        }
        else if (hand[i] == 'K')
        {
            digits.push_back(13);
        }
        else if (hand[i] == 'A')
        {
            digits.push_back(14);
        }
        else
        {
            digits.push_back(hand[i] - 48);
        }
    }

    std::sort(digits.begin(), digits.end());

    long score = royal_flash(digits, hand);
    if (score == 0)
    {
        score = straight_flash(digits, hand);
        if (score == 0)
        {
            score = four_of_a_kind(digits);
            if (score == 0)
            {
                score = full_house(digits);
                if (score == 0)
                {
                    score = flash(hand, digits);
                    if (score == 0)
                    {
                        score = straight(digits);
                        if (score == 0)
                        {
                            score = three_of_a_kind(digits);
                            if (score == 0)
                            {
                                score = two_pairs(digits);
                                if (score == 0)
                                {
                                    score = one_pair(digits);
                                    if (score == 0)
                                    {
                                        score = 14000000 + 
                                            digits[4] * 10000 + 
                                            digits[3] * 1000 + 
                                            digits[2] * 100 + 
                                            digits[1] * 10 + 
                                            digits[0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return score;
}

int main()
{
    std::ifstream ifs("p054_poker.txt");
    if (!ifs.is_open())
    {
        return -1;
    }

    int current = 0;
    std::vector<std::string> hands(1000);
    while (ifs.good() && current != 1000)
    {
        std::getline(ifs, hands[current++]);
    }

    int player1 = 0;
    for (auto& hand : hands)
    {
        auto id1 = deal_id(hand);
        auto id2 = deal_id(hand.substr(15));

        if (id1 > id2)
        {
            player1++;
        }
    }

    ifs.close();
    std::cout << player1 << std::endl;

    return 0;
}
