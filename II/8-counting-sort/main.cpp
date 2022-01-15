#include <iostream>
#define MAXKEY 100

using namespace std;


void counting_sort(int *A, int *B, int *tmp, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        tmp[A[i]]++;
    }

    int sum = 0;
    for (size_t i = 0; i < MAXKEY; i++)
    {
        sum += tmp[i];
        tmp[i] = sum;
    }

    for (size_t i = 0; i < n; i++)
        B[tmp[A[i]]-1] = A[i];
}


void print_array(int *A, int n)
{
    for (size_t i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}


int main()
{
    int n = 7;
    int A [] = {1, 2, 5, 6, 7, 8, 3};
    int B [n] = {0};
    int tmp [MAXKEY] = {0};
    counting_sort(A, B, tmp, n);

    print_array(A, n);
    print_array(B, n);
    return 0;
}