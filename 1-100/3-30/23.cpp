#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <chrono>

int sum_of_divisors(int num)
{
	int sum = 1;
	for (int i = 2; i * i <= num; sum += num % i ? 0 : (i * i == num ? i : i + num / i), i++);
	return sum;
}

int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	std::vector<int> abunds;
	abunds.reserve(10000);

	for (int i = 3; i < 28123; i++)
	{
		int sum = sum_of_divisors(i);
		if (sum > i)
		{
			abunds.push_back(i);
		}
	}

	constexpr long end = 28123;
	constexpr long sum1 = (1 + end - 1) * (end-1) / 2;

	bool sums[end * 2 + 1] = { false };
	for (auto it1 = abunds.begin(); it1 != abunds.end() && *it1 < end / 2; it1++)
	{
		for (auto it2 = it1; it2 != abunds.end(); it2++)
		{
			sums[*it1 + *it2] = true;
		}
	}

	long sum2 = 0;
	for (int i = 0; i < end; i++)
	{
		if (!sums[i])
		{
			sum2 += i;
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	std::cout << "time = " << fp_ms.count() << std::endl;
	std::cout << sum1 << std::endl << sum1 - sum2 << std::endl << sum2 << std::endl;

	return 0;
}
