#include <iostream>


int *pos1;
int *pos2;
int global_max = -1000;


int find_between(int *array1, int n1, int *array2, int n2)
{
    int s = array1[n1-1] + array2[0];
    int max = s;
    int *pos_1=&(array1[n1-1]), *pos_2=array2;

    for (int i = n1 - 2; i > 0; i--)
    {
        s += array1[i];
        if (s >= max)
        {
            pos_1 = &(array1[i]);
            max = s;
        }
    }
    
    s = max;
    for (int i = 1; i < n2; i++)
    {
        s += array2[i];
        if (s >= max)
        {
            pos_2 = &(array2[i]);
            max = s;
        }
    }
    if(max > global_max)
    {
        global_max = max;
        pos1 = pos_1;
        pos2 = pos_2;
    }
    return max;
}


int find_max_subarray(int *array, int n)
{
    int s1, s2, s3;
    if (n>=2)
    {
        s1 = find_max_subarray(array, n/2);
        s2 = find_max_subarray(array + n/2, n-n/2);
        s3 = find_between(array, n/2, array+n/2, n-n/2);
    } else {
        return array[0];
    }

    if (s1 > s2 && s1 > s3)
        return s1;
    else if (s2 > s3)
        return s2;
    else
        return s3;
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
    int n = 16;
    int array [] = {
        13, -3, -25, 20, -3, -16, -23, 
        18, 20, -7, 12, -5, -22, 15, -4, 7
    };
    print_array(array, n);
    std::cout << find_max_subarray(array, n) << std::endl;
    // print sub array
    std::cout << "len: " << pos2 - pos1 + 1 << std::endl;
    for (; pos1 <= pos2; pos1++)
    {
        std::cout << (*pos1) << ",";
    }
    std::cout << std::endl;
    
    return 0;
}

