#include <iostream>
using namespace std;
#include <complex>

template <class swapable>
void swapX(swapable &i, swapable &j)
{
    swapable temp = i;
    i = j;
    j = temp;
}
int main()
{
    int x = 2, y = 4;
    double m = 2.223, n = 3.3323;
    complex<double> c1(2.5, 3.33), c2(9.5, 6.66);
    cout << "before swap int:" << x << "," << y << endl;
    cout << "before swap double:" << m << "," << n << endl;
    cout << "before swap complex:" << c1 << "," << c2 << endl;
    swapX(x, y);
    swapX(m, n);
    swapX(c1, c2);
    cout << "after swap int:" << x << "," << y << endl;
    cout << "after swap double:" << m << "," << n << endl;
    cout << "after swap complex:" << c1 << "," << c2 << endl;
}