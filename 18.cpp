#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>

int main()
{ 
	auto t1 = std::chrono::high_resolution_clock::now();

	std::vector<int> nums[] = 
	{
		{ 75 } ,
		{ 95, 64 } ,
		{ 17, 47, 82 } ,
		{ 18, 35, 87, 10 } ,
		{ 20, 4, 82, 47, 65 } ,
		{ 19, 1, 23, 75, 3, 34 } ,
		{ 88, 2, 77, 73, 7, 63, 67 } ,
		{ 99, 65, 4, 28, 6, 16, 70, 92 } ,
		{ 41, 41, 26, 56, 83, 40, 80, 70, 33 } ,
		{ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 } ,
		{ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 } ,
		{ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 } ,
		{ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 } ,
		{ 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 } ,
		{ 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23 } 
	};

	std::multimap<int, int> next_sums;
	std::multimap<int, int> prev_sums = { {0 , nums[0][0] } };
	
	for (auto i = 1; i < _countof(nums); i++)
	{
		for (auto j = 0 ; j < prev_sums.size() ; j++)
		{
			auto range = prev_sums.equal_range(j);
			for (auto it = range.first; it != range.second; it++)
			{
				next_sums.emplace(j, it->second + nums[i][j]);
				next_sums.emplace(j + 1, it->second + nums[i][j + 1]);
			}
		}

		prev_sums = next_sums;
		next_sums.clear();
	}

	auto x = std::max_element(prev_sums.begin(), prev_sums.end(), [](const auto& p1, const auto& p2)
	{
		return p1.second < p2.second; 
	});

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	std::cout << "Time ms = " << fp_ms.count() << std::endl;
	std::cout << x->second << std::endl;

	return 0;
}
