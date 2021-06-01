#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findNum(string s, char x)
{
    int count = 0;
    for (auto i : s)
    {
        if (i == x)
        {
            count++;
        }
    }
    return count;
}

int aGood(string s, char x)
{
    if (s.size() == 1)
    {
        return s[0] != x;
    }
    int lcost, rcost;
    int mid = s.length() / 2;
    string left = s.substr(0, mid);
    string right = s.substr(mid, s.length());
    lcost = aGood(left, x + 1) + (right.length() - count(right.begin(), right.end(), x));
    rcost = aGood(right, x + 1) + (left.length() - count(left.begin(), left.end(), x));
    return min(lcost, rcost);
}

int main()
{
    int iter, size;
    cin >> iter;
    vector<string> cont;
    string x;
    for (int i = 0; i < iter; i++)
    {
        x.clear();
        cin >> size;
        cin >> x;
        cont.push_back(x);
    }
    for (auto i : cont)
    {
        cout << aGood(i, 'a') << endl;
    }
    // cin >> x;
    // int cost = aGood(x, 'a');
    // cout << cost << endl;
}