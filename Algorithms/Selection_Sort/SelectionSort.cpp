#include <iostream>

/**
 * @brief The Selection Sort Algorithm repeatedly selects the smallest (or largest) element from
 * the unsorted portion of the list and swaps it with the first element of the unsorted part.
 * 
 * This process is repeated for the remaining unsorted portion until the entire list is sorted.
 * 
 */

#define MAX(A, B) ((A) > (B) ? (A) : (B))

template <size_t N>
static void printArray(int (&arrPtr)[N])
{
    for(int c : arrPtr)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}
static int getMax(int* arrPtr, int size)
{
    int retVal = -1;

    int max;
    int i;
    max = i;
    for(i = 0; i < size; i++)
    {
        if(arrPtr[max] < arrPtr[i])
        {
            max = i;
        }
    }
    retVal = max;
    return retVal;
}
static void sortArray(int* arrPtr, int size)
{
    int i;
    int temp;
    int max = 0;
    int pass;
    int SIZE = size - 1;

    for(pass = 1; pass <= size - 1; pass++)
    {
        max = 0;
        for(i = 0; i <= SIZE; i++)
        {
            if(arrPtr[max] < arrPtr[i])
            {
                max = i;
            }
        }
        temp = arrPtr[SIZE];
        arrPtr[SIZE] = arrPtr[max];
        arrPtr[max] = temp;
        --SIZE;
    }
}
int main(void)
{
    std::cout << "Begin the Selection Sort program\n";
    int arr[]{9, 15, 1, 10, 17, 9, 2, 5, 13, 8};
    int size = sizeof(arr) / sizeof(int);
    // auto max = getMax(arr, size);
    // std::cout << "Max number in array = " << arr[max] << " and at index no. " << max << std::endl;
    printArray(arr);
    sortArray(arr, size);
    printArray(arr);
    return 0;
}