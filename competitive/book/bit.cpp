#include <iostream>
using namespace std;

int main()
{
    //signed and unsigned
    int x = -43;
    unsigned int y = x;
    cout << x << "\t" << y << endl;
    x = 2147483647l;
    cout << x << endl;
    x++;
    cout << x << endl;
    //bit operaion.
    x = 53;
    if ((x & 1) == 0)
    {
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }
    //bit masking
    //print the number in binary format.
    for (int k = 31; k >= 0; k--)
    {
        if (x & (1 << k))
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}