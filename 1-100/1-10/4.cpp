#include <iostream>
#include <string>

int main()
{
	int curMax = 0;
	for (auto i = 999; i > 0; i--)
	{
		for (auto j = i; j > 0; j--)
		{
			auto nextMax = i * j;
			auto strNormal = std::to_string(nextMax);
			auto strReverse = strNormal;
			std::reverse(strReverse.begin(), strReverse.end());
			if (strReverse == strNormal)
			{
				if (nextMax > curMax)
				{
					curMax = nextMax;
					std::cout << curMax << "\t"<< i << " " << j << std::endl;
				}
			}
		}
	}

	return 0;
} 