#include <iostream>

class MyException : public std::exception
{
    std::string m_inform;
public:
    MyException(std::string inform) : m_inform(inform)
    {

    }

    const char* what() const noexcept
    {
        return m_inform.c_str();
    }
};

template <typename T>
class Vector
{
private:
    T* m_data = nullptr;
    size_t m_size = 0;
public: 
    Vector(T* data, size_t size) : m_data(data), m_size(size) {}

    auto size() const
    {
        return m_size;
    }

    T& at(size_t s)
    {
        if(s >= m_size)
        {
            throw MyException("num is greater than size");
        }
        return m_data[s];
    }
};

int main(int argc, char* argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Vector<int> vec(arr, 10);

    try
    {
       std::cout << vec.at(1) << std::endl;
       std::cout << vec.at(11) << std::endl;
    } 
    catch(const MyException& ex)
    {
        std::cout << ex.what() << std::endl;
    } 
}
