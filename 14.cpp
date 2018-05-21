#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <chrono>
#include <algorithm>

//#define SMART_PROCESS
#ifdef SMART_PROCESS

static std::map<long long, long> items;
long collatz(long long num)
{
	if (num == 1)
	{
		return 0;
	}

	auto pos = items.find(num);
	if (pos != items.end())
	{
		return pos->second;
	}

	long long next = (num % 2) ? (num = num * 3 + 1) : (num /= 2);
	long chain = collatz(next) + 1;

	items[num] = chain;

	return chain;
}

int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	long max = 0;
	long long num = 0;
	for (long long i = 3; i < 999999; i += 2)
	{		
		long res = collatz(i);
		if (res > max)
		{
			max = res;
			num = i;
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	std::cout << "Max = " << num << " time ms = " << fp_ms.count() << std::endl;
}

#else

long collatz(long long num, long chain)
{
	if (num == 1)
	{
		return chain;
	}

	if (num % 2)
	{
		num += (num << 1) + 1;
	}
	else
	{
		num >>= 1;
	}

	return collatz(num, ++chain);
}

int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	long max = 0;
	long long num = 0;
	for (long long i = 3; i < 999999; i += 2)
	{
		long res = collatz(i, 1);
		if (res > max)
		{
			max = res;
			num = i;
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	std::cout << "Max = " << num << " time ms = " << fp_ms.count() << std::endl;
}

#endif