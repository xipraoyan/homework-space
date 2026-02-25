#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <ctime>
#include <queue>
#include <condition_variable>


struct pahest
{
    std::queue<int> q;
    int size = 5;

    bool isEmpty() const
    {
        return q.empty();
    }
    bool isFull() const
    {
        return q.size() == size;
    }

    void push(int val)
    {
        if(!isFull())
        {
            q.push(val);
            std::cout << "pahest size = " << q.size() << std::endl;
        }
    }
    void pop()
    {
        if(!isEmpty())
        {
            q.pop();
            std::cout << "pahest size = " << q.size() << std::endl;
        }
    }
};

std::condition_variable cv1;
std::condition_variable cv2;
std::mutex mtx;
pahest p;

void producer()
{
    while (true)
    {
        std::unique_lock<std::mutex> ul(mtx);
        cv1.wait(ul, []()
        {
            return !p.isFull();
        });
        p.push(1);
        ul.unlock();
        cv1.notify_all();
    }
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> ul(mtx);
        cv1.wait(ul, []()
        {
            return !p.isEmpty();
        });
        p.pop();
        ul.unlock();
        cv1.notify_all();
    }
}

int main(int argc, char* argv[])
{
    std::thread t1(consumer);
    std::thread t2(producer);
    std::thread t3(consumer);
    std::thread t4(producer);

    cv1.notify_all();

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
