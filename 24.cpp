#include <iostream>
#include <vector>

long factorial(long num)
{
	return (num == 1) ? 1 : num * factorial(num - 1);
}

void permutate(int order, int balance, std::vector<int>& indexes)
{
	long f = factorial(order - 1);
	indexes.push_back(balance / f);
	balance %= f;

	if (balance != 0)
	{
		permutate(order - 1, balance, indexes);
	}
}

int main()
{
	constexpr long order = 10;
	constexpr long index = 1000000 - 1;

	std::vector<int> indexes1;
	permutate(order, index, indexes1);

	std::vector<int> indexes2;
	for (auto i = 0; i < order; i++)
	{
		indexes2.push_back(i);
	}

	for (auto ind : indexes1)
	{
		std::cout << indexes2[ind];
		indexes2.erase(indexes2.begin() + ind);
	}

	for (auto ind : indexes2)
	{
		std::cout << ind;
	}

	std::cout << std::endl;
	return 0;
}
