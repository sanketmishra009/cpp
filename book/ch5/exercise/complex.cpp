#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

class complex
{
public:
    friend class vec_complex;
    complex() {}
    complex(double r) : real(r), imag(0) {}
    complex(double r, double i) : real(r), imag(i) {}
    void assign(double r, double i)
    {
        real = r;
        imag = i;
    }
    void print()
    {
        cout << real << " + " << imag << "i ";
    }
    operator double()
    {
        return (sqrt(real * real + imag * imag));
    }

    friend ostream &operator<<(ostream &out, const complex x)
    {
        return out << x.real << "+" << x.imag << "i" << endl;
    }
    complex operator--(int)
    {
        this->real--;
        this->imag--;
        return *this;
    }
    friend complex operator+(complex, complex);
    friend complex operator-(complex, complex);
    friend complex operator*(complex, complex);

private:
    double real, imag;
};

class vec_complex
{
public:
    vec_complex(complex *arr, int s) : size(s)
    {
        cout << "ctor called." << endl;
        for (int i = 0; i < s; i++)
        {
            x[i] = arr[i];
        }
        cout << "ctor end" << endl;
    }
    vec_complex(int s) : size(s)
    {
        for (int i = 0; i < size; i++)
        {
            x[i] = complex(0.0);
            cout << x[i];
        }
    }
    void vecPrint()
    {
        for (int i = 0; i < size; i++)
        {
            cout << x[i];
        }
    }
    complex getVal(int index)
    {
        return x[index];
    }
    friend vec_complex operator+(vec_complex &, vec_complex &);
    friend vec_complex operator-(vec_complex &, vec_complex &);
    friend vec_complex operator*(vec_complex &, vec_complex &);

    // private:
    int size;
    complex x[];
};

vec_complex operator+(vec_complex &v1, vec_complex &v2)
{
    assert(v1.size == v2.size);
    complex *arr = new complex[v1.size];
    for (int i = 0; i < v1.size; i++)
    {
        arr[i] = v1.x[i] + v2.x[i];
        // cout << arr[i];
    }
    vec_complex arrx(arr, v1.size);
    return arrx;
}

vec_complex operator-(vec_complex &v1, vec_complex &v2)
{
    assert(v1.size == v2.size);
    complex *arr = new complex[v1.size];
    for (int i = 0; i < v1.size; i++)
    {
        arr[i] = v1.x[i] - v2.x[i];
        // cout << arr[i];
    }
    vec_complex arrx(arr, v1.size);
    return arrx;
}

vec_complex operator*(vec_complex &v1, vec_complex &v2)
{
    assert(v1.size == v2.size);
    complex *arr = new complex[v1.size];
    for (int i = 0; i < v1.size; i++)
    {
        arr[i] = v1.x[i] * v2.x[i];
        // cout << arr[i];
    }
    vec_complex arrx(arr, v1.size);
    return arrx;
}

complex operator+(complex x, complex y)
{
    return complex(x.real + y.real, x.imag + y.imag);
}

complex operator-(complex x, complex y)
{
    return complex(x.real - y.real, x.imag - y.imag);
}

complex operator*(complex x, complex y)
{
    return complex(x.real * y.real, x.imag * y.imag);
}

int main()
{
    // complex x(2.5, 3.4);
    // complex y(4, 5.55);
    // cout << x + y;
    // x--;
    // cout << x - y;
    // cout << x * y;

    complex x[5] = {complex(2, 4), complex(2.4, 4.98), complex(4.5, 4.9), 5, 6};
    vec_complex com(x, 5);
    // com.vecPrint();
    cout << endl;
    vec_complex z = com * com;
    z.vecPrint();
}