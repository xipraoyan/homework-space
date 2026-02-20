#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
public:
    int m_col;
    int m_row;
    int** m_arr;

public:
    Matrix();
    Matrix(int a, int b);

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    Matrix(Matrix&& tmp) noexcept;
    Matrix& operator=(Matrix&& tmp) noexcept;

    virtual void print();

    virtual ~Matrix();

};

class ChessBoard : public Matrix
{
public:
  ChessBoard();

  ChessBoard(ChessBoard&& tmp) noexcept;
  ChessBoard& operator=(ChessBoard&& tmp) noexcept;

  void initBoard();
  void print() override;
  ~ChessBoard() override;

};

#endif                 