#include <iostream>
#include <string>
#include <vector>

void push_hundreds(std::vector<std::string>& digits)
{
	for (auto i = 1; i < 10; i++)
	{
		std::string prefix = digits[i] + "hundred";
		digits.push_back(prefix);
		for (auto j = 1; j < 100; j++)
		{
			digits.push_back(prefix + "and" + digits[j]);
		}
	}
}

void push_tens(std::string& prefix, std::vector<std::string>& digits)
{
	digits.push_back(prefix);
	for (auto i = 1; i < 10; i++)
	{
		digits.push_back(prefix + digits[i]);
	}
}

int main()
{
	std::vector<std::string> digits;

	digits.push_back("");
	digits.push_back("one");
	digits.push_back("two");
	digits.push_back("three");
	digits.push_back("four");
	digits.push_back("five");
	digits.push_back("six");
	digits.push_back("seven");
	digits.push_back("eight");
	digits.push_back("nine");
	digits.push_back("ten");
	digits.push_back("eleven");
	digits.push_back("twelve");
	digits.push_back("thirteen");
	digits.push_back("fourteen");
	digits.push_back("fifteen");
	digits.push_back("sixteen");
	digits.push_back("seventeen");
	digits.push_back("eighteen");
	digits.push_back("nineteen");

	push_tens(std::string("twenty"), digits);
	push_tens(std::string("thirty"), digits);
	push_tens(std::string("forty"), digits);
	push_tens(std::string("fifty"), digits);
	push_tens(std::string("sixty"), digits);
	push_tens(std::string("seventy"), digits);
	push_tens(std::string("eighty"), digits);
	push_tens(std::string("ninety"), digits);

	push_hundreds(digits);
	digits.push_back("onethousand");

	size_t total = 0;
	for (const auto& str : digits)
	{
		total += str.length();
	}

	std::cout << total << std::endl;
	return 0;
}
