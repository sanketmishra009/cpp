#include <iostream>
using namespace std;

inline void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

inline void swap(double &i, double &j)
{
    double temp = i;
    i = j;
    j = temp;
}

int main()
{
    int x = 2, y = 4;
    double m = 2.223, n = 3.3323;
    cout << "before swap int:" << x << "," << y << endl;
    cout << "before swap double:" << m << "," << n << endl;
    swap(x, y);
    swap(m, n);
    cout << "after swap int:" << x << "," << y << endl;
    cout << "after swap double:" << m << "," << n << endl;
}