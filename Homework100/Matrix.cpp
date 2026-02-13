#include <iostream>
#include <memory>

template <typename T>
class Matrix
{
private:
    std::size_t m_col;
    std::size_t m_row;
    std::unique_ptr<std::unique_ptr<T[]>[]> m_arr;

public:
    Matrix(std::size_t col, std::size_t row) 
        : m_col(col), m_row(row)
    {    
      m_arr = std::make_unique<std::unique_ptr<T[]>[]>(m_col);

      for(int i = 0; i < m_col; i++)
      {
        m_arr[i] = std::make_unique<T[]>(m_row);

        for(int j = 0; j < m_row; j++)
        {
          m_arr[i][j] = rand() % 10;
        }
      } 
    }

    Matrix(const Matrix& other)
        : m_col(other.m_col), m_row(other.m_row)
    {
      m_arr = std::make_unique<std::unique_ptr<T[]>[]>(m_col);

      for(int i = 0; i < m_col; i++)
      {
        m_arr[i] = std::make_unique<T[]>(m_row);

        for(int j = 0; j < m_row; j++)
        {
          m_arr[i][j] = other.m_arr[i][j];
        }
      }
    }

    Matrix& operator = (const Matrix& other)
    {
      if(this != &other)
      {
        this -> m_row = other.m_row;
        this -> m_col = other.m_col;

        this -> m_arr = std::make_unique<std::unique_ptr<T[]>[]>(m_col);

        for(int i = 0; i < m_col; i++)
        {
          m_arr[i] = std::make_unique<T[]>(m_row);

          for(int j = 0; j < m_row; j++)
          {
            m_arr[i][j] = other.m_arr[i][j];
          }
        }  
      }
      return *this;
    }

    Matrix(Matrix&& other) noexcept
        : m_col(other.m_col),
          m_row(other.m_row),
          m_arr(std::move(other.m_arr))
    {
        other.m_col = 0;
        other.m_row = 0;
    }

    Matrix& operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            m_col = other.m_col;
            m_row = other.m_row;
            m_arr = std::move(other.m_arr);

            other.m_col = 0;
            other.m_row = 0;
        }
        return *this;
    }

    void print() const
    {
      for(int i = 0; i < m_col; i++)
      {
        for(int j = 0; j < m_row; j++)
        {
          std::cout << m_arr[i][j] << " ";
        }
        std::cout << std::endl;
      }
    }
   
    ~Matrix()
    {

    }
};

int main(int argc, char* argv[])
{
   Matrix<int> a(3, 3);
   a.print();
   std::cout << std::endl;

   Matrix<int> b = a;   
   b.print();

   std::cout << std::endl;
   Matrix<int> c = std::move(a);  
   c.print();

    return 0;
}
