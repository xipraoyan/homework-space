#include <iostream>
#include <functional>

int main(int argc, char* argv[])
{
    std::function<std::function<int(int)>(int)> f;
    
    f = [](int a)
        {
            return [a](int b)
            {
                return a * b;
            };
        };

    std::cout << f(5)(6) << std::endl;

    return 0;
}