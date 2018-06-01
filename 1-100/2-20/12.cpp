#include <iostream>

int dividers(long num)
{
	int total = 2;
	long sqr = (long)std::sqrt(num);
	for (auto i = 2; i < sqr; i++)
	{
		if (num % i == 0)
		{
			total+= 2;
		}
	}

	if (sqr * sqr == num)
	{
		total--;
	}

	return total;
}

int main()
{
	for (long i = 3; ; i++)
	{
		auto dvs = dividers(i * (i + 1) / 2);
		if (dvs > 500)
		{
			std::cout << i * (i + 1) / 2 << std::endl;
			break;
		}
	}
	return 0;
}
