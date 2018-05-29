#include <iostream>

//#define VIA_BRUTFORCE
#ifdef VIA_BRUTFORCE

const long long stop = 20;

long long routes(long long x, long long y)
{
	if (y + 1 == stop && x == stop)
	{
		return 1;
	}

	if (x + 1 == stop && y == stop)
	{
		return 1;
	}

	long long curr = 0;

	if (x + 1 <= stop)
	{
		curr += routes(x + 1, y);
	}

	if (y + 1 <= stop)
	{
		curr += routes(x, y + 1);
	}

	return curr;
}

int main()
{
	std::cout << routes(0, 0) << std::endl;
	return 0;
}

#else

int main()
{
	//	make some magic - PASCAL triangle
	constexpr auto res = 4LLU * 23LLU * 29LLU * 31LLU * 33LLU * 35LLU * 37LLU * 39LLU;
	std::cout <<  res << std::endl;
	return 0;
}

#endif