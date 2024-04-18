#include <iostream>
/// @brief This is the code for linear search implemented in a class.
/// Its time complexity is O(n) --> The bigger the data set, the number of steps to complete that search will increase proportionally.
/// @tparam T 
// template<typename T>
class LinearSearch
{
private:
    int* arrPtr;
    int size;
public:
    LinearSearch(int size)
    {
        this->size = size;
        arrPtr = new int[size];
        std::cout << "LinearSearch(size)        --> Parameterized Constructor\n";
    }
    void PrintContainer()
    {
        for(auto c = 0; c < size; c++)
        {
            std::cout << arrPtr[c] << " ";
        }
        std::cout << std::endl;
    }
    void FillContainer(void)
    {
        int i;
        for(i = 0; i < size; i++)
        {
            arrPtr[i] = (i + 1) * 3;
        }
    }
    int SearchContainer(int value)
    {
        int i;
        int retVal = -1;
        for(i = 0; i < size; i++)
        {
            if(arrPtr[i] == value)
            {
                retVal = i;
                break;
            }
        }
        return retVal;
    }
    ~LinearSearch()
    {
        delete[] arrPtr;
        std::cout << "~LinearSearch()           --> Destructor\n";
    }
};

/// @brief 
/// @param  
/// @return 
int main(void)
{
    std::cout << "Begin Linear Search Program\n";
    LinearSearch ls(10);
    ls.FillContainer();
    ls.PrintContainer();

    int status = ls.SearchContainer(30);

    if(status != -1)
    {
        std::cout << "Element found." << std::endl;
    }
    else
    {
        std::cout << "Element not found!" << std::endl;
    }
    return 0;
}