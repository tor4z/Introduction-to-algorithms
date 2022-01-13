#include <iostream>
#include <cmath>

using namespace std;


void print_array(int *A, int n)
{
    for (size_t i = 0; i < n; i++)  
        cout << A[i] << " ";
    cout << endl;
}


bool gt(int *A, int i, int j, int d)
{
    if((A[i] / (int)pow(10, d-1)) % 10 > (A[j] / (int)pow(10, d-1)) % 10)
        return true;
    else
        return false;
}


void insert_sort(int *A, int n, int d)
{
    int tmp;
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if(gt(A, j-1, j, d))
            {
                tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
            }
        }
    }
    
}


void radix_sort(int *A, int n, int d)
{
    for (size_t i = 1; i <= d; i++)
    {
        insert_sort(A, n, i);
    }
}



int main()
{
    int n = 7;
    int A [] = {329, 457, 657, 839, 436, 720, 355};
    print_array(A, n);
    radix_sort(A, n, 3);
    print_array(A, n);
    return 0;
}