#include <iostream>

/*
 *
 * To achieve insertion sort, perform the following steps:
 * 1- We have to start with the second element, because the first element in the array is assumed to be sorted.
 * 2- Compare second element with first element and check if the second element is smaller, then swap them.
 * 3- Move to the third element and compare it with the second element,
 *  then the first element and swap as it's necessary to put it in the correct position among
 *  the first three elements.
 * 4- Continue this process, comparing each element with the ones before it and swapping as it's needed
 *  to place it in the correct position among the sorted elements.
 * 5- Repeat until the entire array is sorted.
 * 
 */

template <size_t N>
static void printArray(int (&arrPtr)[N])
{
    for(int c : arrPtr)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}
static void sortArray(int* arrPtr, int size)
{
    uint16_t i, sortedIndex;
    int temp;
    for(i = 1; i < size; i++)
    {
        sortedIndex = i - 1;
        if(arrPtr[i] < arrPtr[sortedIndex])
        {
            temp = arrPtr[i];
            arrPtr[i] = arrPtr[sortedIndex];
            arrPtr[sortedIndex] = temp;
            temp = 0;
            while(sortedIndex > 0)
            {
                if(arrPtr[sortedIndex] < arrPtr[sortedIndex - 1])
                {
                    temp = arrPtr[sortedIndex];
                    arrPtr[sortedIndex] = arrPtr[sortedIndex - 1];
                    arrPtr[sortedIndex - 1] = temp;
                    --sortedIndex;
                }
                else
                {
                    /* The left side array is already sorted. */
                    break;
                }
            }
            temp = 0;
        }
    }
}

int main(void)
{
    std::cout << "Begin the Insertion Sort program\n";
    int arr[]{17, 9, 15, 10, 1, 9, 2, 5, 13, 8};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr);
    sortArray(arr, size);
    printArray(arr);
    return 0;
}