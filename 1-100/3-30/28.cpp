#include <iostream>

int main()
{
	long sum = 1;
	for (long i = 0 , shift = 2 , start = 1 ; i < 1001 / 2 ;  i++, shift += 2)
	{
	  start += shift;
		sum += start;

		start += shift;
		sum += start;

		start += shift;
		sum += start;

		start += shift;
		sum += start;
	}

	std::cout << sum << std::endl;
	return 0;
}
