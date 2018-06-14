#include <iostream>
#include <vector>

int main()
{
	constexpr int days_norm[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	constexpr int days_leap[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	auto result = 0;
	auto start = (4 * 30 + 7 * 31 + 28) % 7;
	for (auto i = 1901; i < 2001; i++)
	{
		auto* ptr_days = i % 4 ? days_norm : days_leap;
		for (auto j = 0; j < 12; j++)
		{
			start = (start + ptr_days[j]) % 7;
			if (start == 6)
			{
				result++;
			}
		}
	}

	std::cout << result << std::endl;
	return 0;
}
