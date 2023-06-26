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