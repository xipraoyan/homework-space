#include <iostream>

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(int value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(const T& value)
    {
        Node* newNode = new Node(value);
        if (!head)  
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;

    }

    void push_front(const T& value)
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    T front() const
    {
        return head->data;
    }

    T back() const
    {
        return tail->data;
    }

    void print() const
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~List()
    {
        while (head)
        {
            pop_front();
        }
    }
};

template <typename T>
class MyOwnQueue : private List<T>
{
public:
    void enqueue(const T& value)
    {
        List<T>::push_back(value);
    }

    void dequeue()
    {
        List<T>::pop_front();
    }

    T front()
    {
        return List<T>::front();
    }

    T back()
    {
        return List<T>::back();
    }
};

int main(int argc, char* argv[])
{
    MyOwnQueue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << q.front() << std::endl; // 10
    std::cout << q.back() << std::endl;  // 30

    q.dequeue();
    std::cout << q.front() << std::endl; // 20
}