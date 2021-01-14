#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    node(int x, int y) : val(x), weight(y) {}
    int val, weight;
};

int main()
{
    node x(2, 4);
    vector<node> arrv[4];
    for (int i = 0; i < 4; i++)
    {
        node x(i, i * i);
        node y(i, i * i * i);
        arrv[i].push_back(x);
        arrv[i].push_back(y);
    }
    for (int i = 0; i < 4; i++)
    {
        for (auto x : arrv[i])
        {
            cout << "->" << x.val << "," << x.weight;
        }
        cout << "\n";
    }
    cout << x.val << x.weight;
}
