#include <iostream>

using namespace std;


class Matrix
{
public:
    int size;
    int *data;

    Matrix(int n)
    {
        size = n;
        data = new int[n * n]{0};
    }

    Matrix(int n, const initializer_list<int>& array)
    {
        size = n;
        data = new int[n * n];
        int i = 0;
        for (auto it : array)
        {
            data[i] = it;
            ++i;
        }
    }

    Matrix &operator*(const Matrix &m)
    {
        Matrix *out = new Matrix(size);

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                out->data[i * size + j] = 0;
                for (size_t k = 0; k < size; k++)
                {
                    out->data[i * size + j] += 
                        this->data[i * size + k] * m.data[k * size + j];
                }
            }
        }
        return *out;
    }

    Matrix *fill(int x)
    {
        int n = size * size;
        for (size_t i = 0; i < n; i++)
            data[i] = x;
        return this;
    }

    Matrix *t()
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i; j < size; j++)
            {
                int tmp = data[i * size + j];
                data[i * size + j] = data[j * size + i];
                data[j * size + i] = tmp;
            }
        }
        return this;
    }

    Matrix &operator+(const Matrix &m)
    {
        Matrix *out = new Matrix(size);
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                out->data[i * size + j] = 
                    data[i * size + j] + m.data[i * size + j];
            }
        }
        return *out;
    }

    Matrix &operator+=(const Matrix &m)
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                data[i * size + j] += m.data[i * size + j];
            }
        }
        return *this;
    }

    Matrix &operator-(Matrix &m)
    {
        Matrix *out = new Matrix(size);
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                out->data[i * size + j] =
                    data[i * size + j] - m.data[i * size + j];
            }
        }
        return *out;
    }

    Matrix &operator-=(Matrix &m)
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                data[i* size + j] -= m.data[i * size + j];
            }
        }
        return *this;
    }

    bool operator==(Matrix &m)
    {
        if(size != m.size)
            return false;

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if(data[i * size + j] == m.data[i * size + j])
                    return false;
            }
        }
        return true;
    }

    friend ostream &operator<<(ostream &os, Matrix &m);
};


ostream &operator<<(ostream &os, Matrix &m)
{
    os << "[";
    for (size_t i = 0; i < m.size; i++)
    {
        if(i != 0) os << " ";
        os << "[";
        for (size_t j = 0; j < m.size; j++)
            os << m.data[i * m.size + j] << " ";
        os << "]";
        if(i < m.size-1) os << endl;
    }
    os << "]";
    return os;
}


int main()
{
    // Matrix fill
    Matrix *m1 = new Matrix(2);
    m1->fill(1);
    cout << *m1 << endl;

    // Matrix init with initialized-list
    Matrix *m2 = new Matrix(2, {1, 2, 3, 4});
    cout << *m2 << endl;

    // Matrix transpose
    m2->t();
    cout << *m2 << endl;

    // Matrix multiply
    cout << (*m1) * (*m2) << endl;

    // Matrix +=
    *m1 += *m2;
    cout << *m1 << endl;

    // Matrix -=
    *m1 -= *m2;
    cout << *m1 << endl;

    // Matrix +
    cout << *m1 + *m2 << endl;

    // Matrix -
    cout << *m1 - *m2 << endl;

    return 0;
}
