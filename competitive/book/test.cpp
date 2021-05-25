#include <iostream>

using namespace std;

int main()
{
    //write output stream cout to a file.
    freopen("output.txt", "w", stdout);
    int a = 11;
    float b = (float)a / 2;
    cout << b << endl;
}