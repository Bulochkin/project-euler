#include <iostream>
#include <numeric>

static constexpr int proceed = 100;
static constexpr int num_size = proceed * 2;

static int _num[num_size] = { 1 };
static int _backup[num_size];

void mult(int times)
{
	memcpy(_backup, _num, sizeof(_num));

	int curr = 1;
	int moving = 0;
	while (curr++ != times)
	{
		for (auto i = 0; i < _countof(_num); i++)
		{
			_num[i] += _backup[i];
			_num[i] += moving;
			moving = _num[i] / 10;
			_num[i] %= 10;
		}
	}
}

void factorial(int n)
{
	if (n != 1)
	{
		mult(n);
		factorial(n - 1);
	}
}

int main()
{
	factorial(proceed);
	std::cout << std::accumulate(std::begin(_num), std::end(_num), 0) << std::endl;

	return 0;
}
