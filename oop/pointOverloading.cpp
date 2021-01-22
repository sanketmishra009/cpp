#include <iostream>
#include <math.h>
using namespace std;

class point
{
public:
    point(){};
    point(double d) : x(d), y(2.4) {}
    operator double();

    // private:
    double x, y;
};

//convert class to a native type;

point::operator double()
{
    return sqrt(x * x + y * y);
}

int main()
{
    point s;
    double d = 2.4;
    s = d; //implicit conversion.
    cout << s.x << endl;
    s = 0;
    s = static_cast<point>(d); //explicit conversion.
    cout << s.x << endl;

    d = s; //converting class to native;
    cout << d << endl;
}