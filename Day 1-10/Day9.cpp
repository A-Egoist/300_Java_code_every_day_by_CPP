#include <iostream>
void while_statement_test()
{
    int tempMax = 100;
    int tempValue = 0;
    int tempSum = 0;
    // Approach 1.
    while (tempSum <= tempMax)
    {
        tempValue ++;
        tempSum += tempValue;
        std::cout << "tempValue = " << tempValue << ", tempSum = " << tempSum << std::endl;
    }
    tempSum -= tempValue;
    std::cout << "The sum not exceeding " << tempMax << " is: " << tempSum << std::endl;
    // Approach 2.
    std::cout << "Alternative approach." << std::endl;
    tempValue = 0;
    tempSum = 0;
    while (true)
    {
        tempValue ++;
        tempSum += tempValue;
        std::cout << "tempValue = " << tempValue << ", tempSum = " << tempSum << std::endl;

        if (tempMax < tempSum)
        {
            break;
        }
    }
    tempSum -= tempValue;
    std::cout << "The sum not exceeding " << tempMax << " is: " << tempSum << std::endl;
}
int main()
{
    while_statement_test();
    return 0;
}