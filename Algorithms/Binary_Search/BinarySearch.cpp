#include <iostream>
#include <cstdlib>
#include <time.h>

class BinarySearch
{
private:
    int* arrPtr = nullptr;
    int size = 0;
    int lowIndex = 0;
    int midIndex = 0;
    int highIndex = 0;
public:
    BinarySearch(int arr[], int size)
    {
        this->arrPtr = arr;
        this->size = size;
        std::cout << "BinarySearch()" << std::endl;
    }
    void fill(void)
    {
        srand(time(0));
        int i;
        for (i = 0; i < size; i++)
        {
            *(arrPtr + i) = rand() % size;
        }
    }
    void sort(void)
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
        }
    }

    /* This is an iterative function */
    int search(int value)
    {
        int i;
        int retVal = -1;
        lowIndex = 0;
        highIndex = 0 + size - 1;
        for (i = 0; i < size; i++)
        {
            if (lowIndex == highIndex || lowIndex > highIndex)
            {
                retVal = -1;
            }
            else
            {
                midIndex = (lowIndex + highIndex) / 2;
                if (value == arrPtr[midIndex])
                {
                    retVal = midIndex;
                }
                else if (value > arrPtr[midIndex])
                {
                    lowIndex = midIndex + 1;
                    retVal = midIndex;
                }
                else if (value < arrPtr[midIndex])
                {
                    highIndex = midIndex - 1;
                    retVal = midIndex;
                }
                else
                {
                    retVal = -1;
                }
            }
        }
        return retVal;
    }

    /* This is a recursive function */
    int search(int low, int high, int value)
    {
        int mid = (low + high) / 2;
        int retVal = -1;
        if (low > high)
        {
            retVal = -1;
        }
        else
        {
            if (value < arrPtr[0])
            {
                retVal = -1;
            }
            else if (value == arrPtr[mid])
            {
                retVal = mid;
            }
            else if (value > arrPtr[mid])
            {
                retVal = search((mid + 1), high, value);
            }
            else if (value < arrPtr[mid])
            {
                retVal = search(low, (mid - 1), value);
            }
            else
            {
                retVal = -1;
            }
        }
        return retVal;
    }
    void print(void)
    {
        int i;
        for (i = 0; i < size; i++)
        {
            std::cout << *(arrPtr + i) << " ";
        }
        std::cout << std::endl;
    }
    ~BinarySearch()
    {
        std::cout << "~BinarySearch()" << std::endl;
    }
};

int main(void)
{
    std::cout << "Begin the Binary Search program\n";
    constexpr int SIZE = 10;
    int arr[SIZE]{};
    int value = 0;
    int low = 0;
    int high = SIZE - 1;
    std::cout << "Size of arr[] = " << SIZE << std::endl;
    BinarySearch bs(arr, SIZE);

    bs.fill();
    bs.print();
    bs.sort();
    bs.print();

    // value = 0;
    // value = bs.search(low, high, 1);
    // if (value != -1)
    // {
    //     std::cout << "Value is at index no. " << value << std::endl;
    // }
    // else
    // {
    //     std::cout << "Value not found !!" << std::endl;
    // }
    // value = 0;
    // value = bs.search(low, high, 2);
    // if (value != -1)
    // {
    //     std::cout << "Value is at index no. " << value << std::endl;
    // }
    // else
    // {
    //     std::cout << "Value not found !!" << std::endl;
    // }
    // for (int i = arr[0]; i <= arr[size - 1]; i++)
    // {
    //     value = 0;
    //     value = bs.search(low, high, i);
    //     if (value != -1)
    //     {
    //         std::cout << "Value is at index no. " << value << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "Value not found !!" << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
    // value = 0;
    // value = bs.search(low, high, (arr[size - 1] + 1));
    // if (value != -1)
    // {
    //     std::cout << "Value is at index no. " << value << std::endl;
    // }
    // else
    // {
    //     std::cout << "Value not found !!" << std::endl;
    // }
    return 0;
}