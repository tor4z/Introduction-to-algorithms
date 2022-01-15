#include <iostream>


using namespace std;


typedef struct matrix
{
    int size;
    int *data;
} Matrix;


void fill_matrix(Matrix *m, int x)
{
    for (size_t i = 0; i < m->size; i++)
    {
        for (size_t j = 0; j < m->size; j++)
        {
            m->data[i * m->size + j] = x;
        }
        
    }   
}


void print_matrix(Matrix *m)
{
    cout << "[";
    for (size_t i = 0; i < m->size; i++)
    {
        if (i > 0) cout << " ";
        cout << "[";
        for (size_t j = 0; j < m->size; j++)
        {
            cout << m->data[i * (m->size) + j] << " ";
        }
        cout << "]";
        if (i < m->size - 1) cout << endl;
    }
    cout << "]" << endl;
}



Matrix *new_matrix(int n)
{
    Matrix *m = new Matrix();
    m->size = n;
    m->data = new int[n * n];
    return m;
}


void strassen_matrix_multiply(
    Matrix *m1, int i1, int j1,
    Matrix *m2, int i2, int j2,
    Matrix *m3, int i3, int j3,
    int n
)
{
    if (n == 1)
        m3->data[i3 * m1->size + j3] += 
            m1->data[i1 * m1->size + j1] * m2->data[i2 * m1->size + j2];
    else
    {
        int half = n/2;
        // C11 = A11B11 + A12B21
        // A11B11
        strassen_matrix_multiply(
            m1, i1, j1,
            m2, i2, j2,
            m3, i3, j3,
            half
        );
        // A12B21
        strassen_matrix_multiply(
            m1, i1,        j1 + half,
            m2, i2 + half, j2,
            m3, i3,        j3,
            half
        );

        // C12 = A11B12 + A12B22
        // A11B12
        strassen_matrix_multiply(
            m1, i1, j1,
            m2, i2, j2 + half,
            m3, i3, j3 + half,
            half
        );
        // A12B22
        strassen_matrix_multiply(
            m1, i1,        j1 + half,
            m2, i2 + half, j2 + half,
            m3, i3,        j3 + half,
            half
        );

        // C21 = A21B11 + A22B21
        // A21B11
        strassen_matrix_multiply(
            m1, i1 + half, j1,
            m2, i2, j2,
            m3, i3 + half, j3,
            half
        );
        // A22B21
        strassen_matrix_multiply(
            m1, i1 + half, j1 + half,
            m2, i2 + half, j2,
            m3, i3 + half, j3,
            half
        );

        // C22 = A21B12 + A22B22
        // A21B12
        strassen_matrix_multiply(
            m1, i1 + half, j1,
            m2, i2,        j2 + half,
            m3, i3 + half, j3 + half,
            half
        );
        // A22B22
        strassen_matrix_multiply(
            m1, i1 + half, j1 + half,
            m2, i2 + half, j2 + half,
            m3, i3 + half, j3 + half,
            half
        );
    }
}


int main()
{
    Matrix *m1 = new_matrix(8);
    Matrix *m2 = new_matrix(8);
    fill_matrix(m1, 1);
    fill_matrix(m2, 2);
    Matrix *out = new_matrix(m1->size);
    strassen_matrix_multiply(m1, 0, 0, m2, 0, 0, out, 0, 0, m1->size);

    print_matrix(m1);
    print_matrix(m2);
    print_matrix(out);
    return 0;
}
