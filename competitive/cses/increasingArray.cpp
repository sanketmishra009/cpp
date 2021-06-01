#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<long long> arr)
{
    long long cost = 0;
    long long last, curr, diff;
    last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        curr = arr[i];
        diff = curr - last;
        // cout << "difference at round: " << i << endl;
        // cout << diff << endl;
        if (diff < 0)
        {
            cost += abs(diff);
            arr.at(i) = last;
        }
        last = arr[i];
    }
    // cout << "###########################" << endl;
    // for (auto i : arr)
    // {
    //     cout << i << endl;
    // }
    return cost;
}

int main()
{
    long x;
    int n;
    vector<long long> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    cout << solve(arr) << endl;
}