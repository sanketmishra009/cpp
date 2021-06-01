#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    getline(cin, x);
    x[0] = toupper(x[0]);
    cout << x << endl;
}