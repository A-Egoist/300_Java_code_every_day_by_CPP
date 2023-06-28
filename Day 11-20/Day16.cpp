#include <iostream>

int sum_to_n(int n)
{
    if (n <= 0) return 0;
    return n + sum_to_n(n - 1);
}

int fibonacci(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int tempValue = 5;
    std::cout << "0 sum to " << tempValue << " = " << sum_to_n(tempValue) << std::endl;

    tempValue = -1;
    std::cout << "0 sum to " << tempValue << " = " << sum_to_n(tempValue) << std::endl;

    for (int i = 0; i < 10; i ++)
    {
        std::cout << "Fibonacci " << i << ": " << fibonacci(i) << std::endl;
    }

    return 0;
}