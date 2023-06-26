#include <iostream>
int add_to_n(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += i;
    return sum;
}
int add_to_n(int n, int step)
{
    int sum = 0;
    for (int i = 1; i <= n; i += step)
        sum += i;
    return sum;
}
void for_statement_test()
{
    int tempN = 10;
    std::cout << "1 add to " << tempN << " is " << add_to_n(tempN) << std::endl;
    
    tempN = 0;
    std::cout << "1 add to " << tempN << " is " << add_to_n(tempN) << std::endl;

    int tempStepLength = 1;
    tempN = 10;
    std::cout << "1 add to " << tempN << " with step length " << tempStepLength << " is " << add_to_n(tempN, tempStepLength) << std::endl;

    tempStepLength = 2;
    std::cout << "1 add to " << tempN << " with step length " << tempStepLength << " is " << add_to_n(tempN, tempStepLength) << std::endl;
}
int main()
{
    for_statement_test();
    return 0;
}