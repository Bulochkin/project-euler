#include <iostream>
#include <set>
#include <string>

// A utility for creating palindrome
int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;

    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;

    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

// Fruition to print decimal palindromic number
void generatePaldindromes(int n, std::set<int>& pls)
{
    int number;

    // Run two times for odd and even length palindromes
    for (int j = 0; j < 2; j++)
    {
        // Creates palindrome numbers with first half as i. 
        // Value of j decided whether we need an odd length
        // of even length palindrome.
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            pls.emplace(number);
            i++;
        }
    }
}

bool regeneratePalindrome(unsigned long long pl)
{
    std::string s1, s2;
    for (int i = 0; i < 15; i++)
    {
        s1 = std::to_string(pl);
        std::reverse(s1.begin(), s1.end());
        decltype(pl) pl_new = std::stoull(s1);
        pl += pl_new;
        s1 = std::to_string(pl);
        s2 = s1;
        std::reverse(s2.begin(), s2.end());
        if (s1 == s2)
        {
            return true;
        }
    }

    return false;
}

// Driver Program to test above function
int main()
{
    std::set<int> pls;
    generatePaldindromes(10000, pls);

    int total = 0;
    for (auto pl : pls)
    {
        if (!regeneratePalindrome(pl))
        {
            std::cout << pl << std::endl;
            total++;
        }
    }

    std::cout << std::endl << total << std::endl;
    return 0;
}
