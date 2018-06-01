#include <iostream>

int main()
{
	auto start1 = 0;
	auto start2 = 1;

	auto currentSum = 0;
	auto currentFib = start1 + start2;
	while(currentFib < 4000000)
	{
		start1 = start2;
		start2 = currentFib;

		//std::cout << currentFib << std::endl;
		currentFib = start1 + start2;

		if (currentFib % 2 == 0)
		{
			currentSum += currentFib;
		}
	}

	std::cout << currentSum << std::endl;
	return 0;
}
