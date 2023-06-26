#include <iostream>

int main()
{
    int tempNumber1, tempNumber2;
    
    // try a positive value
    tempNumber1 = 5;
    if (tempNumber1 >= 0)
    {
        tempNumber2 = tempNumber1;
    }
    else
    {
        tempNumber2 = -tempNumber1;
    }
    std::cout << "The absolute value of " << tempNumber1 << " is " << tempNumber2 << std::endl;
    
    // try a negative value
    tempNumber1 = -3;
    if (tempNumber1 >= 0)
    {
        tempNumber2 = tempNumber1;
    }
    else
    {
        tempNumber2 = -tempNumber1;
    }
    std::cout << "The absolute value of " << tempNumber1 << " is " << tempNumber2 << std::endl;

    // Now we use a function for this purpose.
    tempNumber1 = 6;
    std::cout << "The absolute value of " << tempNumber1 << " is " << abs(tempNumber1) << std::endl;
    tempNumber1 = -8;
    std::cout << "The absolute value of " << tempNumber1 << " is " << abs(tempNumber1) << std::endl;
    return 0;
}