#include <iostream>

using namespace std;


void print_array(int *A, int n)
{
    for (size_t i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}


void swap(int *A, int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}


int partition(int *A, int s, int e)
{
    int i;
    while (s < e)
    {
        for (i = e; i > s; i--)
        {
            if(A[i] < A[s])
            {
                swap(A, i, s);
                break;
            }
        }
        e = i;
        for (i = s; i < e; i++)
            if(A[i] > A[e])
            {
                swap(A, i, e);
                break;
            }
        s = i;
    }
    return e;
}


void quick_sort(int *A, int s, int e)
{
    int p = partition(A, s, e);
    if(s < p)  quick_sort(A, s, p);
    if(p+1 < e) quick_sort(A, p+1, e);
}


int main()
{
    int A [] = {1, 2, 5, 6, 7, 8, 3};
    int n = 7;
    print_array(A, n);
    quick_sort(A, 0, n-1);
    print_array(A, n);
    return 0;
}