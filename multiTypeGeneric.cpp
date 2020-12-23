#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T1, class T2>
void conver(const T1 *source, T2 *dest, int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = static_cast<T2>(source[i]);
    }
}

template <class Iterable>
void print_array(Iterable *arr, int size)
{
    cout << "The elements in the array are:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int size = 10;
    int arr[size];
    double arrd[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }
    print_array(arr, size);
    print_array(arrd, size);
    conver(arr, arrd, size);
    print_array(arr, size);
    print_array(arrd, size);
}