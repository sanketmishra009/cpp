#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string x;
    int size, count = 0;
    cin >> size;
    cin.ignore();
    // cout << "enter string" << endl;
    getline(cin, x);
    for (int i = 0; i < x.size() - 1; i++)
    {
        if (x[i] == x[i + 1])
        {
            count++;
        }
    }
    cout << count << endl;
}