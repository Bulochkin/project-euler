#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main()
{
	std::ifstream ifs ("p022_names.txt");
	if (!ifs.is_open())
	{
		return -1;
	}

	std::string name;
	std::set<std::string> names;
	while (ifs.good())
	{
		std::getline(ifs, name, ',');
		names.emplace(name);
	}
	ifs.close();

	int current = 1;
	long long score = 0;
	for (auto& name : names)
	{
		int sum = 0;
		for (auto i = 1; i < name.length() - 1; i++)
		{
			sum += (name[i] - 64);
		}
		score += sum * current++;
	}

	std::cout << score << std::endl;
	return 0;
}
