#include <iostream>
#include <math.h>
using namespace std;

class point
{
public:
    point(){};
    point(double d, double e = 2.4) : x(d), y(e){};
    // point(double d) : x(d), y(2.4){};
    // ostream &operator<<(ostream &out)
    // {
    //     out << x << "," << y << endl;
    // }
    friend ostream &operator<<(ostream &os, const point &p)
    {
        os << p.x << "," << p.y << endl;
        return os;
    }

    friend point operator+(point x, point y)
    {
        point sum = {x.x + y.x, x.y + y.y};
        return sum;
    }

private:
    double x, y;
};

// this below function will not work as x and y are private members.
// they can only be accessed by member function or friend functions
// ostream &operator<<(ostream &out, const point &p)
// {
//     out << "(" << p.x << "," << p.y << ")";
//     return out;
// }

int main()
{
    point s;
    s = (32.4);
    point t = point(2.99, 4.87);
    cout << t;
    cout << s + t;
}