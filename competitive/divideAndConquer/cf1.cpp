#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> B;

void solve(long long int num)
{
    if (floor(num / 2) == 1)
    {
        B.push_back(1);
        B.push_back(num % 2);
        B.push_back(1);
    }
    else if (num == 1)
    {
        return;
    }
    else
    {
        solve(floor(num / 2));
        B.push_back(num % 2);
        solve(floor(num / 2));
    }
}

int main()
{
    long long int x, l, r;
    cin >> x >> l >> r;
    solve(x);
    long long int sum = 0;
    for (long long int i = l - 1; i < r; i++)
    {
        if (B[i] == 1)
        {
            sum += 1;
        }
    }
    cout << sum << endl;
}