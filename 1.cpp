#include <iostream>

int main()
{
	int currentSum = 0;

	for (auto i = 0; i < 1000; i++)
	{
		if (i % 5 == 0 || i % 3 == 0)
		{
			currentSum += i;
		}
	}

	std::cout << currentSum << std::endl;
	return 0;
}