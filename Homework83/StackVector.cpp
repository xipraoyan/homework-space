#include <iostream>
#include <initializer_list>

template <typename T>
class vector
{
private:
    T* m_data = nullptr;
    size_t m_size = 0;
    size_t m_cap = 0;

public:
    vector()
    {

    }

    ~vector()
    {
        delete [] m_data;
    }

    vector(std::size_t size) : m_size(size), m_cap(size * 2), m_data(new T[m_cap])
    {}

    vector(const vector& other) : m_size(other.m_size), m_cap(other.m_cap), m_data(new T[m_cap])
    {
        for(auto i = 0; i < m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }

    vector(const vector&& other) : m_size(other.m_size), m_cap(other.m_cap), m_data(other.m_data)
    {
        other.m_size = 0;
        other.m_cap = 0;
        other.m_data = nullptr;
    }

    vector(std::initializer_list<T> init)
    {
        m_size = init.size();
        m_cap  = init.size() * 2;

        m_data = new T[m_cap];

        for (size_t i = 0; i < init.size(); i++)
        {
           m_data[i] = init.begin()[i];
        }
    }

    auto size() const
    {
        return m_size;
    }

    auto cap() const
    {
        return m_cap;
    }

    void push_back(const T& val)
    {
        if (m_size == m_cap)
        {
            if(m_cap == 0)
            {
                m_cap = 2;
                m_data = new T[m_cap];
            }
            else
            {
                std::cout << "realloc" << std::endl;
                m_cap = m_cap * 2;
                T* temp = new T[m_cap];

                for(auto i = 0; i < m_size; i++)
                {
                    temp[i] = m_data[i];
                }

                delete [] m_data;
                m_data = temp;
            }  
        }
        m_data[m_size++] = val;
    }

    void pop_back()
    {
        if (m_size == 0)
        {
            std::cout << "Vector is empty!" << std::endl;
            return;
        }
        m_size--;
    }

    T back() const
    {
        return m_data[m_size - 1];
    }

    T& operator[](size_t i)
    {
        return m_data[i];
    }

    const T& operator[](size_t i) const
    {
        return m_data[i];
    }
};

template <typename T>
class MyOwnStack : private vector<T>
{
public:
    void push(const T& value)
    {
        vector<T>::push_back(value);
    }

    void pop()
    {
        vector<T>::pop_back();
    }

    T top()
    {
        return vector<T>::back();
    }
};

int main(int argc, char* argv[])
{
    MyOwnStack<int> s;

    s.push(10);
    s.push(20);

    std::cout << s.top() << std::endl; 

    s.pop();
    std::cout << s.top() << std::endl; 

}