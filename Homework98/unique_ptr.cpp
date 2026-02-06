#include <iostream>
#include <memory>

template <typename T>
class unique_ptr
{
    T* m_ptr;
public:
    unique_ptr() : m_ptr(nullptr)
    {

    }

    unique_ptr(T* ptr) : m_ptr(ptr)
    {

    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator = (const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& other)
    {
        this->m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    unique_ptr& operator = (unique_ptr&& other)
    {
        if(this != other)
        {
            delete this->m_ptr;
            this->m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    T& operator *()
    {
        return *m_ptr;
    }

    const T& operator *() const
    {
        return *m_ptr;
    }

    T* operator ->()
    {
        return m_ptr;
    }

    T operator ->() const
    {
        return m_ptr;
    }

    ~unique_ptr()
    {
        delete m_ptr;
    }
};

int main(int argc, char* argv[])
{
    unique_ptr<int> ptr(new int(17));

    std::cout << *ptr << std::endl;

    return 0;
}