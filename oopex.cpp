#include <iostream>
using namespace ::std;

class rect
{
public:
    double height, width;
    rect(double h, double w)
    {
        height = h;
        width = w;
    };
    double area() { return height * width; }
};

int main()
{
    rect r = rect(2, 5.5678);
    cout << r.area() << "\n\b\a";
}
