#include <iostream>
#include <cstdlib>
#include <time.h>

static void fillArray(int* arrPtr, int size)
{
    srand(time(0));
    int i;
    for (i = 0; i < size; i++)
    {
        *(arrPtr + i) = rand() % 20;
    }
}
static void printArray(int* arrPtr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        std::cout << *(arrPtr + i) << " ";
    }
    std::cout << std::endl;
}
static void sortArray(int* arrPtr, int size)
{
    int i;
    int temp = 0;
    int pass;

    for (pass = 1; pass < size; pass++)
    {
        for (i = 1; i < size; i++)
        {
            if (arrPtr[i - 1] > arrPtr[i])
            {
                temp = arrPtr[i];
                arrPtr[i] = arrPtr[i - 1];
                arrPtr[i - 1] = temp;
            }
        }
        printArray(arrPtr, size);
    }
}

int main(void)
{
    std::cout << "Begin the Bubble Sort program\n";
    constexpr int SIZE = 10;
    int arr[SIZE]{ 17, 9, 15, 10, 1, 9, 2, 5, 13, 8 };
    //int arr[SIZE]{};
    //fillArray(arr, SIZE);

    printArray(arr, SIZE);

    std::cout << std::endl;
    std::cout << std::endl;

    sortArray(arr, SIZE);

    std::cout << std::endl;
    std::cout << std::endl;

    printArray(arr, SIZE);
    return 0;
}