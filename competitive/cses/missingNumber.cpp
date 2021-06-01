#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int flag=0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[i - 1] + 1)
        {
            flag = arr[i]-1;
        }
    }
    if(!flag){
            flag = arr.size()+1;
        }
        cout<<flag<<endl;
}

int main()
{
    vector<int> arr;
    int size, x;
    cin >> size;
    for (int i = 0; i < size-1; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    if (size == 2 ){
        if(arr[0]==1){
            cout<<2<<endl;
            return 0;
        }

        else{
            cout<<1<<endl;
            return 0;
        }
    }
    solve(arr);
}