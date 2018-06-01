#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>
#include <chrono>

//int sum_of_divisors(int num)
//{
//	int sum = 1;
//	for (int i = 2; i*i <= num; sum += num % i ? 0 : (i*i == num ? i : i + num / i), i++);
//	return sum;
//}

int sum_of_divisors(int num)
{
	int sum = 1;
	int sqr = (int)std::sqrt(num);
	for (int i = 2; i < sqr; i++)
	{
		if (num % i == 0)
		{
			sum += i;
			sum += (num / i);
		}
	}

	if (sqr * sqr == num && num != 1)
	{
		sum += sqr;
	}

	return sum;
}

int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	std::set<int> total;
	for (int i = 3; i < 10000; i++)
	{
		int sum1 = sum_of_divisors(i);
		int sum2 = sum_of_divisors(sum1);
		
		if (i == sum2 && i != sum1)
		{
			//std::cout << i << "\t" << sum1 << std::endl;
			total.emplace(i);
			total.emplace(sum1);			
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	std::cout << "time = " << fp_ms.count() << std::endl;
	std::cout << std::accumulate(std::begin(total), std::end(total), 0) << std::endl;
	return 0;
}
