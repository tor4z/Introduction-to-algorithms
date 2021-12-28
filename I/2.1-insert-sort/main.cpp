#include <iostream>



void insert_sort(int *array, int n)
{
    int tmp;

    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (array[j] > array[j-1])
            {
                break;
            } else {
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
        
    }
    
}


void print_array(int *array, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << array[i];
        if (i < n-1)
            std::cout << ", ";
    }
    std::cout<< std::endl;    
}


int main()
{
    int array [] = {1, 2, 5, 6, 7, 8, 3};
    print_array(array, 7);
    insert_sort(array, 7);
    print_array(array, 7);
    return 0;
}
