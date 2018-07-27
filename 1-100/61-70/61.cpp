#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <numeric>

#define TOTAL 6
std::vector<std::vector<int>> globals;

std::function<int(int)> fcyclical[TOTAL] = {
    [](int n) { return n * (n + 1) / 2; },
    [](int n) { return n * n; },
    [](int n) { return n * (3 * n - 1) / 2; },
    [](int n) { return n * (2 * n - 1); },
    [](int n) { return n * (5 * n - 3) / 2; },
    [](int n) { return n * (3 * n - 2); }
};

void emplace_if(std::vector<int>& v, std::function<int(int)>& f)
{
    for (int n = 1, num = 0; num < 10000; n++)
    {
        num = f(n);
        if (num > 999 && num < 10000)
        {
            v.emplace_back(num);
        }
    }
}

void find_recursive(std::vector<std::pair<int, bool>> alls, std::vector<int> sec)
{
    if (sec.size() == TOTAL)
    {
        if (sec[TOTAL - 1] % 100 == sec[0] / 100)
        {
            std::sort(sec.begin(), sec.end());
            globals.push_back(sec);
        }
        return;
    }

    int cmp = sec.back() % 100;
    for (auto& pair : alls)
    {
        if (pair.first / 100 == cmp && pair.second == false)
        {
            auto newsec(sec);
            newsec.emplace_back(pair.first);

            pair.second = true;
            find_recursive(alls, newsec);
        }
    }
}

bool validate_sequence(const std::vector<int>* const nums, std::vector<int> digits, int index)
{
    if (index == TOTAL)
    {
        return digits.size() == 0;
    }

    bool is_ok = false;
    for (auto digit : digits)
    {
        if (std::binary_search(nums[index].begin(), nums[index].end(), digit))
        {
            auto erased(digits);
            erased.erase(std::remove(erased.begin(), erased.end(), digit), erased.end());
            is_ok = validate_sequence(nums, erased, index + 1);
        }
    }

    return is_ok;
}

int main()
{
    std::vector<int> nums[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
        emplace_if(nums[i], fcyclical[i]);
    }

    std::vector<std::pair<int, bool>> alls;
    alls.reserve(400);
    for (int i = 0; i < TOTAL; i++)
    {
        for (auto num : nums[i])
        {
            alls.emplace_back(std::pair<int, bool>(num, false));
        }
    }

    std::sort(alls.begin(), alls.end());
    alls.erase(std::unique(alls.begin(), alls.end()), alls.end());

    for (auto& pair : alls)
    {
        pair.second = true;
        find_recursive(alls, { pair.first });
    }

    std::sort(globals.begin(), globals.end());
    globals.erase(std::unique(globals.begin(), globals.end()), globals.end());

    for (const auto& one : globals)
    {
        if (validate_sequence(nums, one, 0))
        {
            std::cout << "sum = " << std::accumulate(one.begin(), one.end(), 0) << " -> ";
            for (auto digit : one)
            {
                std::cout << digit << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
