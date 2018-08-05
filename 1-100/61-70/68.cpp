#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <numeric>
#include <string>

std::set<std::vector<int>> seqs;

void processRing(std::vector<int>& ring, std::vector<int>& left)
{
    std::sort(ring.begin(), ring.end());

    do {

        std::sort(left.begin(), left.end());

       do {
            int cmp = 0;
            std::vector<std::vector<int>> sums;
            
            for (int i = 0; i < ring.size(); i++)
            {
                int cmpNew = left[i] + ring[i] + ring[(i + 1) % ring.size()];
                if (sums.empty())
                {
                    cmp = cmpNew;
                }

                if (cmp == cmpNew)
                {
                    sums.push_back({ left[i] , ring[i]  , ring[(i + 1) % ring.size()] });
                    continue;
                }
               
                break;
            }

            if (sums.size() == 5)
            {
                int index = 0;
                for (int i = 1; i < sums.size(); i++)
                {
                    if (sums[i][0] < sums[index][0])
                    {
                        index = i;
                    }
                }

                std::vector<int> seq;
                for (int i = 0; i < sums.size(); i++)
                {
                    for (int j = 0; j < sums[index].size(); j++)
                    {
                        seq.emplace_back(sums[index][j]);
                    }

                    index = (index + 1) % sums.size();
                }

                seqs.emplace(std::move(seq));
            }

        } while (std::next_permutation(left.begin(), left.end()));

    } while (std::next_permutation(ring.begin(), ring.end()));
}

void processPermutation(const std::vector<int>& from, int total, 
                        std::function<void(std::vector<int>&, std::vector<int>&)>& farg)
{
    std::vector<int> perms(from.size(), 1);
    for (int i = 0; i < total; i++)
    {
        perms[i] = 0;
    }

    do {

        std::vector<int> perm, left;
        for (int i = 0; i < perms.size(); i++)
        {
            if (perms[i] == 0)
            {
                perm.push_back(from[i]);
            }
            else
            {
                left.push_back(from[i]);
            }
        }

        farg(perm, left);

    } while (std::next_permutation(perms.begin(), perms.end()));
}

int main()
{
//#define TEST_CASE
#ifdef TEST_CASE
    const int ringTotal = 3;
    const std::vector<int> dataAll = { 1 , 2 , 3 , 4 , 5 , 6 };
#else
    const int ringTotal = 5;
    const std::vector<int> dataAll = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 };
#endif

    std::function<void(std::vector<int>&, std::vector<int>&)> farg = processRing;
    processPermutation(dataAll, ringTotal, farg);

    for (auto& seq : seqs)
    {
        std::string str;
        for (auto num : seq)
        {
            str += std::to_string(num);
            std::cout << num;
        }
        std::cout << "\t-> " << str.length() << std::endl;
    }

    return 0;
}
