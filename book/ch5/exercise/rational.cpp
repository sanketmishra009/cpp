#include <iostream>
#include <math.h>
using namespace std;

long gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

class rational
{
public:
    rational(int n = 0) : a(n), q(1) {}
    // rational(int i, int j) : a(i), q(j) {}
    rational(double r) : a(static_cast<long>(r * BIG)),
                         q(BIG)
    {
        long g = gcd(a, q);
        a = (long)(r * BIG) / g;
        q = BIG / g;
    }
    rational(long i, long j)
    {
        long g = gcd(i, j);
        a = i / g;
        q = j / g;
    }
    void print() const
    {
        cout << a << "/" << q << endl;
    }
    operator double()
    {
        return static_cast<double>(a) / q;
    }
    friend bool operator==(rational, rational);

private:
    long a, q;
    enum
    {
        BIG = 100
    };
};

bool operator==(rational x, rational y)
{
    if (x.a == y.a && x.q == y.q)
    {
        return true;
    }
    return false;
}
inline int greaterr(int i, int j)
{
    return (i > j ? i : j);
}
inline double greaterr(double x, double y)
{
    return (x > y ? x : y);
}
inline rational greaterr(rational w, rational z)
{

    return (w > z ? w : z);
}

int main()
{
    // int i = 2, j = 5;
    // float x = 7.0;
    // double y = 14.5;
    // rational w(10), z(3.5), zmax;
    // cout << "\ngreater(" << i << ", " << j << ") = " << greaterr(i, j);
    // cout << "\ngreater(" << x << ", " << y << ") = " << greaterr(x, y);
    // cout << "\ngreater(" << i << ", ";
    // z.print();
    // // z.print();
    // cout << ") = " << greaterr(static_cast<rational>(i), z);
    // zmax = greaterr(w, z);
    // cout << "\ngreater(";
    // w.print();
    // cout << ", ";
    // z.print();
    // cout << ") = ";
    // zmax.print();
    // // cout << greaterr(w, z);
    // cout << endl;

    rational x(60, 36);
    rational y(60, 36);
    bool z = x == y;
    cout << z << endl;
    // x.print();
}