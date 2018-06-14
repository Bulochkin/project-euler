#include <iostream>
#include <vector>

int fib(int border)
{
	std::vector<int> a(border) , b(border), c(border);
	a[0] = b[0] = 1;

	int index = 2;
	for (index ; !b[b.size() - 1] ; index++)
	{
		int curr = 1, moving = 0;
		std::vector<int> c = a;
		for (auto i = 0; i < a.size(); i++)
		{
			c[i] += b[i];
			c[i] += moving;
			moving = c[i] / 10;
			c[i] %= 10;
		}

		a = std::move(b);
		b = std::move(c);
	}
	return index;
}

//long long fib(long long n)
//{
//	long long a = 1, b = 1;
//	for (long long i = 3; i <= n; i++) 
//	{
//		long long c = a + b;
//		a = b;
//		b = c;
//	}
//	return b;
//}

int main()
{	
	std::cout << fib(1000) << std::endl; 
	return 0;
}
