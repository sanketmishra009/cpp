#include <iostream>
#include <vector>
using namespace std;

int n = 4;
vector<bool> choosen(n + 1);
vector<int> permutation;

void search()
{
    if (permutation.size() == n)
    {
        for (auto i : permutation)
            cout << i << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (choosen[i] == true)
                continue;
            choosen[i] = true;
            permutation.push_back(i);
            search();
            choosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        permutation.push_back(i);
    }
    do
    {
        for (auto i : permutation)
        {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(permutation.begin(), permutation.end()));
}
