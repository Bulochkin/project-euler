#include <iostream>

int main()
{
    int leftUp = 2, leftDown = 5;
    const int rightUp = 3, rightDown = 7;

    while ((leftDown + rightDown) <= 1000000)
    {
        leftUp += rightUp;
        leftDown += rightDown;
    }

    std::cout << leftUp << " / " << leftDown << std::endl;
    return 0;
}
