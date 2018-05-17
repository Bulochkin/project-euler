#include <iostream>

int main()
{
	long currSum1 = 0, currSum2 = 0;
	for (auto i = 1; i < 101; i++)
	{
		currSum1 += i * i;
		currSum2 += i;
	}

	currSum2 *= currSum2;
	std::cout << currSum2 - currSum1 << std::endl;

	//	(1 + 2 + ... + n) ^ 2 = n ^ 2 * (n + 1) ^ 2 * 1 / 4
	//	1 ^ 2 + 2 ^ 2 + ... + n ^ 2 = n * (n + 1) * (2n + 1) * 1 / 6

	return 0;
}