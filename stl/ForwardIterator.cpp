#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

template <class Forward>
void square(Forward first, Forward last)
{
    for (; first != last; first++)
    {
        *first = (*first) * (*first);
    }
}

int main()
{
    srand(time(0));
    vector<int> w;
    for (int i = 0; i < 10; i++)
    {
        w.push_back(rand() % 100);
        cout << w[i] << "\t";
    }
    cout << endl;
    square(w.begin(), w.end());
    for (auto i : w)
    {
        cout << i << "\t";
    }
    cout << endl;
}