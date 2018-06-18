#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int max = 0;
    const std::string to_check = "123456789";
    for (auto i = 2; i < 10000; i++)
    {
        int cur = 1;
        std::string pan;
        while (pan.length() < 9)
        {
            pan += std::to_string(i * cur++);
        }

        if (pan.length() == 9)
        {
            std::string copy(pan);
            std::sort(copy.begin(), copy.end());

            if (copy == to_check)
            {
                int new_max = std::stoi(pan);
                if (new_max > max)
                {
                    std::cout << i << " -> " << pan << std::endl;
                    max = new_max;
                }
            }
        }
    }

    std::cout << std::endl << max << std::endl;
    return 0;
}
