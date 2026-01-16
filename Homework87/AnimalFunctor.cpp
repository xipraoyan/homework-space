#include <iostream>
#include <string>
#include <set>

class Animal
{
public:
    std::string m_type;
    int m_age;

    Animal(const std::string& t, int a) 
          : m_type(t), m_age(a) 
    {}
};

struct AnimalCompare
{
    bool operator()(const Animal& a, const Animal& b) const
    {
        return a.m_type < b.m_type;

        return a.m_age < b.m_age;
    }
};

int main(int argc, char* argv[])
{
    AnimalCompare callableobj;

    std::set<Animal, decltype(callableobj)> animals(callableobj);

    animals.insert(Animal("dog", 3));
    animals.insert(Animal("horse", 6));
    animals.insert(Animal("cat", 5));

    for (const auto& animal : animals)
    {
        std::cout << animal.m_type << " " << animal.m_age << std::endl;
    }

    return 0;
}
