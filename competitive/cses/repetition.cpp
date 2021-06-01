#include <iostream>
#include <vector>
using namespace std;

int solve(string arr)
{
    int sum = 1;
    int Gsum = 1;
    char last, curr;
    last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        curr = arr[i];
        if (last == curr)
        {
            sum++;
        }
        else
        {
            sum = 1;
        }
        last = curr;
        if (sum > Gsum)
        {
            Gsum = sum;
        }
    }
    return Gsum;
}

int main()
{
    string str;
    getline(cin, str);
    cout << solve(str) << endl;
}