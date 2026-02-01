#include <iostream>

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
        if(s > m_size)
        {
            throw "your number is greater than size";
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
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    } 
}