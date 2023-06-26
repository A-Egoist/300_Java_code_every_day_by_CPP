# 300 Java code every day by CPP
This repository is the CPP implementation of [日撸 Java 三百行](https://blog.csdn.net/minfanphd/article/details/116974889)
## Contents

### Day 1-10

#### Day 1: 在 Visual Studio Code 中配置 CPP 环境

[VSCode配置C/C++环境](https://zhuanlan.zhihu.com/p/87864677)

#### Day 2: basic operation

```c++
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
```

#### Day 3: 
