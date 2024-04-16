// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>

template<typename T> class Stack
{
private:
    //T* top = nullptr;
    int top = -1;
    T* base = nullptr;
    //int count = 0;
    int i;
    int size;
public:
    Stack(int size) : size(size)
    {
        /* 1- Create array DS dynamically and initialize it with zero */
        base = new T[size]{};

        /* 2- Print the stack elements */
        printStack();

        /* 3- Let the pointer "top" points to a step before the base of the array and 
            initialize count with zero */
        //top = base;
        //count = 0;
    }
    void push(T element)
    {
        if (isFull())
        {
            std::cout << "Stack is full!" << std::endl;
        }
        else
        {
            base[++top] = element;
            //++count;
            //++top;
            std::cout << "\nelement " << element << " is pushed!" << std::endl;
            printStack();
            printTopElement();
        }
    }
    /* T */void pop(void)
    {
        if(isEmpty())
        {
            std::cout << "All elements are popped!" << std::endl;
            std::cout << "Stack is empty .." << std::endl;
        }
        else
        {
            //--count;
            --top;
            std::cout << "\nelement is popped" << std::endl;
            printStack();
            printTopElement();
            //return base[top];
        }
    }
    T topOfStack(void) { return base[top]; }
    void printTopElement(void)
    {
        std::cout << "top element is " << topOfStack() << std::endl;
    }
    bool isEmpty(void)
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull(void)
    {
        if(top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void printStack(void)
    {
        std::cout << "\nThe list now is: " << std::endl;
        //for (i = 0; (base + i) < top; i++)
        //{
        //    std::cout << *(base + i) << " ";
        //}
        for (i = 0; (base + i) <= (base + top); i++)
        {
            std::cout << *(base + i) << " ";
        }
        std::cout << std::endl;
    }
    ~Stack()
    {
        delete [] base;
        std::cout << "\n~Stack()" << std::endl;
    }
};

static void reverseString(char* string, int size)
{
    Stack<char> str(size);
    int i;

    for(i = 0; i < size; i++)
    {
        str.push(string[i]);
    }

    for (i = 0; i < size; i++)
    {
        string[i] = str.topOfStack();

        /* The pop method here is responsible for decrementing the top pointer
            to point to a lower element after popping, which is a default
            in a stack implementation logic. */
        str.pop();
    }
}

int main()
{
    char begin = 'y';
    char type = 0;
    char exit = 'n';
    auto size = 0;
    char operation = 0;
    int countElements = 0;
    auto element = 0;
    constexpr auto INTEGER = 'i';
    constexpr auto CHARACTER = 'c';
    constexpr auto FLOAT = 'f';
    constexpr auto PUSH = 'p';
    constexpr auto POP = 'o';

    std::cout << "Welcome to Stack implementation program!" << std::endl;
    std::cout << "Please choose the stack type: " << std::endl;
    std::cin >> type;

    std::cout << "Please choose the stack size: " << std::endl;
    std::cin >> size;

    //std::cout << "Begin operation?" << std::endl;
    //std::cin >> begin;
    //
    //while(begin == 'y')
    //{
    //    switch (type)
    //    {
    //    case INTEGER:
    //    {
    //        Stack<int> st(size);

    //        while (exit != 'e')
    //        {
    //            std::cout << "Push or Pop? " << std::endl;
    //            std::cin >> operation;
    //            switch (operation)
    //            {
    //            case PUSH:
    //                std::cout << "Enter the element: ";
    //                std::cin >> element;
    //                st.push(element);
    //                break;
    //            case POP:
    //                st.pop();
    //                break;
    //            default:
    //                break;
    //            }
    //            std::cout << "Do you want to exit?" << std::endl;
    //            std::cin >> exit;
    //        }
    //    }
    //    break;
    //    case CHARACTER:
    //    {
    //        Stack<char> st(size);

    //        while (exit != 'e')
    //        {
    //            std::cout << "Push or Pop? " << std::endl;
    //            std::cin >> operation;
    //            switch (operation)
    //            {
    //            case PUSH:
    //                std::cout << "Enter the element: ";
    //                std::cin >> element;
    //                st.push(element);
    //                break;
    //            case POP:
    //                st.pop();
    //                break;
    //            default:
    //                break;
    //            }
    //            std::cout << "Do you want to exit?" << std::endl;
    //            std::cin >> exit;
    //        }
    //    }
    //    break;
    //    case FLOAT:
    //    {
    //        Stack<float> st(size);

    //        while (exit != 'e')
    //        {
    //            std::cout << "Push or Pop? " << std::endl;
    //            std::cin >> operation;
    //            switch (operation)
    //            {
    //            case PUSH:
    //                std::cout << "Enter the element: ";
    //                std::cin >> element;
    //                st.push(element);
    //                break;
    //            case POP:
    //                st.pop();
    //                break;
    //            default:
    //                break;
    //            }
    //            std::cout << "Do you want to exit?" << std::endl;
    //            std::cin >> exit;
    //        }
    //    }
    //    break;
    //    default:
    //        break;
    //    }
    //    std::cout << "You want to end operation?" << std::endl;
    //    std::cin >> begin;
    //}

    //int size(10);
    //char str[100];

    //std::cout << "Please enter the string: ";
    //std::cin >> str;

    //reverseString(str, strlen(str));

    //std::cout << "Output: " << str << std::endl;

    //Stack<char> st(size);

    //st.push('a');
    //st.push('b');
    //st.push('c');
    //st.push('d');
    //st.push('e');
    //st.push('f');
    //st.push('g');
    //st.push('h');
    //st.push('i');
    //st.push('j');

    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();

    //st.pop();

    //Stack<int> st(size);

    //st.push(10);
    //st.push(20);
    //st.push(30);
    //st.push(40);
    //st.push(50);
    //st.push(60);
    //st.push(70);
    //st.push(80);
    //st.push(90);
    //st.push(100);
    
    /* This push operation won't happen, as this will cause stack overflow according to the limited size of the static array,
        however this case is handled inside the "Stack" class! */
    //st.push(110);

    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();
    //st.pop();

    /* This pop operation won't happen either, as there will be no other elements left to be popped,
        however this case is also handled inside the "Stack" class! */
    //st.pop();
    

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
