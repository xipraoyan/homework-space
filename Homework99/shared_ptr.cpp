#include <iostream>

template <typename T>
class shared_ptr
{
    T* m_ptr;
    std::size_t* m_refcount;

    void reset()
    {
        if(m_refcount)
        {
            --(*m_refcount);

            if(*m_refcount == 0)
            {
                delete m_ptr;
                delete m_refcount;
            }
        }
        m_ptr = nullptr;
        m_refcount = nullptr;  
    }

public:
    shared_ptr() : m_ptr(nullptr), m_refcount(nullptr)
    {
       
    }

    explicit shared_ptr(T* ptr) : m_ptr(ptr), m_refcount(new std::size_t(1))
    {

    }

    shared_ptr(const shared_ptr& other) 
    {
        this->m_ptr = other.m_ptr;
        this->m_refcount = other.m_refcount;
        ++(*m_refcount);
    }

    shared_ptr& operator = (const shared_ptr& other)
    {
        if(this != &other)
        {
            reset();
            this->m_ptr = other.m_ptr;
            this->m_refcount = other.m_refcount;
            ++(*m_refcount);
        }
        return *this;
    }
    shared_ptr(shared_ptr&& other) : m_ptr(other.m_ptr), m_refcount(other.m_refcount)
    {
        other.m_ptr = nullptr;
        other.m_refcount = nullptr;
    }

    shared_ptr& operator = (shared_ptr&& other)
    {
        if(this != &other)
        {
            reset();
            this->m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
            this->m_refcount = other.m_refcount;
            other.m_refcount = nullptr;
        }
        return *this;
    }

    T& operator *()
    {
        return *m_ptr;
    }

    T operator*() const 
    { 
        return *m_ptr; 
    }

    T* operator -> ()
    {
        return m_ptr;
    }   

    const T* operator -> () const 
    { 
        return m_ptr; 
    }

    auto get_count() const
	{
		return m_refcount ? *m_refcount : 0; 
	}

     ~shared_ptr()
    {
        reset();
    }
}; 

class A 
{
public:
    A()
    {
        std::cout << "A is created" << "\n";
    }

    ~A()
    {
        std::cout << "A is destroyed" << "\n";
    }
};

int main(int argc, char* argv[])
{
    shared_ptr<A> sptr1(new A());
    shared_ptr<A> sptr2 = sptr1;
    shared_ptr<A> sptr3;
    sptr3 = sptr1;
    std::cout << "sptr1 count: " << sptr1.get_count() << "\n";

    shared_ptr<A> sptr4 = std::move(sptr1);
    shared_ptr<A> sptr5(new A());
    sptr4 = std::move(sptr5);
    std::cout << "sptr5 count: " << sptr5.get_count() << "\n";

}