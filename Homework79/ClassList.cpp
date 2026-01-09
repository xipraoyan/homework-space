#include <iostream>

namespace ACA
{
    class List
    {
    private:
        struct Node
        {
            int data;
            Node* next;

            Node(int value)
            {
                data = value;
                next = nullptr;
            }
        };

        Node* head;

    public:
        List()
        {
            head = nullptr;
        }

        void push_front(int value)
        {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        void pop_front()
        {
            if (head == nullptr)
            {
                std::cout << "List is empty" << std::endl;
            }

            Node* temp = head;
            head = head->next;
            delete temp;
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
            
        }
    };
}

int main()
{
    ACA::List list;

    list.push_front(30);
    list.push_front(20);
    list.push_front(10); 
    list.print();  


    list.pop_front();     
    list.print();

    return 0;
}
