#include <iostream>
#include <string>

using namespace std;

string supernum(string n)
{
    // cout << "n: " << n << endl;
    if (n.size() == 1)
    {
        return n;
    }
    else
    {
        long long int sum = 0;
        for (auto i : n)
        {
            // sum = i - 48;
            // cout << "i: " << i << typeid(i).name() << endl;
            // cout << "sum: " << sum << typeid(sum).name() << endl;
            sum += (i - 48);
        }
        // cout << "sum: " << sum << endl;
        return supernum(to_string(sum));
    }
}

string repeat(string s, int n)
{
    // Copying given string to temparory string.
    string s1 = s;

    for (int i = 1; i < n; i++)
        s += s1; // Concatinating strings

    return s;
}

int main()
{
    string inp;
    int x;
    cin >> inp >> x;
    inp = repeat(inp, x);

    cout << supernum(inp) << endl;
}