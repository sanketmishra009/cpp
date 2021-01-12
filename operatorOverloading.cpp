#include <iostream>
using namespace std;

typedef enum days
{
    sun,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat
} days;

inline days operator++(days d)
{
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

ostream &operator<<(ostream &out, const days &d)
{
    switch (d)
    {
    case sun:
        out << "sunday";
        break;
    case mon:
        out << "monday";
        break;
    case tue:
        out << "tuesday";
        break;
    case wed:
        out << "wednesday";
        break;
    case thu:
        out << "thursday";
        break;
    case fri:
        out << "friday";
        break;
    case sat:
        out << "saturday";
        break;
    }
    return out;
}
int main()
{
    days d = static_cast<days>(2), e;
    e = ++d;
    int x = static_cast<int>(d);
    cout << d << "\t" << e << "\t" << x << endl;
}