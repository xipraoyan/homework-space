#include <iostream>
#include <string>
#include <unordered_set>

class Animal
{
public:
    std::string m_type;
    int m_age;

    Animal(const std::string& t, int a) 
          : m_type(t), m_age(a) 
    {}


    struct CustomHash
    {
        std::size_t operator()(const Animal& a) const
        {
            std::size_t h2 = std::hash<std::string> ()(a.m_type);
            std::size_t h1 = std::hash<int> ()(a.m_age);

            return h1 ^ h2;
        }
    };

    bool operator == (const Animal& a) const
    {
        return this -> m_type == other.m_type && this -> m_age == other.m_age;
    }

};

int main(int argc, char* argv[])
{
    AnimalHash callableobj;

    std::unordered_set<Animal, decltype(callableobj)> animals(callableobj);

    animals.insert(Animal("dog", 3));
    animals.insert(Animal("horse", 6));
    animals.insert(Animal("cat", 5));

    for(const auto& animal : animals)
    {
        std::cout << animal.m_type << " " << animal.m_age << std::endl;
    }

    return 0;
}
