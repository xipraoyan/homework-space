#include <iostream>
#include <stdexcept>
#include <thread>
#include <atomic>
#include <chrono>
#include <ctime>
#include <vector>
#include <mutex>
#include <future>

std::vector<long long> memo(100001, -1);
std::vector<long long> memo2(1000001, -1);

std::mutex mtx;

long long fibo(int n)
{
    if(n < 0) return 0;

    for(auto i = 2; i <= n; ++i)
    {
        memo[i] = memo[i-1] + memo[i-2];
    }

    return memo[n];
}

long long fibo2(int n)
{
    if(n < 0) return 0;

    if(-1 != memo2[n]) return memo2[n];

    for(auto i = 2; i <= n; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        memo2[i] = memo2[i-1] + memo2[i-2];
    }

    return memo2[n];
}

bool iscorrect(const auto& vec1, const auto& vec2)
{
    if(vec1.size() != vec2.size()) return false;

    for(auto i = 0; i < vec1.size(); ++i)
    {
        if(vec1[i] != vec2[i]) return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    std::srand(std::time(0));
    memo[0] = 1;
    memo[1] = 1;
    memo2[0] = 1;
    memo2[1] = 1;

    auto start{std::chrono::steady_clock::now()};
    for(int i = 0; i < 100; ++i)
    {
        fibo(i);
    }
    auto finish{std::chrono::steady_clock::now()};

    std::chrono::duration<double> elapsed_seconds{finish - start};
    std::cout << elapsed_seconds << std::endl;


    start = {std::chrono::steady_clock::now()};
    std::vector<std::future<long long>> vecfut;
    for(int i = 0; i < 1000; ++i)
    {
        auto index = std::rand() % 1000;
        vecfut.emplace_back(std::async(std::launch::async, fibo2, index));
    }
    for(auto & in : vecfut)
    {
        in.get();
    }
    finish = {std::chrono::steady_clock::now()};

    elapsed_seconds = {finish - start};
    std::cout << elapsed_seconds << std::endl;

    if(iscorrect(memo, memo2))
    {
        std::cout << "correct" << std::endl;
    }
    else    
    {
        std::cout << "incorrect" << std::endl;
    }

    return 0;

}