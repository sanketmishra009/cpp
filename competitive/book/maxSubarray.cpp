#include <iostream>
#include <vector>
using namespace std;

void subArray(vector<int> arr, int n)
{
    int best = 0, sum = 0, lb = 0, ub = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sum + arr[i])
        {
            lb = i;
        }
        sum = max(arr[i], sum + arr[i]);
        if (sum > best)
        {

            best = sum;
            ub = i;
        }
    }
    cout << "upper: " << ub << " lower: " << lb << " best= " << best << endl;
}

int main()
{
    vector<int> arr{-1, 2, 4, -3, 5, 2, -5, 2};
    subArray(arr, arr.size());
}