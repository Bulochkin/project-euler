#include <iostream>
#include <vector>

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

void power(int x, int n) 
{
    int res[MAX];
    int res_size = 0;
    int temp = x;

    // Initialize result
    while (temp != 0) {
        res[res_size++] = temp % 10;
        temp = temp / 10;
    }

    // (x^n = x*x*x....n times) Multiply x n times
    for (int i = 2; i <= n; i++)
        res_size = multiply(x, res, res_size);

    std::cout << x << "^" << n << " = ";
    for (int i = res_size - 1; i >= 0; i--)
        std::cout << res[i];
}

int main() 
{
    int exponent = 25;
    int base = 24;
    power(base, exponent);

    std::cout << std::endl;
    return 0;
}
