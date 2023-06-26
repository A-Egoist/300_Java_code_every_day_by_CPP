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