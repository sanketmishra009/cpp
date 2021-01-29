#include <iostream>
using namespace std;

class wagon
{
public:
    wagon(int v = 2) : x(v){};
    void get_x()
    {
        cout << x << endl;
    }
    void sq_x()
    {
        cout << x * x << endl;
    }

private:
    int x;
};