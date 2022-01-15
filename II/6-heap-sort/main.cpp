#include <bits/stdc++.h>

using namespace std;


int parent(int i)
{
    return  i / 2;
}

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}


void max_heapify(int *A, int i, int n)
{
    int l, r, largest_index, tmp;

    for (; i < n; i++)
    {
        l = left(i);
        r = right(i);
        if(A[r] < A[l])
            largest_index = l;
        else
            largest_index = r;

        if(A[largest_index] > A[i])
        {
            tmp = A[i];
            A[i] = A[largest_index];
            A[largest_index] = tmp;
            max_heapify(A, largest_index, n);
        }
        else 
        {
            break;
        }
    }
    
}

void build_max_heap(int *A, int n)
{
    for (size_t i = n/2; i > 0; i--)
        max_heapify(A, i, n);
}


void heap_sort(int *A, int n)
{
    int tmp;
    for (size_t i = n-1; i > 0; i--) {
        tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        max_heapify(A, 0, i);
    }
}


int max_heap_insert(int *A, int x, int n)
{
    A[n] = x;
    int i = n, p;
    while (p >= 0)
    {
        int p = parent(i);
        if(A[p] < x)
        {
            A[i] = A[p];
            A[p] = x;
            i = p;
        }
        else
        {
            break;
        }
    }
}

int heap_extract_max(int *A, int n)
{
    int maximum = A[0];
    A[0] = A[n-1];
    max_heapify(A, 0, n-1);
    return maximum;
}


void heap_increase_key(int *A, int k, int i, int n)
{
    // Assume K >= A[i]
    A[i] = k;
    int p;

    while (p >= 0)
    {
        p = parent(i);
        if(A[p] < k)
        {
            A[i] = A[p];
            A[p] = k;
            i = p;
        }
        else
        {
            break;
        }
    }
    
}


int heap_maximum(int *A, int n)
{
    return A[0];
}


int main()
{
    
    return 0;
}
