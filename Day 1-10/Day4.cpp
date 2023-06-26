#include <iostream>

bool is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    return true;
    return false;
}
int main()
{
    int tempYear = 2021;
    std::cout << tempYear << " is ";
    if (!is_leap_year(tempYear)) std::cout << "Not ";
    std::cout << "a leap year." << std::endl;

    tempYear = 2000;
    std::cout << tempYear << " is ";
    if(!is_leap_year(tempYear)) std::cout << "Not ";
    std::cout << "a leap year." << std::endl;

    tempYear = 2100;
    std::cout << tempYear << " is ";
    if(!is_leap_year(tempYear)) std::cout << "Not ";
    std::cout << "a leap year." << std::endl;

    tempYear = 2004;
    std::cout << tempYear << " is ";
    if(!is_leap_year(tempYear)) std::cout << "Not ";
    std::cout << "a leap year." << std::endl;

    return 0;
}