#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    string x;
    set<char> s;
    getline(cin, x);
    for (auto i : x)
    {
        s.insert(i);
    }
    // for (auto i : s)
    // {
    //     cout << i << '\t';
    // }
    // cout << endl;
    if (s.size() % 2 != 0)
    {
        cout << "IGNORE HIM!";
    }
    else
    {
        cout << "CHAT WITH HER!";
    }
}