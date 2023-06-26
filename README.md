# 300 Java code every day by CPP
This repository is the CPP implementation of [日撸 Java 三百行](https://blog.csdn.net/minfanphd/article/details/116974889)
## Contents

### Day 1-10

#### Day 1: 在 Visual Studio Code 中配置 CPP 环境

[VSCode配置C/C++环境](https://zhuanlan.zhihu.com/p/87864677)

#### Day 2: 基本算数运算符

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

#### Day 3: 基本 if 语句

```c++
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
```

#### Day 4: 闰年的计算

```c++
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
```

#### Day 5: 基本 switch 语句

```c++
#include <iostream>

char score_to_level(int score)
{
    char level = 'E';
    score /= 10;
    switch (score)
    {
    case 10:
    case 9:
        level = 'A';
        break;
    case 8:
        level = 'B';
        break;
    case 7:
        level = 'C';
        break;
    case 6:
        level = 'D';
        break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
        level = 'F';
        break;
    default:
        break;
    }
    return level;
}
void score_to_level_test()
{
    int tempScore = 100;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 91;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 82;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 75;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 66;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 52;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 8;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
    tempScore = 120;
    std::cout << tempScore << " to level is " << score_to_level(tempScore) << std::endl;
}

int main()
{
    score_to_level_test();
    return 0;
}
```

#### Day 6: 基本 for 语句

```c++
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
```

#### Day 7: 矩阵元素相加

```c++
#include <iostream>
#include <vector>
int matrix_element_sum(const std::vector<std::vector<int> > &p)
{
    int sum = 0;
    for (int i = 0; i < p.size(); i ++)
    {
        for (int j = 0; j < p[i].size(); j ++)
        {
            sum += p[i][j];
        }
    }
    return sum;
}
void matrix_element_sum_test()
{
    std::vector<std::vector<int> > matrix(3, std::vector<int>(4));
    for (int i = 0; i < matrix.size(); i ++)
    {
        for (int j = 0; j < matrix[i].size(); j ++)
        {
            matrix[i][j] = i * 10 + j;
        }
    }
    std::cout << "The matrix is: " << std::endl;
    for (int i = 0; i < matrix.size(); i ++)
    {
        for (int j = 0; j < matrix[i].size(); j ++)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << "The matrix element sum is: " << matrix_element_sum(matrix) << std::endl;
}
std::vector<std::vector<int> > matrix_addition(const std::vector<std::vector<int> > &a, const std::vector<std::vector<int> > &b)
{
    std::vector<std::vector<int> > c(a.size(), std::vector<int>(a[0].size()));
    for (int i = 0; i < c.size(); i ++)
    {
        for (int j = 0; j < c[0].size(); j ++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
void matrix_addition_test()
{
    std::vector<std::vector<int> > matrix(3, std::vector<int>(4));
    for (int i = 0; i < matrix.size(); i ++)
    {
        for(int j = 0; j < matrix[0].size(); j ++)
        {
            matrix[i][j] = i * 10 + j;
        }
    }
    std::cout << "The matrix is:" << std::endl;
    for (int i = 0; i < matrix.size(); i ++)
    {
        for (int j = 0; j < matrix[0].size(); j ++)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << "The new matrix is:" << std::endl;
    std::vector<std::vector<int> > result = matrix_addition(matrix, matrix);
    for (int i = 0; i < result.size(); i ++)
    {
        for (int j = 0; j < result[0].size(); j ++)
            std::cout << result[i][j] << ' ';
        std::cout << std::endl;
    }
}
int main()
{
    matrix_element_sum_test();
    matrix_addition_test();
    return 0;
}
```

#### Day 8: 矩阵加法

```c++
#include <iostream>
#include <vector>


class Matrix
{
public:
    int rows, cols;
    int **data;
    Matrix(int rows, int cols)
    {
        this->rows = rows, this->cols = cols;
        data = new int*[this->rows];
        for (int i = 0; i < this->rows; i ++)
        {
            data[i] = new int[this->cols]{0};
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < this->rows; i ++)
            delete []this->data[i];
        delete []this->data;
    }
    Matrix operator*(const Matrix& b)
    {
        if (this->cols != b.rows)
        {
            throw "The columns of the first matrix not equal the rows of the second matrix.";
        }
        Matrix result(this->rows, b.cols);
        for (int i = 0; i < this->rows; i ++)
        {
            for (int j = 0; j < b.cols; j ++)
            {
                for (int k = 0; k < this->cols; k ++)
                {
                    result.data[i][j] += this->data[i][k] * b.data[k][j];
                }
            }
        }
        return result;
    }
};


void matrix_multiplication_test()
{
    Matrix matrix1(2, 3);
    for (int i = 0; i < matrix1.rows; i ++)
        for (int j = 0; j < matrix1.cols; j ++)
            matrix1.data[i][j] = i + j;
    std::cout << "The First matrix is: " << std::endl;
    for (int i = 0; i < matrix1.rows; i ++)
    {
        for (int j = 0; j < matrix1.cols; j ++)
            std::cout << matrix1.data[i][j] << ' ';
        std::cout << std::endl;
    }
    Matrix matrix2(3, 2);
    for (int i = 0; i < matrix2.rows; i ++)
        for (int j = 0; j < matrix2.cols; j ++)
            matrix2.data[i][j] = i * 10 + j;
    std::cout << "The Second matrix is: " << std::endl;
    for (int i = 0; i < matrix2.rows; i ++)
    {
        for (int j = 0; j < matrix2.cols; j ++)
            std::cout << matrix2.data[i][j] << ' ';
        std::cout << std::endl;
    }
    try
    {
        Matrix result = matrix1 * matrix2;
        std::cout << "The result matrix of the first matrix multiplied the second matrix is:" << std::endl;
        for (int i = 0; i < result.rows; i ++)
        {
            for (int j = 0; j < result.cols; j ++)
                std::cout << result.data[i][j] << ' ';
            std::cout << std::endl;
        }

        result = matrix1 * matrix1;
        std::cout << "The result matrix of the first matrix multiplied itself is:" << std::endl;
        for (int i = 0; i < result.rows; i ++)
        {
            for (int j = 0; j < result.cols; j ++)
                std::cout << result.data[i][j] << ' ';
            std::cout << std::endl;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << std::endl;
    }
}
int main()
{
    matrix_multiplication_test();
    return 0;
}
```

#### Day 9: while 语句

```c++
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
```

#### Day 10: 综合任务 1



```c++
```

