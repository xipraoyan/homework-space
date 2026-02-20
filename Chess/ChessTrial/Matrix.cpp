#include "Matrix.h"
#include <iostream>

//******PARAM CTOR*******
Matrix::Matrix(int a, int b)
{
    //std::cout << __func__ << std::endl;
    m_col = a;
    m_row = b;
        
    m_arr = new int* [m_col];
    for(int i = 0; i < m_col; i++)
    {
        m_arr[i] = new int[m_row];
        for(int j = 0; j < m_row; j++)
        {
            m_arr[i][j] = 0;
        }
    } 
}

//******COPY CTOR*******
Matrix::Matrix(const Matrix& other)
{
    //std::cout << __func__ << std::endl;
    m_row = other.m_row;
    m_col = other.m_col;

    m_arr = new int* [m_col];
    for(int i = 0; i < m_col; i++)
    {
        m_arr[i] = new int[m_row];
        for(int j = 0; j < m_row; j++)
        {
            m_arr[i][j] = other.m_arr[i][j];
        }
    }
}

//******OPERATOR =******
Matrix& Matrix::operator=(const Matrix& other) 
{
    //std::cout << __func__ << std::endl;
    if(this != &other)
    {
        for (int i = 0; i < m_col; ++i) 
        {
            delete [] m_arr[i];
        }
        delete [] m_arr;

        this -> m_row = other.m_row;
        this -> m_col = other.m_col;

        this -> m_arr = new int* [m_col];
        for(int i = 0; i < m_col; i++)
        {
            m_arr[i] = new int[m_row];
            for(int j = 0; j < m_row; j++)
            {
                m_arr[i][j] = other.m_arr[i][j];
            }
        }
    }
    return *this;
}

//******MOVE CTOR*******
Matrix::Matrix(Matrix&& tmp) noexcept 
    :   m_col(std::move(tmp.m_col)),
        m_row(std::move(tmp.m_row)),
        m_arr(std::move(tmp.m_arr))
{
    tmp.m_arr = nullptr;
    tmp.m_row = 0;
    tmp.m_col = 0;
}

//******MOVE OPERATOR =*******
Matrix& Matrix::operator=(Matrix&& tmp) noexcept
{
    if(this != &tmp)
    {
        this -> m_col = std::move(tmp.m_col);
        this -> m_row = std::move(tmp.m_row);
        this -> m_arr = std::move(tmp.m_arr);

        tmp.m_arr = nullptr;
        tmp.m_row = 0;
        tmp.m_col = 0;
    }
    return *this;
}

//******DTOR*******
Matrix::~Matrix()  
{
    //std::cout << __func__ << std::endl;
    for (int i = 0; i < m_col; ++i) 
    {
        delete [] m_arr[i];
    }
    delete [] m_arr;
}

//******MATRIX/CHESSBOARD PRINT FUNC*******
void Matrix::print()
{
    std::cout << "      ";
    for(int i = 0; i < m_col; i++)
    {
        std::cout << (char)('A' +  i) << "     ";
    }
    std::cout << std::endl;
    std::cout << "   +—————+—————+—————+—————+—————+—————+—————+—————+" << std::endl;

    for(int i = 0; i < m_col; i++)
    {
        int boardNumber = m_col - i;
        std::cout << boardNumber << " " << " | " ;

        for(int j = 0; j < m_row; j++)
        {
            std::cout << " " << m_arr[i][j] << " ";
            std::cout << " | " ;
        }

        std::cout << boardNumber << " ";

        std::cout << std::endl;
        std::cout << "   +—————+—————+—————+—————+—————+—————+—————+—————+" << std::endl;
    }

    std::cout << "      ";
    for(int i = 0; i < m_col; i++)
    {
        std::cout << (char)('A' +  i) << "     ";
    }
    std::cout << std::endl;
}         