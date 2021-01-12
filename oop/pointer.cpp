#include <iostream>
using namespace std;

class point
{
public:
    double getx() { return this->x; }
    double gety() { return this->y; }
    void setx(double x) { this->x = x; }
    void sety(double y) { this->y = y; }
    double x, y;
};

// point operator+(point &p1, point &p2)
// {
//     point sum = {p1.x + p2.x, p1.y + p2.y};
//     return sum;
// }

ostream &operator<<(ostream &out, const point &p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

void pointer(point *p)
{
    cout << p->x << "\n";
}
void p1(point &p)
{
    cout << p.x << "\n";
    cout << &p << "\n";
    point *x = &p;
    cout << x->y << "\n";
}
void disp(int *p)
{
    cout << *p << "\n"; //prints value
    cout << p << "\n";  // prints address
    cout << &p << "\n"; //prints own address
}

int main()
{
    point a = {1, 2.5}, b = {9.99, 99.78};
    // cout << "a=" << a << "b=" << b << endl;
    // cout << "sum of points = " << a + b << endl;
    cout << a << "\n"
         << &a << "\n";
    pointer(&a);
    p1(a);
    // int x = 10;
    // cout << &x;
    // disp(&x);
}
