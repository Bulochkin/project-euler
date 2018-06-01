#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool isPrime(long long num)
{
	for (long long x = 2; x < num; x++)
	{
		if (num % x == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::vector<long long> vctFactors;
	long long startValue = 600851475143;
	for (long long i = 3; i < startValue; i += 2)
	{
		if (startValue % i == 0)
		{
			startValue /= i;
			vctFactors.push_back(i);
		}
	}

	vctFactors.push_back(startValue);

	for (const auto val : vctFactors)
	{
		std::cout << val << " ";
	}

	std::sort(vctFactors.begin(), vctFactors.end());

	for (auto it = vctFactors.rbegin(); it != vctFactors.rend(); it++)
	{
		if (isPrime(*it))
		{
			std::cout << std::endl << "Result = " << *it << std::endl;
			return 0;
		}
	}

	//long long result = std::accumulate(vctFactors.begin() + 1, vctFactors.end(), (long long)1, std::multiplies<long long>());
	//std::cout << std::endl << "Result = " << result << std::endl;

	std::cout << "Result not founnd" << std::endl;
	return 0;
}