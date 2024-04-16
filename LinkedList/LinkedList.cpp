// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

constexpr auto DELETE = (char)'d';
constexpr auto CREATE = (char)'c';
constexpr auto EXIT = (char)'e';

typedef struct node
{
    int data;
    struct node* next;
}Node; 

static void InsertNode(Node** pointerToHead, int newData)
{
    /* 1- Dynamically allocate a node */
    Node* newNode = (Node*)malloc(sizeof(Node));

    /* 2- Validate the node, and if it's not a null pointer, assign the new data to the data part of the node */
    if(newNode != nullptr)
    {
        newNode->data = newData;
    }

    /* 3- Validate the node, and if it's not a null pointer, let the "next" part of the node point to head */
    if (newNode != nullptr)
    {
        newNode->next = *pointerToHead;
    }

    /* 4- Move the head to point to the new node */
    *pointerToHead = newNode;
}

static void DeleteNode(Node** pointerToHead)
{
    /* 1- Declare a temporary pointer that points to the "Node", and assign the head to that temp */
    Node* temp = *pointerToHead;
    
    /* 2- Let head point to the next node, i.e. second node */
    if(*pointerToHead == nullptr)
    {
        printf("Node already deleted!");
    }
    else
    {
        *pointerToHead = (*pointerToHead)->next;
    }
}

static void PrintList(Node** pointerToHead)
{
    Node* temp = *pointerToHead;
    printf_s("\nList is: ");
    while(temp != nullptr)
    {
        printf_s("    %d", temp->data);
        temp = temp->next;
    }
    if(*pointerToHead == nullptr)
    {
        printf_s(" empty! \n");
    }
    printf_s("\n");
}

int main(void)
{
    std::cout << "Hello World!" << std::endl;

    Node* head = nullptr;
    auto operation = 0;
    int x = 0;

    while(operation != EXIT)
    {
        printf_s("Create or Delete? ");
        operation = getchar();

        switch(operation)
        {
        case CREATE:
            printf_s("Enter the number: ");
            scanf_s("%d", &x);
            printf_s("\n");
            InsertNode(&head, x);
            PrintList(&head);
            break;

        case DELETE:
            DeleteNode(&head);
            PrintList(&head);
            break;

        default:
            break;
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
