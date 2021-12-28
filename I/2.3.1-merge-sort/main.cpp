#include <iostream>


void merge(int *array1, int n1, int *array2, int n2)
{
    int tmp[n1 + n2];
    int k = 0;
    size_t i = 0, j = 0;

    for (; i < n1 && j < n2;)
    {
        if (array1[i] < array2[j])
        {
            tmp[k] = array1[i];
            i++;
        } else {
            tmp[k] = array2[j];
            j++;
        }
        k++;
    }

    if (i < n1)
        tmp[k] = array1[n1-1];
    else
        tmp[k] = array2[n2-1];

    for (size_t i = 0; i < (n1 + n2); i++)
        array1[i] = tmp[i];    
}


void merge_sort(int *array, int n)
{
    if (n > 1)
    {
        merge_sort(array, n/2);
        merge_sort(array + n/2, n-n/2);
        merge(array, n/2, array + n/2, n-n/2);
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
    std::cout << std::endl;
}


int main()
{
    int array [] = {6, 5, 8, 4, 3, 1, 7};
    int n = 7;
    print_array(array, n);
    merge_sort(array, n);
    print_array(array, n);
    return 0;
}
