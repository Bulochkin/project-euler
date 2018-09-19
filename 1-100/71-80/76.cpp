#include <iostream>
#include <vector>

//  https://www.geeksforgeeks.org/generate-unique-partitions-of-an-integer/
int process(int n)
{
    int _total = 0;
    std::vector<int> p(n);

    int k = 0;  // Index of last element in a partition 
    p[k] = n;  // Initialize first partition as number itself 

    while (true)
    {
        // Find the rightmost non-one value in p[]. Also, update the 
        // rem_val so that we know how much value can be accommodated 
        int rem_val = 0;
        while (k >= 0 && p[k] == 1)
        {
            rem_val += p[k];
            k--;
        }

        // if k < 0, all the values are 1 so there are no more partitions 
        if (k < 0)
        {
            return _total;
        }

        // Decrease the p[k] found above and adjust the rem_val 
        p[k]--;
        rem_val++;


        // If rem_val is more, then the sorted order is violated.  Divide 
        // rem_val in different values of size p[k] and copy these values at 
        // different positions after p[k] 
        while (rem_val > p[k])
        {
            p[k + 1] = p[k];
            rem_val = rem_val - p[k];
            k++;
        }

        // Copy rem_val to next position and increment position 
        p[k + 1] = rem_val;

        k++;
        _total++;
    }
}

int main()
{
    std::cout << process(9) << std::endl;
    return 0;
}
