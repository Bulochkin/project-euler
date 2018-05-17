/*

1	=	1
2	=	2
3	=	3
4	=	2 * 2
5	=	5
6	=	2 * 3
7	=	7
8	=	2 * 2 * 2
9	=	3 * 3
10	=	2 * 5

10	-	
9	-	3
8	-	2 , 2
7	-	7
6	-	
5	-	
4	-	


2 , 3 , 2 , 5 , 7 , 2 , 3



2 , 5 , 3 , 3 , 2 , 2 , 7



11	=	11
12	=	2 * 2 * 3
13	=	13
14	=	2 * 7
15	=	3 * 5
16	=	2 * 2 * 2 * 2
17	=	17
18	=	2 * 3 * 3
19	=	19
20	=	2 * 2 * 5

11	-	11
12	-	
13	-	13
14	-	7
15	-	
16	-	

2 , 2 , 3 , 2 , 3 , 5 , 16 , 17 , 18 , 19 , 20




*/



#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

void calculateDividers(int num, int i, std::vector<int>& divs)
{
	if (num == i)
	{
		divs.push_back(i);
		return;
	}

	if (num % i == 0)
	{
		divs.push_back(i);
		calculateDividers(num / i, i, divs);
	}
	else
	{
		calculateDividers(num, ++i, divs);
	}
}

int main()
{
	constexpr int num = 20;
	std::vector<std::vector<int>> allDivs(num - 1);	//	skip 1 , calc 2...num

	for (auto i = 2; i <= num; i++)
	{
		calculateDividers(i, 2, allDivs[i - 2]);
	}

	std::vector<std::pair<int, bool>> scarb;
	for (auto& oneDivs : allDivs)
	{
		for (auto& sc : scarb)
		{
			sc.second = true;
		}

		for (auto it = oneDivs.begin(); it != oneDivs.end(); it++)
		{
			auto pos = std::find_if(scarb.begin(), scarb.end(), [it](const auto& element) { return element.first == *it && element.second; });

			if (pos == scarb.end())
			{
				scarb.emplace_back(*it, false);
			}
			else
			{
				pos->second = false;
			}
		}
	}

	int finalResult = 1;
	for (auto& sc : scarb)
	{
		finalResult *= sc.first;
	}

	std::cout << finalResult << std::endl;
	return 0;
}
