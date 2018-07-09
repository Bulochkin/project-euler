#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

int multiply(int x, int res[], int res_size) 
{
    int carry = 0;  // Initialize carry
    for (int i = 0; i < res_size; i++)  // One by one multiply n with individual digits of res[]
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10; // Store last digit of 'prod' in res[]        
        carry = prod / 10;  // Put rest in carry
    }

    // Put carry in res and increase result size
    while (carry) 
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }

    return res_size;
}

void power(int x, int n, std::vector<int>& tens) 
{
    int res[MAX];
    int res_size = 0 , temp = x;

    // Initialize result
    while (temp != 0) 
    {
        res[res_size++] = temp % 10;
        temp = temp / 10;
    }

    // (x^n = x*x*x....n times) Multiply x n times
    for (int i = 2; i <= n; i++)
    {
        res_size = multiply(x, res, res_size);
    }

    for (int i = std::min(10 - 1, res_size - 1); i >= 0; i--)
    {
        tens[i] += res[i];
    }
}

int main() 
{
    const int total = 1000;
    std::vector<int> tens(10, 0);
 
    for (auto i = 1; i != total; i++)
    {
        power(i, i, tens);
    }

    int carry = 0;
    for (auto i = 0; i < 10; i++)
    {
        tens[i] += carry;
        carry = tens[i] / 10;
        tens[i] %= 10;
    }

    for (auto it = tens.rbegin() ; it != tens.rend() ; it++)
    {
        std::cout << *it;
    }

    std::cout << std::endl;
    return 0;
}
