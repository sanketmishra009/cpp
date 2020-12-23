#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
template <class summable>
inline summable summ(summable arr[], int size)
{
    summable s = 0;
    for (int i = 0; i < size; i++)
    {
        s += arr[i];
    }
    return s;
}

int main()
{
    srand(time(0));
    int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << endl;
    }
    int x = summ(arr, size);
    cout << "sum is:"
         << x;
}