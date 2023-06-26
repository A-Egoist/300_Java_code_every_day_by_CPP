#include <iostream>

int main()
{
    int tempFirstInt, tempSecondInt, tempResultInt;
    double tempFirstDouble, tempSecondDouble, tempResultDouble;
    tempFirstInt = 15;
    tempSecondInt = 4;
    tempFirstDouble = 1.2;
    tempSecondDouble = 3.5;

    // Addition
    tempResultInt = tempFirstInt + tempSecondInt;
    tempResultDouble = tempFirstDouble + tempSecondDouble;
    std::cout << tempFirstInt << " + " << tempSecondInt << " = " << tempResultInt << std::endl;
    std::cout << tempFirstDouble << " + " << tempSecondDouble << " = " << tempResultDouble << std::endl;
    
    // Subtraction
    tempResultInt = tempFirstInt - tempSecondInt;
    tempResultDouble = tempFirstDouble - tempSecondDouble;
    std::cout << tempFirstInt << " - " << tempSecondInt << " = " << tempResultInt << std::endl;
    std::cout << tempFirstDouble << " - " << tempSecondDouble << " = " << tempResultDouble << std::endl;

    // Multiplication
    tempResultInt = tempFirstInt * tempSecondInt;
    tempResultDouble = tempFirstDouble * tempSecondDouble;
    std::cout << tempFirstInt << " * " << tempSecondInt << " = " << tempResultInt << std::endl;
    std::cout << tempFirstDouble << " * " << tempSecondDouble << " = " << tempResultDouble << std::endl;

    // Division
    tempResultInt = tempFirstInt / tempSecondInt;
    tempResultDouble = tempFirstDouble / tempSecondDouble;
    std::cout << tempFirstInt << " / " << tempSecondInt << " = " << tempResultInt << std::endl;
    std::cout << tempFirstDouble << " / " << tempSecondDouble << " = " << tempResultDouble << std::endl;

    // Modulus
    tempResultInt = tempFirstInt % tempSecondInt;
    std::cout << tempFirstInt << " % " << tempSecondInt << " = " << tempResultInt << std::endl;
    return 0;
}