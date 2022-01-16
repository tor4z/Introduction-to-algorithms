#include <iostream>


using namespace std;


typedef struct matrix
{
    int size;
    int *data;
} Matrix;


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


Matrix *square_matrix_multiply(Matrix *m1, Matrix *m2)
{
    Matrix *out = new_matrix(m1->size);
    for (size_t i = 0; i < m1->size; i++)
    {
        for (size_t j = 0; j < m1->size; j++)
        {
            out->data[i * m1->size + j] = 0;
            for (size_t k = 0; k < m1->size; k++)
            {
                out->data[i * m1->size + j] += 
                    m1->data[i * m1->size + k] * m2->data[k * m1->size + j];
            }
        }
    }
    return out;
}

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


int main()
{
    Matrix *m1 = new_matrix(5);
    Matrix *m2 = new_matrix(5);
    fill_matrix(m1, 1);
    fill_matrix(m2, 2);
    Matrix *out = square_matrix_multiply(m1, m2);

    print_matrix(m1);
    print_matrix(m2);
    print_matrix(out);
    return 0;
}
