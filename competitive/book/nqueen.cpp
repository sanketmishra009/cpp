#include <iostream>
#include <vector>
using namespace std;
#define N 8
// vector<int> coll(n), diag1(n), diag2(n), queen(n);
int coll[N], diag1[2 * N - 1], diag2[2 * N - 1];
int countt = 0;
vector<int> arrange;
void search(int y)
{
    // diag2[0] = 0;
    // cout << "inside search "
    //      << "y = " << y << endl;
    if (y == N)
    {
        countt++;
        cout << "solution #" << countt << endl;
        for (int i = 0; i < N; i++)
        {
            cout << i + 1 << "  ";
        }
        cout << endl;

        for (auto i : arrange)
        {
            for (int j = 0; j < i; j++)
            {
                cout << "   ";
            }
            cout << "1" << endl;
        }
        cout << endl;
        return;
    }
    else
    {
        for (int x = 0; x < N; x++)
        {
            // cout << "x: " << x << " ";
            if (coll[x] || diag1[x + y] || diag2[(x - y) + N - 1])
            {
                // cout << "continued ";
                continue;
            }
            else
            {
                arrange.push_back(x);
                coll[x] = 1;
                diag1[x + y] = 1;
                diag2[(x - y) + N - 1] = 1;
                // cout << "printing matrices" << endl;
                // for (int i = 0; i < N; i++)
                // {
                //     cout << coll[i] << endl;
                // }
                // cout << endl;
                // for (int i = 0; i < 2 * N - 1; i++)
                // {
                //     cout << diag1[i] << " " << diag2[i] << endl;
                // }
                // queen.push_back(x);
                // cout << endl;
                search(y + 1);
                // cout << endl
                //  << "inside search "
                //  << "y = " << y << endl;
                // queen.pop_back();
                arrange.pop_back();
                coll[x] = 0;
                diag1[x + y] = 0;
                diag2[(x - y) + N - 1] = 0;
            }
        }
    }
}

int main()
{
    search(0);
    cout << countt << endl;
}