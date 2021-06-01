#include <iostream>
#include <vector>
using namespace std;

vector<int> subset;

void search(int k, int n)
{
    if (k == n + 1)
    {
        for (auto i : subset)
        {
            cout << i;
        }
        cout << endl;
    }
    else
    {
        subset.push_back(k);
        search(k + 1, n);
        subset.pop_back();
        search(k + 1, n);
    }
}

int main()
{
    search(1);
}