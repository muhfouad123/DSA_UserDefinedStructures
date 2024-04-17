// DynamicLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class LinkedList
{
private:
    typedef struct node
    {
        int data;
        struct node* nextNode;
    }Node;
    Node* head = nullptr;
public:
    LinkedList()
    {
        std::cout << "\nLinkedList()\n" << std::endl;
    }
    void InsertNodeFromHead(int data)
    {
        Node* temp = new Node{};
        temp->data = data;
        temp->nextNode = head;
        head = temp;
        PrintList();
    }
    void InsertNodeFromTail(int data)
    {
        Node* currentNode = head;
        Node* previousNode = nullptr;
        Node* temp = new Node{};
        if(temp == nullptr)
        {
            /* Do nothing! */
            return;
        }
        else
        {
            temp->data = data;
            while (currentNode != nullptr)
            {
                previousNode = currentNode;
                currentNode = currentNode->nextNode;
            }
            previousNode->nextNode = temp;
            temp->nextNode = currentNode;
        }
        PrintList();
    }
    void DeleteNodeFromHead(void)
    {
        if (IsEmpty())
        {
            std::cout << "List is already empty!" << std::endl;
            std::cout << "Nothing to delete!!" << std::endl;
        }
        else
        {
            head = head->nextNode;
        }
        PrintList();
    }
    void DeleteNodeFromTail(void)
    {
        Node* currentNode = head;
        Node* previousNode = nullptr;

        if(IsEmpty())
        {
            std::cout << "List is already empty!" << std::endl;
            std::cout << "Nothing to delete!!" << std::endl;
        }
        else
        {
            if (currentNode->nextNode == nullptr)
            {
                head = nullptr;
            }
            else
            {
                while (currentNode->nextNode != nullptr)
                {
                    previousNode = currentNode;
                    currentNode = currentNode->nextNode;
                }
                previousNode->nextNode = nullptr;
            }
        }
        PrintList();
    }
    bool IsEmpty(void)
    {
        if(head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void PrintList(void)
    {
        // temp1 == currentNode
        Node* temp1;
        // temp2 == previousNode
        Node* temp2;

        std::cout << "head -> ";

        temp1 = head;
        if(temp1 == nullptr)
        {
            std::cout << "";
        }
        while (temp1 != nullptr)
        {
            std::cout << temp1->data << " -> ";
            temp2 = temp1;
            temp1 = temp1->nextNode;
        }
        std::cout << "null" << std::endl;
    }
    ~LinkedList()
    {
        delete head;
        std::cout << "\n~LinkedList()\n" << std::endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    LinkedList ll;

    ll.PrintList();

    ll.InsertNodeFromHead(10);
    ll.InsertNodeFromHead(20);
    ll.InsertNodeFromHead(30);
    ll.InsertNodeFromHead(40);
    ll.InsertNodeFromHead(50);
    ll.InsertNodeFromHead(60);

    ll.InsertNodeFromTail(10);
    ll.InsertNodeFromTail(20);
    ll.InsertNodeFromTail(30);
    ll.InsertNodeFromTail(40);
    ll.InsertNodeFromTail(50);
    ll.InsertNodeFromTail(60);

    ll.DeleteNodeFromHead();
    ll.DeleteNodeFromTail();

    ll.DeleteNodeFromHead();
    ll.DeleteNodeFromTail();

    ll.DeleteNodeFromHead();
    ll.DeleteNodeFromTail();

    ll.DeleteNodeFromHead();
    ll.DeleteNodeFromTail();

    ll.DeleteNodeFromHead();
    ll.DeleteNodeFromTail();

    ll.DeleteNodeFromHead();
    ll.DeleteNodeFromTail();

    ll.DeleteNodeFromHead();
    ll.DeleteNodeFromTail();
}
