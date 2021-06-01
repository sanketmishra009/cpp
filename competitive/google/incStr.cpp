#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Istring(string x)
{
    int len;
    vector<int> res;
    for (int i = 0; i < x.length(); i++)
    {
        len = 1;
        cout << x[i] << endl;
        for (int j = i; j > 0; j--)
        {
            cout << "        " << x[j] << ", " << x[j - 1] << endl;
            if (x[j] > x[j - 1])
            {
                len++;
            }
            else
            {
                break;
            }
        }
        res.push_back(len);
    }
    return res;
}

int main(int argc, char *argv[])
{
    string x;
    getline(cin, x);
    vector<int> z;
    z = Istring(x);
    for (auto i : z)
    {
        cout << i << endl;
    }
}