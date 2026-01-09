#include <iostream>

template <typename T>
class SinglyLinkedList 
{
private:
    struct Node 
    {
      T data;         
      Node* next;       

    
      Node(const T& val) 
      {
        data = val;
        next = nullptr;
      }
    };

    Node* head;

public:
    SinglyLinkedList() 
    {
        head = nullptr;
    }

    void insertAtHead(const T& data) 
    {
        Node* newNode = new Node(data);
        newNode -> next = head; 
        head = newNode;       
    }

    void printList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            std::cout << current -> data << " -> ";
            current = current -> next; 
        }
        std::cout << "end" << std::endl;
    }
};

int main(int argc, char* argv[]) 
{
    SinglyLinkedList<int> list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    list.printList(); 

    return 0;
}
