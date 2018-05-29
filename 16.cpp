#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	constexpr int power = 1000;
	int num[power / 2] = { 1 };

	int curr = 0;
	int moving = 0;
	while (curr++ != power)
	{
		for (auto i = 0; i < _countof(num); i++)
		{
			num[i] += num[i];
			num[i] += moving;
			moving = num[i] / 10;
			num[i] %= 10;
		}
	}

	for (auto i = 0; i < _countof(num); i++)
	{
		std::cout << num[i] << " ";
	}

	std::cout << std::endl << std::accumulate(std::begin(num), std::end(num), 0) <<  std::endl;
	return 0;
}
