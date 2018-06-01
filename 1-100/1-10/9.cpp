#include <iostream>

int main()
{
	for (int a = 999 ; a > 0 ; a--)
	{
		for (int b = a - 1 ; b > 0 ; b--)
		{
			for (int c = b - 1 ; c > 0 ; c--)
			{
				if (((c * c + b * b) == a * a) && ((a + b + c) == 1000))
				{
					std::cout << a << " " << b << " " << c << " " << a * b * c << std::endl;
					break;
				}
			}
		}
	}

	return 0;
}
 