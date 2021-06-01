#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include <bits/stdc++.h>
using namespace std;

vector<int> B;

int sumV(vector<int> vec, int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += i;
    }
    return sum;
}

int checkMid(vector<int> x, int mid)
{
    int flag = 1;
    for (auto i : x)
    {
        if (i != mid)
        {
            flag = 0;
        }
    }
    return flag;
}

void das(vector<int> arr, int l, int r)
{
    // cout << "s is " << s << endl;
    int sum = 0;
    sum = accumulate(arr.begin() + l, arr.begin() + r + 1, sum);
    // cout << "l , r, Sum: " << l << r << sum << endl;
    B.push_back(sum);
    // cout << "sum is " << sum << endl;
    int mid = (arr[l] + arr[r]) / 2;
    int pos = -1;
    for (int i = l; i < r + 1; i++)
    {
        // cout << "mid: " << mid << "arrVal" << arr[i] << endl;
        if (arr[i] <= mid)
        {
            pos = i;
        }
        else
        {
            break;
        }
    }
    if (pos == -1 || pos == r)
    {
        return;
    }
    // cout << "indexes " << l << pos << r << endl;
    das(arr, l, pos);
    das(arr, pos + 1, r);
}

int main()
{
    vector<int> a;
    int iter, x, y, temp, res;
    cin >> iter;
    for (int i = 0; i < iter; i++)
    {
        cin >> x;
        cin >> y;
        a.clear();
        B.clear();
        for (int j = 0; j < x; j++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        das(a, 0, a.size() - 1);
        //check a array.
        // for (auto i : B)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        for (int j = 0; j < y; j++)
        {
            cin >> temp;
            res = 0;
            for (auto i : B)
            {
                // cout << "i:" << i << "temp: " << temp << endl;
                if (i == temp)
                {
                    res = 1;
                }
            }
            if (res)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}